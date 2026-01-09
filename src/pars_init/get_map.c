/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:12:30 by authomas          #+#    #+#             */
/*   Updated: 2026/01/09 16:35:35 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../../inc/pars.h"

char	*get_map(t_pars *pars, int map_fd)
{
	char	*map_inline;
	char	*tmp;

	map_inline = ft_strdup(pars->line);
	free_ptr(pars->line);
	pars->line = get_next_line(map_fd);
	while (pars->line)
	{
		tmp = ft_strjoin(map_inline, pars->line);
		free_ptr(map_inline);
		if (!tmp)
		{
			return (NULL);
		}
		map_inline = tmp;
		free_ptr(pars->line);
		pars->line = get_next_line(map_fd);
	}
	return (map_inline);
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
		{
			if (map[y][x] == '0')
			{
				if (x == 0 || is_valid_adj(map[y][x - 1]) == EXIT_FAILURE)
					return (EXIT_FAILURE);
				if (is_valid_adj(map[y][x + 1]) == EXIT_FAILURE)
					return (EXIT_FAILURE);
				if (!map[y + 1] || ft_strlen(map[y + 1]) < x
					|| is_valid_adj(map[y + 1][x]) == EXIT_FAILURE)
					return (EXIT_FAILURE);
				if (y == 0 || ft_strlen(map[y - 1]) < x
					|| is_valid_adj(map[y - 1][x]) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}
