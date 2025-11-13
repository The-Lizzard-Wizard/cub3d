/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:49:16 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/13 16:35:18 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/cub_math.h"
#include "../../minilibx-linux/mlx.h"
#include <X11/X.h>
#include "../../inc/key.h"

int	keypresse(int key, t_data *data)
{
	if (key == K_ESC)
		free_and_exit(data);
	if (key == K_A)
	{
		data->player.view_angle = vect_rot(data->player.view_angle, (double)deg_to_rad(-1));
		data->player.camera_plane = vect_rot(data->player.camera_plane, (double)deg_to_rad(-1));
	}
	if (key == K_D)
	{
		data->player.view_angle = vect_rot(data->player.view_angle, (double)deg_to_rad(1));
		data->player.camera_plane = vect_rot(data->player.camera_plane, (double)deg_to_rad(1));
	}
	if (key == K_W)
	{
		data->player.pos.x += data->player.view_angle.x / 10;
		data->player.pos.y += data->player.view_angle.y / 10;
	}
	return (EXIT_SUCCESS);
}

void	event_listener(t_data *data)
{
	mlx_hook(data->mlx_win, 2, (1L << 0), keypresse, data);
	mlx_hook(data->mlx_win, DestroyNotify,
	KeyPressMask, free_and_exit, &data);
}