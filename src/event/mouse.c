/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:14:18 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/17 15:20:09 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"
#include "../../inc/cub3d.h"
#include "../../inc/cub_math.h"

void	move_left(t_data *data, int pos[2], int *old_mouse_x)
{
	int motion;

	motion = (*old_mouse_x - pos[0]);
	data->player.view_angle = vect_rot(\
		data->player.view_angle, ((double)deg_to_rad(-1) * motion) / 20);
	data->player.camera_plane = vect_rot(\
		data->player.camera_plane, ((double)deg_to_rad(-1) * motion) / 20);
	if (pos[0] <= 0)
	{
		mlx_mouse_move(data->mlx_ptr, data->mlx_win, WIN_W / 2, WIN_H / 2);
		*old_mouse_x = (WIN_W / 2) + 1;
	}
	else
		*old_mouse_x = pos[0];
}

void	move_right(t_data *data, int pos[2], int *old_mouse_x)
{
	int motion;

	motion = pos[0] - *old_mouse_x;
	data->player.view_angle = vect_rot(\
		data->player.view_angle, ((double)deg_to_rad(1) * motion) / 20);
	data->player.camera_plane = vect_rot(\
		data->player.camera_plane, ((double)deg_to_rad(1) * motion) / 20);
	if (pos[0] >= WIN_W)
	{
		mlx_mouse_move(data->mlx_ptr, data->mlx_win, WIN_W / 2, WIN_H / 2);
		*old_mouse_x = (WIN_W / 2) - 1;
	}
	else
		*old_mouse_x = pos[0];
}

void	mouse_camera(t_data *data)
{
	static int	old_mouse_x;
	int pos[2];

	mlx_mouse_get_pos(data->mlx_ptr, data->mlx_win, &pos[0], &pos[1]);
	if (pos[0] > old_mouse_x)
		move_right(data, pos, &old_mouse_x);
	if (pos[0] < old_mouse_x)
		move_left(data, pos, &old_mouse_x);
}
