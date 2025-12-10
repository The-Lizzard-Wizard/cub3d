/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:55:25 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/08 16:22:50 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/define.h"
#include <stdio.h>

int	get_nb_things(t_thing *list)
{
	t_thing	*curr_thing;
	int	nb;

	nb = 1;
	if (list == NULL)
		return (0);
	curr_thing = list;
	while (curr_thing->next != NULL)
	{
		curr_thing = curr_thing->next;
		nb++;
	}
	return (nb);
}
int	update_sprite_info(t_data *data)
{
	data->nb_thing = get_nb_things(data->thing_list);
	if (data->sprite_distance)
		free(data->sprite_distance);
	if (data->sprite_order)
		free(data->sprite_order);
	data->sprite_distance = ft_calloc(data->nb_thing, sizeof(double));
	if (!data->sprite_distance)
		return (EXIT_FAILURE);
	data->sprite_order = ft_calloc(data->nb_thing, sizeof(int));
	if (!data->sprite_order)
		return (free_one_and_exit(data->sprite_distance, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

t_thing	*get_thing_by_id(t_thing *list, int id)
{
	t_thing	*curr_thing;
	int		i;

	i = 0;
	if (list == NULL)
		return (NULL);
	curr_thing = list;
	while (curr_thing->next != NULL && i < id)
	{
		if (curr_thing->next == NULL)
			return (NULL);
		curr_thing = curr_thing->next;
		i++;
	}
	return (curr_thing);
}

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
	if (thing_to_del == NULL)
		return ;
	if (!(thing_to_del->next == NULL && thing_to_del->prev == NULL))
	{
		if (thing_to_del->prev == NULL && thing_to_del->next != NULL)
		{
			thing_to_del->next->prev = NULL;
			data->thing_list = thing_to_del->next;
		}
		else if (thing_to_del->next == NULL && thing_to_del->prev != NULL)
			thing_to_del->prev->next = NULL;
		else
		{
			thing_to_del->next->prev = thing_to_del->prev;
			thing_to_del->prev->next = thing_to_del->next;
		}
	}
	free(thing_to_del);
	update_minimap(data);
	update_sprite_info(data);
	ft_printf("%d\n", data->nb_thing);
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
