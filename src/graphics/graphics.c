/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:10:24 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/22 15:40:53 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../../inc/cub3d.h"
#include "../../minilibx-linux/mlx.h"

t_img	*new_xpm_img(t_data *data, char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path,
		&img->size_x, &img->size_y);
	if (img->mlx_img == NULL)
		return (NULL);
	img->addr = (int *)mlx_get_data_addr(img->mlx_img, &img->pixels_bits,
		&img->size_line, &img->endian);
	return (img);
}

t_img	*new_img(t_data *data, int sx, int sy)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->mlx_img = mlx_new_image(data->mlx_ptr, sx, sy);
	if (img->mlx_img == NULL)
		return (NULL);
	img->size_x = sx;
	img->size_y = sy;
	img->addr = (int *)mlx_get_data_addr(img->mlx_img, &img->pixels_bits,
		&img->size_line, &img->endian);
	return (img);
}

int	draw_img(t_data *data, t_img *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img->mlx_img,
		x, y);
	return (EXIT_SUCCESS);
}

int	draw_img_on_img(t_img *to_img, t_img *img, int x, int y)
{
	int		ix;
	int		iy;
	t_color	px;

	ix = 0;
	iy = 0;
	if (x < 0 || x >= to_img->size_x || x < 0 || x >= to_img->size_y)
		return (EXIT_FAILURE);
	while (ix < img->size_x)
	{
		iy = 0;
		if (x + ix > to_img->size_x)
			break ;
		while (iy < img->size_y)
		{
			if (y + iy > to_img->size_y)
				break ;
			px = get_pixel(img, ix, iy);
			if (px != NONE_COLOR_XPM)
				set_pixel(to_img, x + ix, y + iy, px);
			iy++;
		}
		ix++;
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