/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:09:15 by authomas          #+#    #+#             */
/*   Updated: 2026/01/26 15:34:24 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pars.h"

int	set_path(char *pars_path, char *line, int path_len)
{
	if (*pars_path)
		return (EXIT_FAILURE);
	if (path_len > PATH_MAX)
		path_len = PATH_MAX;
	ft_strlcpy(pars_path, line, path_len + 1);
	return (EXIT_SUCCESS);
}

int	get_path_by_id(t_pars *pars, char id, char *line)
{
	int	i;

	i = 0;
	if (id == 'F')
	{
		line[ft_strlen(line) - 1] = 0;
		return (get_color_f(pars, line));
	}
	else if (id == 'C')
	{
		line[ft_strlen(line) - 1] = 0;
		return (get_color_c(pars, line));
	}
	while (!ft_isspace(line[i]))
		i++;
	if (id == 'N' && !*(pars->tex_path_no))
		return (set_path(pars->tex_path_no, line, i));
	else if (id == 'S' && !*(pars->tex_path_so))
		return (set_path(pars->tex_path_so, line, i));
	else if (id == 'E' && !*(pars->tex_path_ea))
		return (set_path(pars->tex_path_ea, line, i));
	else if (id == 'W' && !*(pars->tex_path_we))
		return (set_path(pars->tex_path_we, line, i));
	return (EXIT_FAILURE);
}

int	check_tex_line(t_pars *pars, char *line)
{
	int		i;
	char	id;

	i = 0;
	id = 0;
	if (!line)
		return (EXIT_FAILURE);
	while (ft_isspace(line[i]))
		i++;
	get_id(&id, line);
	if (id == 0)
		return (EXIT_FAILURE);
	i += 2;
	while (ft_isspace(line[i]))
		i++;
	if (get_path_by_id(pars, id, line + i) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_var(t_pars *pars)
{
	if (!pars->c_color_check || !pars->f_color_check)
	{
		print_error(ER_MAP_NO_COLOR_FOUND);
		free_ptr(pars->line);
		return (EXIT_FAILURE);
	}
	if (!*(pars->tex_path_ea) || !*(pars->tex_path_we))
	{
		print_error(ER_MAP_NO_TEX_FOUND);
		free_ptr(pars->line);
		return (EXIT_FAILURE);
	}
	if (!*(pars->tex_path_no) || !*(pars->tex_path_so))
	{
		print_error(ER_MAP_NO_TEX_FOUND);
		free_ptr(pars->line);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	pars_textures(t_pars *pars, int map_fd)
{
	pars->line = get_next_line(map_fd);
	while (pars->line)
	{
		if (*(pars->line) != '\n')
		{
			if (check_tex_line(pars, pars->line) == EXIT_FAILURE)
				return (check_var(pars));
		}
		free_ptr(pars->line);
		pars->line = get_next_line(map_fd);
	}
	return (EXIT_FAILURE);
}
