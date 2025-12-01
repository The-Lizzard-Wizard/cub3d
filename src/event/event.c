/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:49:16 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/01 11:01:09 by gchauvet         ###   ########.fr       */
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

int	keypresse(int key, t_data *data)
{
	if (key == K_ESC)
		free_and_exit(data);
	if (key == K_TAB)
		switch_int(&data->game_state.toggle_minimap);
	if (key == K_C)
		switch_int(&data->game_state.toggle_collide);
	if (key == K_M)
	{
		if (data->game_state.camera_ctrl_type == 0)
			mlx_mouse_show(data->mlx_ptr, data->mlx_win);
		else
			mlx_mouse_hide(data->mlx_ptr, data->mlx_win);
		switch_int(&data->game_state.camera_ctrl_type);
	}
	if (key == K_SPACE)
		door_interact(data);
	move_press(data, key);
	return (EXIT_SUCCESS);
}

int	keyrelease(int key, t_data *data)
{
	move_release(data, key);
	return (1);
}

void	event_listener(t_data *data)
{
	mlx_hook(data->mlx_win, 2, (1L << 0), keypresse, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, keyrelease, data);
	mlx_hook(data->mlx_win, DestroyNotify,
	KeyPressMask, free_and_exit, &data);
}