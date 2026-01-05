/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprites_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:58:51 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/05 13:07:12 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	swap_order(t_data *data, int i, int j)
{
	int		tmp;
	double	dtmp;

	tmp = data->sp_order[i];
	dtmp = data->sp_distance[i];
	data->sp_order[i] = data->sp_order[j];
	data->sp_order[j] = tmp;
	data->sp_distance[i] = data->sp_distance[j];
	data->sp_distance[j] = dtmp;
}

void	sort_loop(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < data->nb_thing)
	{
		j = i + 1;
		while (j < data->nb_thing)
		{
			if (data->sp_distance[j] > data->sp_distance[i])
				swap_order(data, j, i);
			j++;
		}
		i++;
	}
}

void	sort_sp(t_data *data, t_raycast raycast)
{
	int		i;
	t_thing	*thing_curr;
	t_vec2	dxy;

	i = 0;
	while (i < data->nb_thing)
	{
		thing_curr = get_thing_by_id(data->thing_list, i);
		data->sp_order[i] = i;
		dxy.x = raycast.pos.x - thing_curr->pos.x;
		dxy.y = raycast.pos.y - thing_curr->pos.y;
		data->sp_distance[i] = dxy.x * dxy.x + dxy.y * dxy.y;
		i++;
	}
	sort_loop(data);
}
