/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:35:14 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/02 17:08:02 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int check_tex(t_data *data)
{
	if (!data->textures.tex_y_key)
		return (EXIT_FAILURE);
	if (!data->textures.tex_b_key)
		return (EXIT_FAILURE);
	if (!data->textures.tex_g_key)
		return (EXIT_FAILURE);
	if (!data->textures.tex_r_key)
		return (EXIT_FAILURE);
	if (!data->textures.tex_r_door)
		return (EXIT_FAILURE);
	if (!data->textures.tex_b_door)
		return (EXIT_FAILURE);
	if (!data->textures.tex_g_door)
		return (EXIT_FAILURE);
	if (!data->textures.tex_y_door)
		return (EXIT_FAILURE);
	if (!data->textures.tex_door)
		return (EXIT_FAILURE);
	if (!data->textures.tex_chicken)
		return (EXIT_FAILURE);
	if (!data->textures.tex_magic)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int check_anime(t_data *data)
{
	if (!data->textures.anime_tex_kiwi)
		return (EXIT_FAILURE);
	if (!data->textures.anime_tex_banana)
		return (EXIT_FAILURE);
	if (!data->textures.anime_tex_magic_shoot)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	load_kiwi_textures(t_data *data)
{
	data->textures.anime_tex_kiwi = new_anime(data,
"textures/kiwi_spin.xpm;textures/kiwi_spin1.xpm;\
textures/kiwi_spin2.xpm;textures/kiwi_spin3.xpm;\
textures/kiwi_spin4.xpm;textures/kiwi_spin5.xpm;\
textures/kiwi_spin6.xpm;textures/kiwi_spin7.xpm;\
textures/kiwi_spin8.xpm;textures/kiwi_spin9.xpm;\
textures/kiwi_spin10.xpm;textures/kiwi_spin11.xpm;\
textures/kiwi_spin12.xpm;textures/kiwi_spin13.xpm;\
textures/kiwi_spin14.xpm;textures/kiwi_spin15.xpm;\
textures/kiwi_spin16.xpm;textures/kiwi_spin17.xpm;\
textures/kiwi_spin18.xpm;textures/kiwi_spin19.xpm;\
textures/kiwi_spin20.xpm;textures/kiwi_spin21.xpm;\
textures/kiwi_spin22.xpm;textures/kiwi_spin23.xpm;\
textures/kiwi_spin24.xpm;textures/kiwi_spin25.xpm;\
textures/kiwi_spin26.xpm;textures/kiwi_spin27.xpm;\
textures/kiwi_spin28.xpm;textures/kiwi_spin29.xpm;\
textures/kiwi_spin30.xpm;textures/kiwi_spin31.xpm;\
textures/kiwi_spin32.xpm;textures/kiwi_spin33.xpm;\
textures/kiwi_spin34.xpm;textures/kiwi_spin35.xpm;", 1);
	return (EXIT_SUCCESS);
}

int	load_anime(t_data *data)
{
	data->textures.anime_tex_banana = new_anime(data,
"textures/banana_frame_0.xpm;\
textures/banana_frame_1.xpm;\
textures/banana_frame_2.xpm;\
textures/banana_frame_3.xpm;\
textures/banana_frame_4.xpm;\
textures/banana_frame_5.xpm;\
textures/banana_frame_6.xpm;\
textures/banana_frame_7.xpm;", 5);
	data->textures.anime_tex_magic_shoot = new_anime(data,
"textures/magic_shoot.xpm;\
textures/magic_shoot_1.xpm", 5);
	load_kiwi_textures(data);
	return (EXIT_SUCCESS);
}

int	load_textures(t_data *data)
{
	data->textures.tex_y_key = new_xpm_img(data, "textures/yellow_key.xpm");
	data->textures.tex_b_key = new_xpm_img(data, "textures/blue_key.xpm");
	data->textures.tex_g_key = new_xpm_img(data, "textures/green_key.xpm");
	data->textures.tex_r_key = new_xpm_img(data, "textures/red_key.xpm");
	data->textures.tex_r_door = new_xpm_img(data, "textures/door_r.xpm");
	data->textures.tex_g_door = new_xpm_img(data, "textures/door_g.xpm");
	data->textures.tex_b_door = new_xpm_img(data, "textures/door_b.xpm");
	data->textures.tex_y_door = new_xpm_img(data, "textures/door_y.xpm");
	data->textures.tex_door = new_xpm_img(data, "textures/door.xpm");
	data->textures.tex_magic = NULL;//new_xpm_img(data, "textures/tex_magic_rod.xpm");
	data->textures.tex_chicken = new_xpm_img(data, "textures/chicken.xpm");
	load_anime(data);
	if (check_tex(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
