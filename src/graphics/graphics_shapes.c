/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_shapes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:25:36 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/11 14:45:42 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/define.h"

void	draw_recangle(t_cub_img *to_img, t_color color, int fill, t_modify mod)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < mod.sc_x)
	{
		x = 0;
		while (x < mod.sc_x)
		{
			if (mod.x >= 0 && mod.y >= 0 &&
				mod.x + x < to_img->size_x && mod.y + y < to_img->size_y)
			{
				if (fill == FILL)
					set_pixel(to_img, mod.x + x, mod.y + y, color);
				else if (fill == LINE)
					if (x == 0 || y == 0 || x == mod.sc_x - 1 || y == mod.sc_y - 1)
						set_pixel(to_img, mod.x + x, mod.y + y, color);
			}
			x++;
		}
		y++;
	}
}
