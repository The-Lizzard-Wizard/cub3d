/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:04:08 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/09 14:00:54 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdlib.h>

char	get_map_id(t_map map, size_t x, size_t y)
{
	char	id;

	id = '\0';
	if (x >= 0 && y >= 0 && x < map.width && y < map.height)
	{
		id = map.grid[y * map.width + x];
	}
	return (id);
}

int	set_map_id(t_map map, char id, size_t x, size_t y)
{
	if (id == '\0')
		return (EXIT_FAILURE);
	if (x >= 0 && y >= 0 && x < map.width && y < map.height)
	{
		map.grid[y * map.width + x] = id;
	}
	return (EXIT_SUCCESS);
}
