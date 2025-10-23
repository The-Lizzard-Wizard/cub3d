/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:03:47 by authomas          #+#    #+#             */
/*   Updated: 2025/10/23 17:15:58 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pars.h"

void pars_init(t_pars *pars)
{
	pars->c_color_check = 0;
	pars->f_color_check = 0;
	ft_bzero(pars->tex_path_ea, PATH_MAX);
	ft_bzero(pars->tex_path_we, PATH_MAX);
	ft_bzero(pars->tex_path_no, PATH_MAX);
	ft_bzero(pars->tex_path_so, PATH_MAX);
	pars->map = NULL;
}

int	pars_map(t_data *data, char **argv)
{
	t_pars pars;
	int		map_fd;
	
	pars_init(&pars);
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		return (EXIT_FAILURE);
	if (pars_textures(&pars, map_fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
