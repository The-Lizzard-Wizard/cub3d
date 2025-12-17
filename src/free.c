/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:23:20 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/16 16:56:41 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

int	free_array(char **tab, int code)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free_ptr(tab[i]);
			i++;
		}
	}
	free_ptr(tab);
	return (code);
}

int	free_one_and_exit(void *ptr, int code)
{
	free_ptr(ptr);
	return (code);
}

int	free_too_and_exit(void *ptr1, void *ptr2, int code)
{
	free_ptr(ptr1);
	free_ptr(ptr2);
	return (code);
}

int	free_three_and_exit(void *ptr1, void *ptr2, void *ptr3, int code)
{
	free_ptr(ptr1);
	free_ptr(ptr2);
	free_ptr(ptr3);
	return (code);
}
