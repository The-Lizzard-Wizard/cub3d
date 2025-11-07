/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:58:38 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/07 20:22:32 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../../inc/cub3d.h"

int update_minimap(t_data *data)
{
	size_t	y;
	size_t	x;
	t_modify	mod;

	init_modify(&mod);
	mod.x = 0;
	mod.y = 0;
	y = 0;
	x = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			mod.x = (x * data->ui.wall_img->size_x);
			if (data->map.grid[y][x] == '1')
				draw_img_on_img(data->ui.minimap_img, data->ui.wall_img, mod);
			x++;
		}
		y++;
		mod.y = (y * data->ui.wall_img->size_y);
	}
	return (EXIT_SUCCESS);
}

int draw_minimap_player(t_data *data)
{
	t_modify	mod;

	init_modify(&mod);
	mod.sc_x = 2;
	mod.sc_y = 2;
	draw_img_on_img(data->ui.minimap_img, data->ui.player_img, mod);
	return (EXIT_SUCCESS);
}

int	init_mini_map(t_data *data)
{
	data->map.width = get_long_line_in_array(data->map.grid);
	data->map.height = get_tablen(data->map.grid);
	print_char_array(data->map.grid);
	data->ui.player_img = new_xpm_img(data, "textures/player.xpm");
	data->ui.wall_img = new_xpm_img(data, "textures/minimap_wall.xpm");
	data->ui.minimap_frame = new_xpm_img(data, "textures/minimap_frame.xpm");
	if (!data->ui.wall_img)
		return (EXIT_FAILURE);
	data->ui.minimap_img = new_img(data,
		(data->map.width + 1) * data->ui.wall_img->size_x,
		(data->map.height + 1) * data->ui.wall_img->size_y);
	if (!data->ui.minimap_img)
		return (EXIT_FAILURE);
	update_minimap(data);
	//draw_minimap_player(data);
	return (EXIT_SUCCESS);
}

void	draw_minimap(t_data *data)
{
	t_modify mod;

	init_modify(&mod);
	mod.sc_x = 4;
	mod.sc_y = 4;
	mod.quad_sx = data->ui.minimap_frame->size_x / mod.sc_x * 2;
	mod.quad_sy = data->ui.minimap_frame->size_y / mod.sc_y * 2;
	int playdecx = (extract_decimal(data->player.pos.x) / 12);
	int playdecy = (extract_decimal(data->player.pos.y) / 12);
	mod.quad_x = playdecx + ((int)data->player.pos.x * data->ui.wall_img->size_x) - ((data->ui.minimap_frame->size_x) / mod.sc_x);
	mod.quad_y = playdecy + ((int)data->player.pos.y * data->ui.wall_img->size_y) - ((data->ui.minimap_frame->size_y) / mod.sc_y);
	printf("x %d y %d\n", playdecx, playdecy);
	draw_img_on_img(data->screen_img, data->ui.minimap_img, mod);
	init_modify(&mod);
	mod.sc_x = 2;
	mod.sc_y = 2;
	draw_img_on_img(data->screen_img, data->ui.minimap_frame, mod);
	mod.x = ((data->ui.minimap_frame->size_x / 2) - data->ui.player_img->size_x / 2) * mod.sc_x;
	mod.y = ((data->ui.minimap_frame->size_y / 2) - data->ui.player_img->size_y / 2) * mod.sc_y;
	draw_img_on_img(data->screen_img, data->ui.player_img, mod);
}
