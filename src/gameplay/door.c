/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:43:06 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/02 17:05:20 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	door_interact(t_data *data)
{
	t_int_pos2	pos;
	char		tile;

	pos.x = (int)(data->player.pos.x + data->player.view_angle.x);
	pos.y = (int)(data->player.pos.y + data->player.view_angle.y);
	tile = data->map.grid[pos.y][pos.x];
	if (tile == 'Y')
		if (data->player.yellow_key == 1)
			data->map.grid[pos.y][pos.x] = '0';
	if (tile == 'B')
		if (data->player.blue_key == 1)
			data->map.grid[pos.y][pos.x] = '0';
	if (tile == 'G')
		if (data->player.green_key == 1)
			data->map.grid[pos.y][pos.x] = '0';
	if (tile == 'R')
		if (data->player.red_key == 1)
			data->map.grid[pos.y][pos.x] = '0';
	if (tile == 'D')
		data->map.grid[pos.y][pos.x] = 'd';
	if (tile == 'd')
		data->map.grid[pos.y][pos.x] = 'D';
	update_minimap(data);
}
