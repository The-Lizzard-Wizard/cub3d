/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:31:20 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/15 13:45:10 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../inc/define.h"
#include "../inc/cub3d.h"
#include "../inc/cub_math.h"
#include "../minilibx-linux/mlx.h"

int free_and_exit(t_data *data)
{
	(void)data;
	mlx_loop_end(data->mlx_ptr);
	return (EXIT_SUCCESS);
}

void	free_img(t_data *data)
{
	free_cub_img(data, data->textures.tex_east, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_north, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_south, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_west, EXIT_SUCCESS);

	free_cub_img(data, data->textures.tex_y_key, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_b_key, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_g_key, EXIT_SUCCESS);
	free_cub_img(data, data->textures.tex_r_key, EXIT_SUCCESS);

	free_cub_img(data, data->ui.wall_img, EXIT_SUCCESS);
	free_cub_img(data, data->ui.y_door, EXIT_SUCCESS);
	free_cub_img(data, data->ui.b_door, EXIT_SUCCESS);
	free_cub_img(data, data->ui.g_door, EXIT_SUCCESS);
	free_cub_img(data, data->ui.r_door, EXIT_SUCCESS);
	free_cub_img(data, data->ui.minimap_img, EXIT_SUCCESS);
	free_cub_img(data, data->ui.pl_img, EXIT_SUCCESS);
	free_cub_img(data, data->ui.mimp_frame, EXIT_SUCCESS);
	free_cub_img(data, data->ui.floor_img, EXIT_SUCCESS);
	free_cub_img(data, data->ui.font, EXIT_SUCCESS);

	free_cub_img(data, data->screen_img, EXIT_SUCCESS);

	free_array(data->map.grid, EXIT_SUCCESS);
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
	if (init_mlx(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pars(&data, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_ui(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_data(&data);
	t_vec2 pos;
	pos.x = 2.5;
	pos.y = 2.5;
	add_thing(&data, data.textures.tex_y_key, pos, THING_Y_KEY);
	pos.x = 3;
	pos.y = 2;
	add_thing(&data, data.textures.tex_b_key, pos, THING_B_KEY);
	pos.x = 5;
	pos.y = 2;
	add_thing(&data, data.textures.tex_g_key, pos, THING_G_KEY);
	pos.x = 6;
	pos.y = 2;
	add_thing(&data, data.textures.tex_r_key, pos, THING_R_KEY);
	update_sprite_info(&data);
	update_minimap(&data);
	event_listener(&data);
	mlx_loop_hook(data.mlx_ptr, update, &data);
	mlx_loop(data.mlx_ptr);
	free_img(&data);
	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	free(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
