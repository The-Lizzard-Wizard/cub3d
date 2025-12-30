/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:00:19 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/30 13:47:20 by gchauvet         ###   ########.fr       */
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
	if (!data->textures.tex_magic_rod)
		return (EXIT_FAILURE);
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
	data->textures.tex_magic_rod = new_xpm_img(data, "textures/tex_magic_rod.xpm");
	data->textures.tex_chicken = new_xpm_img(data, "textures/chicken.xpm");
	
	data->textures.anime_tex_banana = new_anime(data, "textures/banana_frame_0.xpm;\
textures/banana_frame_1.xpm;\
textures/banana_frame_2.xpm;\
textures/banana_frame_3.xpm;\
textures/banana_frame_4.xpm;\
textures/banana_frame_5.xpm;\
textures/banana_frame_6.xpm;\
textures/banana_frame_7.xpm;", 5);
	data->textures.anike_tex_kiwi = new_anime(data,"textures/rotation/kiwi_spin.xpm;\
textures/rotation/kiwi_spin1.xpm;\
textures/rotation/kiwi_spin2.xpm;\
textures/rotation/kiwi_spin3.xpm;\
textures/rotation/kiwi_spin4.xpm;\
textures/rotation/kiwi_spin5.xpm;\
textures/rotation/kiwi_spin6.xpm;\
textures/rotation/kiwi_spin7.xpm;\
textures/rotation/kiwi_spin8.xpm;\
textures/rotation/kiwi_spin9.xpm;\
textures/rotation/kiwi_spin10.xpm;\
textures/rotation/kiwi_spin11.xpm;\
textures/rotation/kiwi_spin12.xpm;\
textures/rotation/kiwi_spin13.xpm;\
textures/rotation/kiwi_spin14.xpm;\
textures/rotation/kiwi_spin15.xpm;\
textures/rotation/kiwi_spin16.xpm;\
textures/rotation/kiwi_spin17.xpm;\
textures/rotation/kiwi_spin18.xpm;\
textures/rotation/kiwi_spin19.xpm;\
textures/rotation/kiwi_spin20.xpm;\
textures/rotation/kiwi_spin21.xpm;\
textures/rotation/kiwi_spin22.xpm;\
textures/rotation/kiwi_spin23.xpm;\
textures/rotation/kiwi_spin24.xpm;\
textures/rotation/kiwi_spin25.xpm;\
textures/rotation/kiwi_spin26.xpm;\
textures/rotation/kiwi_spin27.xpm;\
textures/rotation/kiwi_spin28.xpm;\
textures/rotation/kiwi_spin29.xpm;\
textures/rotation/kiwi_spin30.xpm;\
textures/rotation/kiwi_spin31.xpm;\
textures/rotation/kiwi_spin32.xpm;\
textures/rotation/kiwi_spin33.xpm;\
textures/rotation/kiwi_spin34.xpm;\
textures/rotation/kiwi_spin35.xpm;", 1);
	data->textures.anime_tex_magic_shoot = new_anime(data, "textures/magic_shoot.xpm;\
textures/magic_shoot_1.xpm", 5);
	if (check_tex(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_data(t_data *data)
{
	data->player.control.move_w = 0;
	data->player.control.move_s = 0;
	data->player.control.move_d = 0;
	data->player.control.move_a = 0;
	data->player.control.move_left = 0;
	data->player.control.move_right = 0;
	data->player.magic_rod = 0;
	data->game_state.toggle_collide = 1;
	data->game_state.toggle_minimap = 1;
	data->game_state.camera_ctrl_type = 1;
	data->player.banana = 0;
	data->player.kiwi = 0;
	data->player.red_key = 0;
	data->player.blue_key = 0;
	data->player.green_key = 0;
	data->player.yellow_key = 0;
	data->thing_list = NULL;
	data->things_to_del = NULL;
	data->sprite_distance = NULL;
	data->sprite_order = NULL;
	return (EXIT_SUCCESS);
}
