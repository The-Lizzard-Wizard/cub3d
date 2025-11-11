/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:58:38 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/11 13:41:58 by gchauvet         ###   ########.fr       */
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
			else if (data->map.grid[y][x] == '0')
				draw_img_on_img(data->ui.minimap_img, data->ui.floor_img, mod);
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
	data->ui.floor_img = new_xpm_img(data, "textures/minimap_floor.xpm");
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

int	draw_player_pos(t_data *data)
{
	char	*ch_x;
	char	*ch_y;
	t_modify	mod;

	init_modify(&mod);
	mod.y = 128 * 2;
	mod.sc_x = 2;
	mod.sc_y = 2;
	ch_x = ft_itoa(data->player.pos.x);
	if (!ch_x)
		return (EXIT_FAILURE);
	ch_y = ft_itoa(data->player.pos.y);
	if (!ch_y)
		return (free_one_and_exit(ch_x, EXIT_FAILURE));
	put_text_on_img(data->screen_img, data->ui.font, "(x:  y:  )", mod);
	mod.x = 32 * 2;
	put_text_on_img(data->screen_img, data->ui.font, ch_x, mod);
	mod.x = 32 * 6;
	put_text_on_img(data->screen_img, data->ui.font, ch_y, mod);
	return (free_too_and_exit(ch_x, ch_y, EXIT_SUCCESS));
}

void	draw_minimap(t_data *data, int map_size)
{
	t_modify mod;

	init_modify(&mod);
	mod.sc_x = 4;
	mod.sc_y = 4;
	mod.quad_sx = data->ui.minimap_frame->size_x / mod.sc_x * map_size;
	mod.quad_sy = data->ui.minimap_frame->size_y / mod.sc_y * map_size;
	int playdecx = (extract_decimal(data->player.pos.x) / 12);
	int playdecy = (extract_decimal(data->player.pos.y) / 12);
	mod.quad_x = playdecx + ((int)data->player.pos.x * data->ui.wall_img->size_x) - (((data->ui.minimap_frame->size_x * map_size) / 2) / mod.sc_x);
	mod.quad_y = playdecy + ((int)data->player.pos.y * data->ui.wall_img->size_y) - (((data->ui.minimap_frame->size_y * map_size) / 2) / mod.sc_y);
	draw_img_on_img(data->screen_img, data->ui.minimap_img, mod);
	init_modify(&mod);
	mod.sc_x = map_size;
	mod.sc_y = map_size;
	draw_img_on_img(data->screen_img, data->ui.minimap_frame, mod);
	mod.x = ((data->ui.minimap_frame->size_x / 2) - data->ui.player_img->size_x / 2) * mod.sc_x;
	mod.y = ((data->ui.minimap_frame->size_y / 2) - data->ui.player_img->size_y / 2) * mod.sc_y;
	draw_img_on_img(data->screen_img, data->ui.player_img, mod);
	draw_player_pos(data);
}
