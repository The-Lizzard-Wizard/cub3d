/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:03:47 by authomas          #+#    #+#             */
/*   Updated: 2025/10/26 12:12:30 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pars.h"

void pars_init(t_pars *pars, t_data *data)
{
	pars->c_color_check = 0;
	pars->f_color_check = 0;
	ft_bzero(pars->tex_path_ea, PATH_MAX);
	ft_bzero(pars->tex_path_we, PATH_MAX);
	ft_bzero(pars->tex_path_no, PATH_MAX);
	ft_bzero(pars->tex_path_so, PATH_MAX);
	pars->ceiling_color = &data->ceiling_color;
	pars->floor_color = &data->floor_color;
	pars->map = NULL;
	pars->player = &data->player;
}

int	pars(t_data *data, char **argv)
{
	t_pars pars;
	int		map_fd;
	
	(void)data;
	pars_init(&pars, data);
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
	{
		print_error(ER_WRONG_MAP_FILE);
		return (EXIT_FAILURE);
	}
	if (pars_textures(&pars, map_fd) == EXIT_FAILURE)
	{
		print_error(ER_MAP_NO_TEX_FOUND);
		return (EXIT_FAILURE);
	}
	if (pars_map(&pars, map_fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	printf("F: %d\nC: %d\nNO: %s\nSO: %s\nWE: %s\nEA: %s\n", *(pars.floor_color), *(pars.ceiling_color), pars.tex_path_no, pars.tex_path_so
	, pars.tex_path_we, pars.tex_path_ea);
	return (EXIT_SUCCESS);
}
