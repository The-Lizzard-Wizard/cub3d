/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:23:20 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/11 13:40:26 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

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
