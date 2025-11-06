/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:04:07 by authomas          #+#    #+#             */
/*   Updated: 2025/11/06 15:32:51 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../inc/cub3d.h"
#include "../libft/libft.h"

int	get_tablen(char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
		while (tab[i])
			i++;
	return (i);
}

size_t	get_long_line_in_array(char **array)
{
	size_t	line;
	size_t	i;

	i = 0;
	line = 0;
	while (array[i])
	{
		if (ft_strlen(array[i]) > line)
			line = ft_strlen(array[i]);
		i++;
	}
	return (line);
}
