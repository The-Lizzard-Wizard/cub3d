/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:10:24 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/21 13:35:00 by authomas         ###   ########lyon.fr   */
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

t_color	get_pixel(t_img *img, int x, int y)
{
	int color;

	color = 0;
	if (x >= 0 && y >= 0 && x < img->size_x && y < img->size_y)
    {
        color = *(t_color *)(img->addr + (y * img->size_y + x * img->pixels_bits));
    }
	return (color);
}

void	set_pixel(t_img *img, int x, int y, t_color color)
{
	if (x >= 0 && y >= 0 && x < img->size_x && y < img->size_y)
    {
        *(t_color *)(img->addr + (y * img->size_y + x * img->pixels_bits)) = color;
    }
}