/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:06:28 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/08 11:13:17 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../../inc/cub_math.h"
#include "../../inc/cub3d.h"
#include "../../inc/define.h"

static void	draw_tile_type(t_data *data, size_t x, size_t y, t_modify mod)
{
	if (data->map.grid[y][x] == '1')
		draw_img_on_img(data->ui.minimap_img, data->ui.wall_img, mod);
	else if (data->map.grid[y][x] == '0')
		draw_img_on_img(data->ui.minimap_img, data->ui.floor_img, mod);
	else if (data->map.grid[y][x] == 'Y')
		draw_img_on_img(data->ui.minimap_img, data->ui.y_door, mod);
	else if (data->map.grid[y][x] == 'B')
		draw_img_on_img(data->ui.minimap_img, data->ui.b_door, mod);
	else if (data->map.grid[y][x] == 'G')
		draw_img_on_img(data->ui.minimap_img, data->ui.g_door, mod);
	else if (data->map.grid[y][x] == 'R')
		draw_img_on_img(data->ui.minimap_img, data->ui.r_door, mod);
	else if (data->map.grid[y][x] == 'D')
		draw_img_on_img(data->ui.minimap_img, data->ui.door, mod);
	else if (data->map.grid[y][x] == 'd')
		draw_img_on_img(data->ui.minimap_img, data->ui.door_open, mod);
	else if (data->map.grid[y][x] == ' ')
	{
		mod.sc_x = 8;
		mod.sc_y = 8;
		draw_recangle(data->ui.minimap_img, 0, FILL, mod);
		mod.sc_x = 1;
		mod.sc_y = 1;
	}
}

void	draw_thing_on_minimap(t_data *data, t_modify mod)
{
	t_thing	*curr_thing;

	curr_thing = NULL;
	if (!data->thing_list)
		return ;
	curr_thing = data->thing_list;
	init_modify(&mod);
	mod.sc_x = 2;
	mod.sc_y = 2;
	while (curr_thing->next != NULL)
	{
		mod.x = ((curr_thing->pos.x) * 8) - 1;
		mod.y = ((curr_thing->pos.y) * 8) - 1;
		draw_recangle(data->ui.minimap_img, rgba_to_int_color(255, 0, 255, 0), FILL, mod);
		curr_thing = curr_thing->next;
	}
	mod.x = ((curr_thing->pos.x) * 8) - 1;
	mod.y = ((curr_thing->pos.y) * 8) - 1;
	draw_recangle(data->ui.minimap_img, rgba_to_int_color(255, 0, 255, 0), FILL, mod);
}

int update_minimap(t_data *data)
{
	size_t	y;
	size_t	x;
	t_modify	mod;

	init_modify(&mod);
	y = 0;
	x = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			mod.x = (x * data->ui.wall_img->size_x);
			draw_tile_type(data, x, y, mod);
			x++;
		}
		y++;
		mod.y = (y * data->ui.wall_img->size_y);
	}
	draw_thing_on_minimap(data, mod);
	return (EXIT_SUCCESS);
}
