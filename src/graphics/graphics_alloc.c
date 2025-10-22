/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:01:01 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/22 18:01:45 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
