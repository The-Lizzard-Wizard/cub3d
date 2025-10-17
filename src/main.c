/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:31:20 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/17 14:10:59 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	(void)data;
	if (argc == 1)
	{
		printf("try ./cub3d <map.cub>\n");
		return (EXIT_SUCCESS);
	}
	/*if (init_data(data) == EXIT_FAILURE)
	{
		//// EXIT ////
	}*/
	if (pars_map(&data, argv) == EXIT_FAILURE)
	{
		//// EXIT ////
	}
	/*if (init_mlx(data) == EXIT_FAILURE)
	{
		//// EXIT ////
	}*/
	return (EXIT_SUCCESS);
}