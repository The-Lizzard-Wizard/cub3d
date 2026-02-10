/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:54:07 by gchauvet          #+#    #+#             */
/*   Updated: 2026/02/10 14:41:26 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/define.h"
#include <stdio.h>
#include "../../libft/libft.h"

static void	init_error(char *er_list[NB_ERROR_CODE])
{
	er_list[ER_INIT_MLX] = RM_INIT_MLX;
	er_list[ER_INIT_TEX] = RM_INIT_TEX;
	er_list[ER_INIT_WIN] = RM_INIT_WIN;
	er_list[ER_INIT_SC_IMG] = RM_INIT_SC_IMG;
	er_list[ER_MALLOC_ER] = RM_MALLOC_ER;
	er_list[ER_WRONG_MAP_FILE] = RM_WRONG_MAP_FILE;
	er_list[ER_WRONG_ARG] = RM_WRONG_ARG;
	er_list[ER_MAP_TEX_PATH] = RM_MAP_TEX_PATH;
	er_list[ER_MAP_COLOR] = RM_MAP_COLOR;
	er_list[ER_MAP_NOT_CLOSE] = RM_MAP_NOT_CLOSE;
	er_list[ER_MAP_NO_PLAYER_FOUND] = RM_MAP_NO_PLAYER_FOUND;
	er_list[ER_MAP_UNEXPECTED_CHAR] = RM_MAP_UNEXPECTED_CHAR;
	er_list[ER_MAP_NO_TEX_FOUND] = RM_MAP_NO_TEX_FOUND;
	er_list[ER_MAP_NO_COLOR_FOUND] = RM_MAP_NO_COLOR_FOUND;
	er_list[ER_INIT_UI_IMG] = RM_INIT_UI_IMG;
	er_list[ER_INIT_UI_MIMP] = RM_INIT_UI_MIMP;
	er_list[ER_MAP_TOO_MANY_PLAYER] = RM_MAP_TOO_MANY_PLAYER;
}

int	print_error(int code)
{
	static int	nb_er = 0;
	char		*er_list[NB_ERROR_CODE];

	if (nb_er == 0)
	{
		init_error(er_list);
		ft_dprintf(2, "\e[1;31merror\e[0m : %s\n", er_list[code]);
	}
	nb_er++;
	return (code);
}
