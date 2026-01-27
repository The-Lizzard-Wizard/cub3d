/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:31:20 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/27 15:02:31 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../inc/define.h"
#include "../inc/cub3d.h"
#include "../inc/cub_math.h"
#include "../minilibx-linux/mlx.h"

void	free_error(t_data *data)
{
	free_img(data);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free_ptr(data->mlx_ptr);
}

int	init(t_data *data, char **argv)
{
	init_data(data);
	if (init_mlx(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_textures(data) == EXIT_FAILURE)
	{
		free_error(data);
		return (EXIT_FAILURE);
	}
	if (pars(data, argv) == EXIT_FAILURE)
	{
		free_error(data);
		return (EXIT_FAILURE);
	}
	if (init_ui(data) == EXIT_FAILURE)
	{
		free_error(data);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	(void)argc;
	if (argc == 1)
	{
		print_error(ER_WRONG_ARG);
		return (EXIT_SUCCESS);
	}
	data.thing_list = NULL;
	if (init(&data, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (BONUS)
		print_info();
	update_sp_info(&data);
	update_minimap(&data);
	event_listener(&data);
	mlx_loop_hook(data.mlx_ptr, update, &data);
	mlx_loop(data.mlx_ptr);
	free_img(&data);
	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	mlx_destroy_display(data.mlx_ptr);
	free_ptr(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
