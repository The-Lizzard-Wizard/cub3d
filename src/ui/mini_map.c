/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:58:38 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/12 15:03:02 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../../inc/cub_math.h"
#include "../../inc/cub3d.h"

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

int	init_mini_map(t_data *data)
{
	print_char_array(data->map.grid);
	if (!data->ui.wall_img)
		return (EXIT_FAILURE);
	data->ui.minimap_img = new_img(data,
		(data->map.width + 1) * data->ui.wall_img->size_x,
		(data->map.height + 1) * data->ui.wall_img->size_y);
	if (!data->ui.minimap_img)
		return (EXIT_FAILURE);
	update_minimap(data);
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
	mod.x = 32 * 5;
	put_text_on_img(data->screen_img, data->ui.font, ch_y, mod);
	return (free_too_and_exit(ch_x, ch_y, EXIT_SUCCESS));
}

void	draw_minimap(t_data *data, int map_size)
{
	t_modify mod;
	int pld[2];

	init_modify(&mod);
	mod.sc_x = 4;
	mod.sc_y = 4;
	mod.quad_sx = data->ui.mimp_frame->size_x / mod.sc_x * map_size;
	mod.quad_sy = data->ui.mimp_frame->size_y / mod.sc_y * map_size;
	pld[0] = (extract_decimal(data->player.pos.x) / 12);
	pld[1] = (extract_decimal(data->player.pos.y) / 12);
	mod.quad_x = pld[0] + ((int)data->player.pos.x * data->ui.wall_img->size_x)\
		- (((data->ui.mimp_frame->size_x * map_size) / 2) / mod.sc_x);
	mod.quad_y = pld[1] + ((int)data->player.pos.y * data->ui.wall_img->size_y)\
		- (((data->ui.mimp_frame->size_y * map_size) / 2) / mod.sc_y);
	draw_img_on_img(data->screen_img, data->ui.minimap_img, mod);
	init_modify(&mod);
	mod.sc_x = map_size;
	mod.sc_y = map_size;
	draw_img_on_img(data->screen_img, data->ui.mimp_frame, mod);
	mod.x = ((data->ui.mimp_frame->size_x / 2)\
		- data->ui.pl_img->size_x / 2) * mod.sc_x;
	mod.y = ((data->ui.mimp_frame->size_y / 2)\
		- data->ui.pl_img->size_y / 2) * mod.sc_y;
	draw_img_on_img(data->screen_img, data->ui.pl_img, mod);

	
	mod.x += data->player.view_angle.x * 10;
	mod.y += data->player.view_angle.y * 10;
	draw_img_on_img(data->screen_img, data->ui.pl_img, mod);
	draw_player_pos(data);
}
