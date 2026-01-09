/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:10:24 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/09 13:59:50 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../inc/cub3d.h"
#include "../../inc/define.h"
#include "../../minilibx-linux/mlx.h"

t_color	get_pixel(t_cub_img *img, int x, int y)
{
	t_color	color;

	color = 0;
	if (x >= 0 && y >= 0 && x < img->size_x && y < img->size_y)
	{
		color = *(int *)(img->addr + (((y * img->size_x) + x)
					* (img->pixels_bits / 32)));
	}
	return (color);
}

void	set_pixel(t_cub_img *img, int x, int y, t_color color)
{
	if (x >= 0 && y >= 0 && x < img->size_x && y < img->size_y)
	{
		*(int *)(img->addr + (((y * img->size_x) + x)
					* (img->pixels_bits / 32))) = color;
	}
}

void	init_modify(t_modify *mod)
{
	mod->x = 0;
	mod->y = 0;
	mod->sc_x = 1;
	mod->sc_y = 1;
	mod->quad_sx = 0;
	mod->quad_sy = 0;
	mod->quad_x = 0;
	mod->quad_y = 0;
	mod->text_space = 12;
}
