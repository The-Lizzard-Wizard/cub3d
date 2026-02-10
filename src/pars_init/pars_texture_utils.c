/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:03:43 by authomas          #+#    #+#             */
/*   Updated: 2026/02/10 15:05:13 by gchauvet         ###   ########.fr       */
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

int	value_check(int r, int g, int b, char **raw)
{
	char	*r_string;
	char	*g_string;
	char	*b_string;

	r_string = ft_itoa(r);
	g_string = ft_itoa(g);
	b_string = ft_itoa(b);
	if (ft_strncmp(r_string, move_buff(raw[0]), -1) != 0
		|| ft_strncmp(g_string, move_buff(raw[1]), -1) != 0
		|| ft_strncmp(b_string, move_buff(raw[2]), -1) != 0)
	{
		free_ptr(r_string);
		free_ptr(g_string);
		free_ptr(b_string);
		return (EXIT_FAILURE);
	}
	free_ptr(r_string);
	free_ptr(g_string);
	free_ptr(b_string);
	return (EXIT_SUCCESS);
}

int	get_color_c(t_pars *pars, char *line)
{
	size_t	r;
	size_t	g;
	size_t	b;
	char	**raw;

	if (line[ft_strlen(line) - 1] == ',')
		return (EXIT_FAILURE);
	raw = ft_split(line, ',');
	if (!raw)
		return (print_error_exit(ER_MALLOC_ER, EXIT_FAILURE));
	if (array_len(raw) == 3 && !pars->c_color_check)
	{
		r = ft_atoi(raw[0]);
		g = ft_atoi(raw[1]);
		b = ft_atoi(raw[2]);
		if (r > 255 || g > 255 || b > 255
			|| value_check(r, g, b, raw) == EXIT_FAILURE)
			return (free_array(raw, EXIT_FAILURE));
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

	if (line[ft_strlen(line) - 1] == ',')
		return (EXIT_FAILURE);
	raw = ft_split(line, ',');
	if (!raw)
		return (print_error_exit(ER_MALLOC_ER, EXIT_FAILURE));
	if (array_len(raw) == 3 && !pars->f_color_check)
	{
		r = ft_atoi(raw[0]);
		g = ft_atoi(raw[1]);
		b = ft_atoi(raw[2]);
		if (r > 255 || g > 255 || b > 255
			|| value_check(r, g, b, raw) == EXIT_FAILURE)
			return (free_array(raw, EXIT_FAILURE));
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
