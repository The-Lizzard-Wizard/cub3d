/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:23:20 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/01 13:31:14 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	free_array(char **tab, int code)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	free(tab);
	return (code);
}

int	free_one_and_exit(void *ptr, int code)
{
	free(ptr);
	return (code);
}

int	free_too_and_exit(void *ptr1, void *ptr2, int code)
{
	free(ptr1);
	free(ptr2);
	return (code);
}

int	free_three_and_exit(void *ptr1, void *ptr2, void *ptr3, int code)
{
	free(ptr1);
	free(ptr2);
	free(ptr3);
	return (code);
}
