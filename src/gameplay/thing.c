/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:55:25 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/15 16:15:21 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/define.h"
#include <stdio.h>
#include <math.h>

t_thing	*add_thing(t_data *data, t_cub_img **texture, t_vec2 pos, int type)
{
	t_thing	*new_thing;
	t_thing	*last_thing;

	new_thing = ft_calloc(sizeof(t_thing), 1);
	if (!new_thing)
	{
		mlx_loop_end(data->mlx_ptr);
		return (NULL);
	}
	new_thing->texture = texture;
	new_thing->pos = pos;
	new_thing->type = type;
	if (data->thing_list == NULL)
	{
		data->thing_list = new_thing;
		update_sp_info(data);
		return (new_thing);
	}
	else
		last_thing = get_last_thing(data->thing_list);
	last_thing->next = new_thing;
	new_thing->prev = last_thing;
	update_sp_info(data);
	return (new_thing);
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
	else
		data->thing_list = NULL;
	free_ptr(thing_to_del);
	update_sp_info(data);
}

void	take_thing(t_data *data, t_thing *thing)
{
	if (thing->type == THING_Y_KEY)
		take_y_key(data, thing);
	else if (thing->type == THING_B_KEY)
		take_b_key(data, thing);
	else if (thing->type == THING_G_KEY)
		take_g_key(data, thing);
	else if (thing->type == THING_R_KEY)
		take_r_key(data, thing);
	else if (thing->type == THING_MAGIC_ROD)
		take_magic_rod(data, thing);
	else if (thing->type == THING_BANANA)
		take_banana(data, thing);
	else if (thing->type == THING_CHICKEN)
		take_chicken(data, thing);
}

int	check_thing(t_data *data, t_vec2 pos, t_thing *thing)
{
	t_vec2	old_pos;

	old_pos = thing->pos;
	thing->pos.x += thing->vel.x;
	thing->pos.y += thing->vel.y;
	if (thing->type == THING_BULLET)
		bullet_life(data, thing);
	if (pos.x >= thing->pos.x - THING_BOX_W / 2
		&& pos.x <= thing->pos.x + THING_BOX_W / 2
		&& pos.y >= thing->pos.y - THING_BOX_H / 2
		&& pos.y <= thing->pos.y + THING_BOX_H / 2)
		take_thing(data, thing);
	return (EXIT_SUCCESS);
}

int	update_thing(t_data *data)
{
	t_thing	*curr_thing;
	t_thing	*next_thing;

	if (!data->thing_list)
		return (EXIT_SUCCESS);
	next_thing = NULL;
	curr_thing = data->thing_list;
	while (curr_thing != NULL)
	{
		if (check_thing(data, data->player.pos, curr_thing) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (curr_thing->del == 1)
		{
			next_thing = curr_thing->next;
			del_thing(data, curr_thing);
			curr_thing = next_thing;
		}
		else
			curr_thing = curr_thing->next;
	}
	return (EXIT_SUCCESS);
}
