/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:00:19 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/19 15:42:56 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
	return (EXIT_SUCCESS);
}