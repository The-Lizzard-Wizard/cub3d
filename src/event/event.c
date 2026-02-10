/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:49:16 by gchauvet          #+#    #+#             */
/*   Updated: 2026/02/10 11:46:09 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/cub_math.h"
#include "../../minilibx-linux/mlx.h"
#include <X11/X.h>
#include "../../inc/key.h"

void	switch_int(int *toggle)
{
	if (*toggle == 1)
		*toggle = 0;
	else
		*toggle = 1;
}

int	keypress(int key, t_data *data)
{
	if (key == K_ESC)
		mlx_loop_end(data->mlx_ptr);
	if (BONUS)
	{
		if (key == K_TAB)
			switch_int(&data->game_state.toggle_minimap);
		if (key == K_C)
			switch_int(&data->game_state.toggle_collide);
		if (key == K_M)
			switch_int(&data->game_state.camera_ctrl_type);
		if (is_out_of_bounds(data) == 0)
			if (key == K_SPACE)
				door_interact(data);
		if (key == K_CTRL)
			if (is_out_of_bounds(data) == 0)
				if (data->player.magic_rod == 1)
					shoot(data);
	}
	move_press(data, key);
	return (EXIT_SUCCESS);
}

int	keyrelease(int key, t_data *data)
{
	move_release(data, key);
	return (1);
}

int	mouse_press(int key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (key == LMB)
		if (is_out_of_bounds(data) == 0)
			if (data->player.magic_rod == 1)
				shoot(data);
	return (1);
}

void	event_listener(t_data *data)
{
	mlx_hook(data->mlx_win, 2, (1L << 0), keypress, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, keyrelease, data);
	mlx_hook(data->mlx_win, DestroyNotify, KeyPressMask,
		mlx_loop_end, data->mlx_ptr);
	mlx_mouse_hook(data->mlx_win, mouse_press, data);
}
