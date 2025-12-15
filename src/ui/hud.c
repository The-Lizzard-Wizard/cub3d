/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:11:29 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/12 18:36:38 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int draw_hud(t_data *data)
{
	t_modify	mod;

	init_modify(&mod);
	mod.sc_x = 5;
	mod.sc_y = 5;
	mod.x = 0;
	mod.y = WIN_H - (16 * mod.sc_y);
	if (data->player.yellow_key == 1)
		draw_img_on_img(data->screen_img, data->ui.tex_y_key, mod);
	mod.x += (16 * mod.sc_x);
	if (data->player.blue_key == 1)
		draw_img_on_img(data->screen_img, data->ui.tex_b_key, mod);
	mod.x += (16 * mod.sc_x);
	if (data->player.green_key == 1)
		draw_img_on_img(data->screen_img, data->ui.tex_g_key, mod);
	mod.x += (16 * mod.sc_x);
	if (data->player.red_key == 1)
		draw_img_on_img(data->screen_img, data->ui.tex_r_key, mod);
	return (EXIT_SUCCESS);
}