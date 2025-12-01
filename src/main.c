/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:31:20 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/01 11:44:39 by gchauvet         ###   ########.fr       */
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
	pos.x = 2;
	pos.y = 2;
	add_thing(&data, data.textures.tex_north, pos, THING_Y_KEY);
	pos.x = 3;
	pos.y = 2;
	add_thing(&data, data.textures.tex_north, pos, THING_B_KEY);
	pos.x = 5;
	pos.y = 2;
	add_thing(&data, data.textures.tex_north, pos, THING_G_KEY);
	pos.x = 6;
	pos.y = 2;
	add_thing(&data, data.textures.tex_north, pos, THING_R_KEY);
	event_listener(&data);
	mlx_loop_hook(data.mlx_ptr, update, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
