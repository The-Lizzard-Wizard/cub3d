/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:54:07 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/23 17:51:33 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/define.h"
#include <stdio.h>

static void	init_error(char *er_list[NB_ERROR_CODE])
{
	er_list[ER_INIT_MLX] = RM_INIT_MLX;
	er_list[ER_INIT_TEX] = RM_INIT_TEX;
	er_list[ER_INIT_WIN] = RM_INIT_WIN;
	er_list[ER_WRONG_ARG] = RM_WRONG_ARG;
	er_list[ER_MAP_TEX_PATH] = RM_MAP_TEX_PATH;
	er_list[ER_MAP_COLOR] = RM_MAP_COLOR;
	er_list[ER_MAP_DONT_CLOSE] = RM_MAP_DONT_CLOSE;
	er_list[ER_MAP_NO_PLAYER_FOUND] = RM_MAP_NO_PLAYER_FOUND;
	er_list[ER_MAP_UNEXPECTED_CHAR] = RM_MAP_UNEXPECTED_CHAR;
	er_list[ER_MAP_NO_TEX_FOUND] = RM_MAP_NO_TEX_FOUND;
	er_list[ER_MAP_NO_COLOR_FOUND] = RM_MAP_NO_COLOR_FOUND;
}

int	print_error(int code)
{
	char *(er_list[NB_ERROR_CODE]);
	
	init_error(er_list);
	printf("error : %s\n", er_list[code]);
	return (code);
}