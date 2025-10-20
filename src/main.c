/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:31:20 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/20 16:46:02 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../inc/cub3d.h"
#include "../minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	(void)argc;
	if (argc == 1)
	{
		printf("try ./cub3d <map.cub>\n");
		return (EXIT_SUCCESS);
	}
	/*if (init_data(data) == EXIT_FAILURE)
	{
		//// EXIT ////
	}*/
	if (init_mlx(&data) == EXIT_FAILURE)
	{
		//// EXIT ////
	}
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}