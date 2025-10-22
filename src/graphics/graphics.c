/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:10:24 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/22 18:03:52 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../inc/cub3d.h"
#include "../../minilibx-linux/mlx.h"

int	draw_img(t_data *data, t_img *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img->mlx_img,
		x, y);
	return (EXIT_SUCCESS);
}

void	draw_img_while(t_img *to_img, t_modify mod, t_color px, int i[2])
{
	int		i_sc[2];

	i_sc[0] = 0;
	i_sc[1] = 0;
	if (px != NONE_COLOR_XPM)
	{
		i_sc[0] = 0;
		while (i_sc[0] < mod.scale)
		{
			i_sc[1] = 0;
			while (i_sc[1] < mod.scale)
			{
				set_pixel(to_img, mod.x + (i[0] * mod.scale) + i_sc[0],
					mod.y + (i[1] * mod.scale) + i_sc[1], px);
				i_sc[1]++;
			}
			i_sc[0]++;
		}
	}
}

int	draw_img_on_img(t_img *to_img, t_img *img, t_modify mod)
{
	int		i[2];
	t_color	px;

	i[0] = 0;
	i[1] = 0;
	if (mod.x < 0 || mod.x >= to_img->size_x || mod.x < 0 || mod.x >= to_img->size_y)
		return (EXIT_FAILURE);
	while (i[0] < img->size_x && mod.x + (i[0] * mod.scale) <= to_img->size_x)
	{
		i[1] = 0;
		while (i[1] < img->size_y && mod.y + (i[1] * mod.scale) <= to_img->size_y)
		{
			px = get_pixel(img, i[0], i[1]);
			draw_img_while(to_img, mod, px, i);
			i[1]++;
		}
		i[0]++;
	}
	return (EXIT_SUCCESS);
}

t_color	get_pixel(t_img *img, int x, int y)
{
	t_color color;

	color = 0;
	if (x >= 0 && y >= 0 && x < img->size_x && y < img->size_y)
    {
        color = *(int *)(img->addr + (((y * img->size_x) + x) * (img->pixels_bits / 32)));
    }
	return (color);
}

void	set_pixel(t_img *img, int x, int y, t_color color)
{
	if (x >= 0 && y >= 0 && x < img->size_x && y < img->size_y)
    {
        *(int *)(img->addr + (((y * img->size_x) + x ) * (img->pixels_bits / 32))) = color;
    }
}
