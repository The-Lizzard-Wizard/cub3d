/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:11:29 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/28 16:25:04 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int draw_hud(t_data *data)
{
	t_modify	mod;

	init_modify(&mod);
	mod.sc_x = 2;
	mod.sc_y = 2;
	mod.x = 0;
	mod.y = WIN_H - 32;
	if (data->player.yellow_key == 1)
		draw_img_on_img(data->screen_img, data->textures.tex_y_key, mod);
	mod.x += 32;
	if (data->player.blue_key == 1)
		draw_img_on_img(data->screen_img, data->textures.tex_b_key, mod);
	mod.x += 32;
	if (data->player.green_key == 1)
		draw_img_on_img(data->screen_img, data->textures.tex_g_key, mod);
	mod.x += 32;
	if (data->player.red_key == 1)
		draw_img_on_img(data->screen_img, data->textures.tex_r_key, mod);
	return (EXIT_SUCCESS);
}