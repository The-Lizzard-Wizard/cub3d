/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:03:43 by authomas          #+#    #+#             */
/*   Updated: 2026/01/21 14:20:22 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pars.h"
#include "../../inc/cub3d.h"

t_color	rgba_to_int_color(unsigned char r, unsigned char g,
	unsigned char b, unsigned char a)
{
	t_color	color;

	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

int	get_color_c(t_pars *pars, char *line)
{
	size_t	r;
	size_t	g;
	size_t	b;
	char	**raw;

	raw = ft_split(line, ',');
	if (!raw)
		return (EXIT_FAILURE);
	if (array_len(raw) == 3 && !pars->c_color_check)
	{
		r = ft_atoi(raw[0]);
		g = ft_atoi(raw[1]);
		b = ft_atoi(raw[2]);
		if (r > 255 || g > 255 || b > 255)
		{
			free_array(raw, EXIT_FAILURE);
			return (EXIT_FAILURE);
		}
		*(pars->ceiling_color) = rgba_to_int_color(r, g, b, 0);
		pars->c_color_check = 1;
		free_array(raw, EXIT_SUCCESS);
		return (EXIT_SUCCESS);
	}
	free_array(raw, EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int	get_color_f(t_pars *pars, char *line)
{
	size_t	r;
	size_t	g;
	size_t	b;
	char	**raw;

	raw = ft_split(line, ',');
	if (!raw)
		return (EXIT_FAILURE);
	if (array_len(raw) == 3 && !pars->f_color_check)
	{
		r = ft_atoi(raw[0]);
		g = ft_atoi(raw[1]);
		b = ft_atoi(raw[2]);
		if (r > 255 || g > 255 || b > 255)
		{
			free_array(raw, EXIT_FAILURE);
			return (EXIT_FAILURE);
		}
		*(pars->floor_color) = rgba_to_int_color(r, g, b, 0);
		pars->f_color_check = 1;
		free_array(raw, EXIT_SUCCESS);
		return (EXIT_SUCCESS);
	}
	free_array(raw, EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	get_id(char *id, char *line)
{
	if (*line == 'F' && ft_isspace(*(line + 1)))
		*id = 'F';
	if (*line == 'C' && ft_isspace(*(line + 1)))
		*id = 'C';
	if (*line == 'N' && *(line + 1) == 'O' && ft_isspace(*(line + 2)))
		*id = 'N';
	if (*line == 'S' && *(line + 1) == 'O' && ft_isspace(*(line + 2)))
		*id = 'S';
	if (*line == 'E' && *(line + 1) == 'A' && ft_isspace(*(line + 2)))
		*id = 'E';
	if (*line == 'W' && *(line + 1) == 'E' && ft_isspace(*(line + 2)))
		*id = 'W';
}
