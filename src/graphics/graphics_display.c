/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:46:10 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/12 14:20:37 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../inc/cub3d.h"
#include "../../inc/define.h"
#include "../../minilibx-linux/mlx.h"

int	draw_img(t_data *data, t_cub_img *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img->mlx_img,
		x, y);
	return (EXIT_SUCCESS);
}

void	draw_img_while(t_cub_img *to_img, t_modify mod, t_color px, int i[2])
{
	int		i_sc[2];

	i_sc[0] = 0;
	i_sc[1] = 0;
	if (px != NONE_COLOR_XPM)
	{
		i_sc[0] = 0;
		while (i_sc[0] < mod.sc_x)
		{
			i_sc[1] = 0;
			while (i_sc[1] < mod.sc_y)
			{
				set_pixel(to_img, mod.x + (i[0] * mod.sc_x) + i_sc[0],
					mod.y + (i[1] * mod.sc_y) + i_sc[1], px);
				i_sc[1]++;
			}
			i_sc[0]++;
		}
	}
}

int	draw_img_on_img(t_cub_img *to_img, t_cub_img *img, t_modify mod)
{
	int		i[2];
	t_color	px;
	int		pxd;

	i[0] = 0;
	i[1] = 0;
	pxd = 0;
	if (mod.quad_sx == 0)
		mod.quad_sx = img->size_x;
	if (mod.quad_sy == 0)
		mod.quad_sy = img->size_y;
	while (i[0] < mod.quad_sx && mod.x + (i[0] * mod.sc_x) <= to_img->size_x)
	{
		i[1] = 0;
		while (i[1] < mod.quad_sy && mod.y + (\
i[1] * mod.sc_y) <= to_img->size_y)
		{
			pxd++;
			px = get_pixel(img, i[0] + mod.quad_x, i[1] + mod.quad_y);
			draw_img_while(to_img, mod, px, i);
			i[1]++;
		}
		i[0]++;
	}
	return (EXIT_SUCCESS);
}

void	handle_special_char(char *c, t_modify *mod, int first_x)
{
	if (*(c) >= 97 && *(c) <= 122)
		*(c) -= 32;
	if (*(c) == 32)
		mod->x += FONT_CHAR_SIZE * mod->sc_x;
	if (*(c) == '\n')
	{
		mod->x = first_x;
		mod->y += FONT_CHAR_SIZE * mod->sc_y;
	}
}

void	put_text_on_img(t_cub_img *to_img, t_cub_img *font,
	char *str, t_modify mod)
{
	size_t	i;
	int		first_x;
	char	c;

	i = 0;
	mod.quad_sx = FONT_CHAR_SIZE;
	mod.quad_sy = FONT_CHAR_SIZE;
	mod.x -= (FONT_CHAR_SIZE * mod.sc_x) - mod.text_space;
	first_x = mod.x;
	while (str[i])
	{
		c = str[i];
		handle_special_char(&c, &mod, first_x);
		if (c >= 33 && c <= 90)
		{
			mod.x += (FONT_CHAR_SIZE * mod.sc_x);
			if (mod.x != first_x)
				mod.x -= mod.text_space;
			mod.quad_y = ((c - 33) / 10) * FONT_CHAR_SIZE;
			mod.quad_x = ((c - 33) % 10) * FONT_CHAR_SIZE;
			draw_img_on_img(to_img, font, mod);
		}
		i++;
	}
}
