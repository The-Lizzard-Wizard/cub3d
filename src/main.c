/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:31:20 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/21 11:17:47 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../inc/cub3d.h"
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
		printf("try ./cub3d <map.cub>\n");
		return (EXIT_SUCCESS);
	}
	/*if (init_data(data) == EXIT_FAILURE)
	{
		//// EXIT ////
	}*/
	if (init_mlx(&data) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	event_listener(&data);
	t_img *img = new_xpm_img(&data, "textures/090.xpm");
	///t_img *img2 = new_img(&data, 200, 200);
	draw_img(&data, img, 0, 0);
	printf("%d", get_pixel(img, 0, 0));
	printf("%d", get_pixel(img, 0, 10));
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}