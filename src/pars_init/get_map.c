/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:12:30 by authomas          #+#    #+#             */
/*   Updated: 2026/01/26 14:30:53 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../../inc/pars.h"

char	*move_buff(char *buff)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(buff);
	while (buff[i] && ft_isspace(buff[i]))
		i++;
	j = len - 1;
	while (buff[j] && ft_isspace(buff[j]))
		j--;
	if (ft_isspace(buff[j + 1]))
		buff[j + 1] = '\0';
	ft_printf("--%s--\n", buff + i);
	return (buff + i);
}

char	*get_map(t_pars *pars, int map_fd)
{
	char	*map_inline;
	char	*tmp;

	map_inline = ft_strdup(pars->line);
	free_ptr(pars->line);
	if (!map_inline)
		return (NULL);
	pars->line = get_next_line(map_fd);
	while (pars->line)
	{
		if (ft_strncmp(pars->line, "\n", -1) == 0)
		{
			free_ptr(pars->line);
			pars->line = ft_strdup(" \n");
		}
		tmp = ft_strjoin(map_inline, pars->line);
		free_ptr(map_inline);
		free_ptr(pars->line);
		if (!tmp)
			return (NULL);
		map_inline = tmp;
		pars->line = get_next_line(map_fd);
	}
	return (map_inline);
}

int	map_check_if(char **map, size_t x, size_t y)
{
	if (x == 0 || is_valid_adj(map[y][x - 1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_valid_adj(map[y][x + 1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (!map[y + 1] || ft_strlen(map[y + 1]) < x)
	{
		print_error(ER_MAP_NOT_CLOSE);
		return (EXIT_FAILURE);
	}
	if (is_valid_adj(map[y + 1][x]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (y == 0 || ft_strlen(map[y - 1]) < x)
	{
		print_error(ER_MAP_NOT_CLOSE);
		return (EXIT_FAILURE);
	}
	if (is_valid_adj(map[y - 1][x]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	map_check(char **map)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == '0')
				if (map_check_if(map, x, y) == EXIT_FAILURE)
					return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
