/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:00:19 by gchauvet          #+#    #+#             */
/*   Updated: 2026/02/10 13:03:50 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_toggle_bonus(t_data *data)
{
	if (BONUS)
	{
		data->game_state.toggle_collide = 1;
		data->game_state.toggle_minimap = 1;
		data->game_state.camera_ctrl_type = 0;
	}
	else
	{
		data->game_state.toggle_collide = 0;
		data->game_state.toggle_minimap = 0;
		data->game_state.camera_ctrl_type = 1;
	}
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
	init_toggle_bonus(data);
	data->player.banana = 0;
	data->player.kiwi = 0;
	data->player.red_key = 0;
	data->player.blue_key = 0;
	data->player.green_key = 0;
	data->player.yellow_key = 0;
	data->thing_list = NULL;
	data->things_to_del = NULL;
	data->sp_distance = NULL;
	data->sp_order = NULL;
	ft_bzero(&data->textures, sizeof(t_textures));
	ft_bzero(&data->ui, sizeof(t_ui));
	ft_bzero(&data->map, sizeof(t_map));
	return (EXIT_SUCCESS);
}
