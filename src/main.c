/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:31:20 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/11 16:06:08 by gchauvet         ###   ########.fr       */
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
	exit(EXIT_SUCCESS);
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
	(void)data;
	if (init_mlx(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pars(&data, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_ui(&data);
	event_listener(&data);
	mlx_loop_hook(data.mlx_ptr, update, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
