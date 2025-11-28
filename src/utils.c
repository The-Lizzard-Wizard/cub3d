/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:04:07 by authomas          #+#    #+#             */
/*   Updated: 2025/11/28 15:59:23 by gchauvet         ###   ########.fr       */
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

//la fonction est atroce mais s'est normal :)
void	itoa_buff(int n, char *buff)
{
	size_t		i;
	int	is_n;
	long int	cpy;

	i = 0;
	is_n = 0;
	ft_bzero(buff, 13);
	cpy = n;
	if (n == 0)
	{
		buff[0] = '0';
		return ;
	}
	if (!buff)
		return ;
	if (n < 0)
	{
		is_n = 1;
		cpy = cpy * -1;
	}
	while (cpy > 0)
	{
		buff[i] = (cpy % 10) + '0';
		cpy = cpy / 10;
		i++;
	}
	if (is_n == 1)
		buff[i] = '-';
	i++;
}
