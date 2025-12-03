/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:55:25 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/03 16:51:26 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/define.h"
#include <stdio.h>

t_thing	*get_last_thing(t_thing *thing_list)
{
	t_thing	*curr_thing;

	if (thing_list == NULL)
		return (NULL);
	curr_thing = thing_list;
	while (curr_thing->next != NULL)
		curr_thing = curr_thing->next;
	return (curr_thing);
}

int	add_thing(t_data *data, t_cub_img *texture, t_vec2 pos, int type)
{
	t_thing	*new_thing;
	t_thing	*last_thing;

	new_thing = malloc(sizeof(t_thing));
	if (!new_thing)
		return (EXIT_FAILURE);
	new_thing->texture = texture;
	new_thing->next = NULL;
	new_thing->prev = NULL;
	new_thing->pos.x = pos.x;
	new_thing->pos.y = pos.y;
	new_thing->type = type;
	if (data->thing_list == NULL)
	{
		data->thing_list = new_thing;
		return (EXIT_SUCCESS);
	}
	else
		last_thing = get_last_thing(data->thing_list);
	last_thing->next = new_thing;
	new_thing->prev = last_thing;
	return (EXIT_SUCCESS);
}

void	del_thing(t_data *data, t_thing *thing_to_del)
{
	t_thing	*prev;
	t_thing	*next;

	next = NULL;
	prev = NULL;
	if (thing_to_del->prev)
		prev = thing_to_del->prev;
	if (thing_to_del->next)
		next = thing_to_del->next;
	if (prev && next)
	{
		prev->next = next;
		next->prev = prev;
	}
	free(thing_to_del);
	update_minimap(data);
}

int	check_collide_thing(t_data *data, t_vec2 pos, t_thing *thing)
{
	(void)data;
	if (pos.x >= thing->pos.x - THING_BOX_W / 2
		&& pos.x <= thing->pos.x + THING_BOX_W / 2
		&& pos.y >= thing->pos.y - THING_BOX_H / 2
		&& pos.y <= thing->pos.y + THING_BOX_H / 2)
	{
		if (thing->type == THING_Y_KEY)
			take_y_key(data, thing);
		else if (thing->type == THING_B_KEY)
			take_b_key(data, thing);
		else if (thing->type == THING_G_KEY)
			take_g_key(data, thing);
		else if (thing->type == THING_R_KEY)
			take_r_key(data, thing);
	}
	return (EXIT_SUCCESS);
}

int	collide_with_thing(t_data *data)
{
	t_thing	*curr_thing;

	if (!data->thing_list)
		return (EXIT_SUCCESS);
	curr_thing = data->thing_list;
	if (check_collide_thing(data, data->player.pos, curr_thing) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (curr_thing->next != NULL)
	{
		if (check_collide_thing(data, data->player.pos, curr_thing) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		curr_thing = curr_thing->next;
	}
	if (check_collide_thing(data, data->player.pos, curr_thing) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
