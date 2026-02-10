/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:33:39 by authomas          #+#    #+#             */
/*   Updated: 2026/02/10 13:23:41 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pars.h"

void *map_dup_error(char **map, char **n_map)
{
	free_array(map, EXIT_FAILURE);
	free_array(n_map, EXIT_FAILURE);
	return (NULL);
}

char	**normalize_map(char **map, size_t map_width, size_t map_height)
{
	char	**n_map;
	size_t	y;
	size_t	x;

	n_map = ft_calloc(sizeof(char *), map_height);
	if (!n_map)
		return (NULL);
	y = -1;
	while (map[++y])
	{
		x = -1;
		n_map[y] = ft_calloc(sizeof(char), map_width + 1);
		if (!n_map[y])
			return (map_dup_error(map, n_map));
		while (map[y][++x])
			n_map[y][x] = map[y][x];
		while (x < map_width)
		{
			n_map[y][x] = '?';
			x++;
		}
	}
	free_array(map, EXIT_SUCCESS);
	return (n_map);
}

int	file_checking(char *file_name)
{
	int	size;

	size = ft_strlen(file_name);
	if (size <= 4)
		return (EXIT_FAILURE);
	if (ft_strncmp(&file_name[size - 4], ".cub", size) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
