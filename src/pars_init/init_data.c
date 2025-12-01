/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:00:19 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/01 11:04:00 by gchauvet         ###   ########.fr       */
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
	return (EXIT_SUCCESS);
}

int	load_textures(t_data *data)
{
	data->textures.tex_y_key = new_xpm_img(data, "textures/yellow_key.xpm");
	data->textures.tex_b_key = new_xpm_img(data, "textures/blue_key.xpm");
	data->textures.tex_g_key = new_xpm_img(data, "textures/green_key.xpm");
	data->textures.tex_r_key = new_xpm_img(data, "textures/red_key.xpm");
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
	data->game_state.toggle_collide = 1;
	data->game_state.toggle_minimap = 1;
	data->game_state.camera_ctrl_type = 1;
	data->player.score = 0;
	data->player.red_key = 0;
	data->player.blue_key = 0;
	data->player.green_key = 0;
	data->player.yellow_key = 0;
	load_textures(data);
	return (EXIT_SUCCESS);
}
