/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:37:18 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/25 13:13:52 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../minilibx-linux/mlx.h"
#include <stdlib.h>

int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		print_error(ER_INIT_MLX);
		return (EXIT_FAILURE);
	}
	data->screen_img = new_img(data, WIN_W, WIN_H);
	if (!data->screen_img)
	{
		free_ptr(data->mlx_ptr);
		print_error(ER_INIT_SC_IMG);
		return (EXIT_FAILURE);
	}
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "cub3d");
	if (data->mlx_win == NULL)
	{
		free_cub_img(data, data->screen_img, EXIT_FAILURE);
		free_ptr(data->mlx_ptr);
		print_error(ER_INIT_WIN);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
