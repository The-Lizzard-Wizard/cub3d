/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:04:07 by authomas          #+#    #+#             */
/*   Updated: 2025/12/15 14:21:35 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../inc/cub3d.h"
#include "../libft/libft.h"

int	is_out_of_bounds(t_data *data)
{
	if (data->player.pos.x <= 0 || data->player.pos.y <= 0 ||
		data->player.pos.x > (double)data->map.width ||
		data->player.pos.y > (double)data->map.height)
	{
		return (1);
	}
	return (0);
}

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

static size_t	get_malloclen(int n)
{
	int		cpy;
	size_t	i;

	i = 1;
	cpy = n;
	if (n <= 0)
		i += 1;
	while (cpy != 0)
	{
		cpy /= 10;
		i++;
	}
	return (i);
}

void	itoa_buff(int n, char *buff)
{
	size_t		i;
	long int	cpy;

	i = get_malloclen(n);
	cpy = n;
	ft_bzero(buff, i + 1);
	if (!buff)
		return ;
	if (n < 0)
	{
		buff[0] = '-';
		cpy *= -1;
	}
	i -= 2;
	while (cpy >= 10)
	{
		buff[i] = (cpy % 10) + '0';
		cpy = cpy / 10;
		i--;
	}
	buff[i] = (cpy % 10) + '0';
}
