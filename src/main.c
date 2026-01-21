/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:31:20 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/21 15:27:39 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../inc/define.h"
#include "../inc/cub3d.h"
#include "../inc/cub_math.h"
#include "../minilibx-linux/mlx.h"

void	free_more_img(t_data *data)
{
	free_cub_img(data, data->textures.tex_east, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_north, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_south, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_west, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_y_key, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_b_key, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_g_key, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_r_key, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_r_door, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_y_door, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_g_door, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_b_door, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_door, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_magic, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_chicken, EXIT_SUCCESS);
	free_cub_img(data, data->ui.wall_img, EXIT_SUCCESS);
	free_cub_img(data, data->ui.y_door, EXIT_SUCCESS);
	free_cub_img(data, data->ui.b_door, EXIT_SUCCESS);
	free_cub_img(data, data->ui.g_door, EXIT_SUCCESS);
	free_cub_img(data, data->ui.r_door, EXIT_SUCCESS);
	free_cub_img(data, data->ui.door, EXIT_SUCCESS);
	free_cub_img(data, data->ui.door_open, EXIT_SUCCESS);
}

void	free_img(t_data *data)
{
	free_more_img(data);
	free_cub_img(data, data->ui.tex_y_key, EXIT_SUCCESS);
	free_cub_img(data, data->ui.tex_g_key, EXIT_SUCCESS);
	free_cub_img(data, data->ui.tex_b_key, EXIT_SUCCESS);
	free_cub_img(data, data->ui.tex_r_key, EXIT_SUCCESS);
	free_cub_img(data, data->ui.minimap_img, EXIT_SUCCESS);
	free_cub_img(data, data->ui.pl_img, EXIT_SUCCESS);
	free_cub_img(data, data->ui.mimp_frame, EXIT_SUCCESS);
	free_cub_img(data, data->ui.floor_img, EXIT_SUCCESS);
	free_cub_img(data, data->ui.font, EXIT_SUCCESS);
	free_cub_anime(data, data->textures.anime_tex_kiwi, EXIT_SUCCESS);
	free_cub_anime(data, data->textures.anime_tex_banana, EXIT_SUCCESS);
	free_cub_anime(data, data->textures.anime_tex_magic_shoot, EXIT_SUCCESS);
	free_cub_img(data, data->ui.magic_rod_0, EXIT_SUCCESS);
	free_cub_img(data, data->screen_img, EXIT_SUCCESS);
	free_thing_list(data, EXIT_SUCCESS);
	free_ptr(data->sp_order);
	free_ptr(data->sp_distance);
	free_array(data->map.grid, EXIT_SUCCESS);
}

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
