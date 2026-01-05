/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:11:29 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/05 12:36:13 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_kiwi_state(t_data *data, t_modify mod, char str[16])
{
	mod.y = WIN_H - 300;
	mod.x = 5;
	mod.sc_x = 1;
	mod.sc_y = 1;
	draw_img_on_img(data->screen_img,
		data->textures.anime_tex_kiwi->img_curr, mod);
	itoa_buff(data->player.kiwi, str);
	mod.sc_x = 4;
	mod.sc_y = 4;
	mod.x = 130;
	mod.y += 20;
	put_text_on_img(data->screen_img, data->ui.font, str, mod);
}

int	draw_state(t_data *data)
{
	t_modify	mod;
	char		str[16];

	init_modify(&mod);
	mod.sc_x = 4;
	mod.sc_y = 4;
	mod.y = WIN_H - 200;
	mod.x = -10;
	draw_img_on_img(data->screen_img,
		data->textures.anime_tex_banana->img_curr, mod);
	itoa_buff(data->player.banana, str);
	mod.x = 130;
	mod.y += 20;
	put_text_on_img(data->screen_img, data->ui.font, str, mod);
	draw_kiwi_state(data, mod, str);
	return (EXIT_SUCCESS);
}

int	draw_magic_rod(t_data *data)
{
	t_modify	mod;

	init_modify(&mod);
	mod.sc_x = 5;
	mod.sc_y = 5;
	mod.x = (WIN_W / 2) - ((data->ui.magic_rod_0->size_x * mod.sc_x) / 2);
	mod.y = (WIN_H) - (data->ui.magic_rod_0->size_y * mod.sc_y);
	if (data->player.magic_rod == 1)
		draw_img_on_img(data->screen_img, data->ui.magic_rod_0, mod);
	return (EXIT_SUCCESS);
}

int	draw_hud(t_data *data)
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
	draw_magic_rod(data);
	draw_state(data);
	return (EXIT_SUCCESS);
}
