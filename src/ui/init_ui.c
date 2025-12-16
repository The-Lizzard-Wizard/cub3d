/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:01:29 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/16 14:30:25 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_ui_img(t_data *data)
{
	if (!data->ui.pl_img)
		return (EXIT_FAILURE);
	if (!data->ui.wall_img)
		return (EXIT_FAILURE);
	if (!data->ui.floor_img)
		return (EXIT_FAILURE);
	if (!data->ui.mimp_frame)
		return (EXIT_FAILURE);
	if (!data->ui.font)
		return (EXIT_FAILURE);
	if (!data->ui.y_door)
		return (EXIT_FAILURE);
	if (!data->ui.b_door)
		return (EXIT_FAILURE);
	if (!data->ui.g_door)
		return (EXIT_FAILURE);
	if (!data->ui.r_door)
		return (EXIT_FAILURE);
	if (!data->ui.door)
		return (EXIT_FAILURE);
	if (!data->ui.tex_y_key)
		return (EXIT_FAILURE);
	if (!data->ui.tex_g_key)
		return (EXIT_FAILURE);
	if (!data->ui.tex_b_key)
		return (EXIT_FAILURE);
	if (!data->ui.tex_r_key)
		return (EXIT_FAILURE);
	if (!data->ui.magic_rod_0)
		return (EXIT_FAILURE);
	if (!data->ui.magic_rod_1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_ui(t_data *data)
{
	data->ui.pl_img = new_xpm_img(data, "textures/player.xpm");
	data->ui.wall_img = new_xpm_img(data, "textures/minimap_wall.xpm");
	data->ui.floor_img = new_xpm_img(data, "textures/minimap_floor.xpm");
	data->ui.y_door = new_xpm_img(data, "textures/minimap_yd.xpm");
	data->ui.b_door = new_xpm_img(data, "textures/minimap_bd.xpm");
	data->ui.g_door = new_xpm_img(data, "textures/minimap_gd.xpm");
	data->ui.r_door = new_xpm_img(data, "textures/minimap_rd.xpm");
	data->ui.door = new_xpm_img(data, "textures/minimap_door.xpm");
	data->ui.door_open = new_xpm_img(data, "textures/door_open.xpm");
	data->ui.mimp_frame = new_xpm_img(data, "textures/minimap_frame.xpm");
	data->ui.font = new_xpm_img(data, "textures/font.xpm");
	data->ui.thing = new_xpm_img(data, "textures/thing.xpm");
	data->ui.tex_y_key = new_xpm_img(data, "textures/ui_yellow_key.xpm");
	data->ui.tex_b_key = new_xpm_img(data, "textures/ui_blue_key.xpm");
	data->ui.tex_g_key = new_xpm_img(data, "textures/ui_green_key.xpm");
	data->ui.tex_r_key = new_xpm_img(data, "textures/ui_red_key.xpm");
	data->ui.magic_rod_0 = new_xpm_img(data, "textures/magic_rod_0.xpm");
	data->ui.magic_rod_1 = new_xpm_img(data, "textures/magic_rod_1.xpm");
	if (check_ui_img(data) == EXIT_FAILURE)
	{
		print_error(ER_INIT_UI_IMG);
		return (EXIT_FAILURE);
	}
	if (init_mini_map(data) == EXIT_FAILURE)
	{
		print_error(ER_INIT_UI_MIMP);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
