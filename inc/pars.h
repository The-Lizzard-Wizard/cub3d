/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:12:05 by authomas          #+#    #+#             */
/*   Updated: 2025/10/23 17:18:35 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H
#define PARS_H

#include <stdbool.h>
#include <linux/limits.h>
#include "cub3d.h"

typedef struct s_pars
{
	char tex_path_no[PATH_MAX];
	char tex_path_so[PATH_MAX];
	char tex_path_ea[PATH_MAX];
	char tex_path_we[PATH_MAX];
	int	ceiling_color;
	bool c_color_check;
	int floor_color;
	bool f_color_check;
	char *map;
}	t_pars;

int	pars_textures(t_pars *pars, int map_fd);
int get_color_c(t_pars *pars, char *line);
int get_color_f(t_pars *pars, char *line);

#endif