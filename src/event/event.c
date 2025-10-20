/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:49:16 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/20 17:58:04 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../minilibx-linux/mlx.h"
#include <X11/X.h>

void	event_listener(t_data *data)
{
    mlx_hook(data->mlx_win, DestroyNotify,
		KeyPressMask, free_and_exit, &data);
}