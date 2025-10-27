/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:10:24 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/27 14:02:05 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../inc/cub3d.h"
#include "../../inc/define.h"
#include "../../minilibx-linux/mlx.h"

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
