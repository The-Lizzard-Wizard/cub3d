/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:09:54 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/15 16:22:40 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/key.h"
#include "../../inc/cub_math.h"

void	move_press(t_data *data, int key)
{
	if (key == K_W)
		data->player.control.move_w = 1;
	if (key == K_S)
		data->player.control.move_s = 1;
	if (key == K_A)
		data->player.control.move_a = 1;
	if (key == K_D)
		data->player.control.move_d = 1;
	if (key == K_LEFT)
		data->player.control.move_left = 1;
	if (key == K_RIGHT)
		data->player.control.move_right = 1;
}

void	move_release(t_data *data, int key)
{
	if (key == K_W)
		data->player.control.move_w = 0;
	if (key == K_S)
		data->player.control.move_s = 0;
	if (key == K_A)
		data->player.control.move_a = 0;
	if (key == K_D)
		data->player.control.move_d = 0;
	if (key == K_LEFT)
		data->player.control.move_left = 0;
	if (key == K_RIGHT)
		data->player.control.move_right = 0;
}

int	collide(t_data *data, t_vec2 pos, int xy)
{
	int coll;
	char	tile;

	coll = 0;
	if (xy == 1)
	{
		tile = data->map.grid[(int)data->player.pos.y][(int)pos.x];
		if (tile == '1' || tile == 'Y' || tile == 'B' || tile == 'G' || tile == 'R' || tile == 'D')
			coll = 1;
	}
	else if (xy == 2)
	{
		tile = data->map.grid[(int)pos.y][(int)data->player.pos.x];
		if (tile == '1' || tile == 'Y' || tile == 'B' || tile == 'G' || tile == 'R' || tile == 'D')
			coll = 1;
	}
	return (coll);
}

void	keyboard_camera(t_data *data)
{
	if (data->player.control.move_right == 1)
	{
		data->player.view_angle = vect_rot(\
			data->player.view_angle, (double)deg_to_rad(1));
		data->player.camera_plane = vect_rot(\
			data->player.camera_plane, (double)deg_to_rad(1));
	}
	if (data->player.control.move_left == 1)
	{
		data->player.view_angle = vect_rot(\
			data->player.view_angle, (double)deg_to_rad(-1));
		data->player.camera_plane = vect_rot(\
			data->player.camera_plane, (double)deg_to_rad(-1));
	}
}

void	move(t_data *data, t_vec2 *next_move)
{
	if (data->player.control.move_w == 1)
	{
		next_move->x += data->player.view_angle.x / 30;
		next_move->y += data->player.view_angle.y / 30;
	}
	if (data->player.control.move_s == 1)
	{
		next_move->x -= data->player.view_angle.x / 30;
		next_move->y -= data->player.view_angle.y / 30;
	}
	keyboard_camera(data);
	if (data->player.control.move_d == 1)
	{
		next_move->x += data->player.camera_plane.x / 30;
		next_move->y += data->player.camera_plane.y / 30;
	}
	if (data->player.control.move_a == 1)
	{
		next_move->x -= data->player.camera_plane.x / 30;
		next_move->y -= data->player.camera_plane.y / 30;
	}
	if (data->game_state.camera_ctrl_type == 0)
		mouse_camera(data);
}
