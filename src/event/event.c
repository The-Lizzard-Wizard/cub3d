/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:49:16 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/07 17:22:37 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../minilibx-linux/mlx.h"
#include <X11/X.h>
#include "../../inc/key.h"

int	keypresse(int key, t_data *data)
{
	if (key == K_ESC)
		free_and_exit(data);
	return (EXIT_SUCCESS);
}

void	event_listener(t_data *data)
{
	mlx_hook(data->mlx_win, 2, (1L << 0), keypresse, data);
	mlx_hook(data->mlx_win, DestroyNotify,
	KeyPressMask, free_and_exit, &data);
}