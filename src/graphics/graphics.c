/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:10:24 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/27 12:48:40 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../inc/cub3d.h"
#include "../../inc/define.h"
#include "../../minilibx-linux/mlx.h"

t_color rgba_to_int_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	t_color color;

	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

t_color	get_pixel(t_cub_img *img, int x, int y)
{
	t_color color;

	color = 0;
	if (x >= 0 && y >= 0 && x < img->size_x && y < img->size_y)
    {
        color = *(int *)(img->addr + (((y * img->size_x) + x) * (img->pixels_bits / 32)));
    }
	return (color);
}

void	set_pixel(t_cub_img *img, int x, int y, t_color color)
{
	if (x >= 0 && y >= 0 && x < img->size_x && y < img->size_y)
    {
        *(int *)(img->addr + (((y * img->size_x) + x ) * (img->pixels_bits / 32))) = color;
    }
}
