/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:42:33 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/10 15:36:16 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <limits.h>
#include <math.h>

void	sort_sprite(t_data *data, t_raycast raycast)
{
	int	i;
	t_thing	*thing_curr;

	i = 0;
	while (i < data->nb_thing)
	{
		thing_curr = get_thing_by_id(data->thing_list, i);
		data->sprite_order[i] = i;
		data->sprite_distance[i] = ((raycast.pos.x - thing_curr->pos.x) * (raycast.pos.x - thing_curr->pos.x) + (raycast.pos.y - thing_curr->pos.y) * raycast.pos.y - thing_curr->pos.y);
		i++;
	}
	//sort la liste chainer de sprite ici
}

void	draw_sprite(t_data *data, t_raycast *raycast)
{
	int	i;
	t_thing *thing_curr;
	t_sprite_cast	sprite_cast;
	t_color	color;
	int	y;

	sort_sprite(data, *raycast);
	i = 0;
	y = 0;
	while (i < data->nb_thing)
	{
		thing_curr = get_thing_by_id(data->thing_list, data->sprite_order[i]);
		sprite_cast.sprite_pos.x = thing_curr->pos.x - raycast->pos.x;
		sprite_cast.sprite_pos.y = thing_curr->pos.y - raycast->pos.y;

		sprite_cast.inv_det = 1.0 / (raycast->plane.x * raycast->dir.y - raycast->dir.x * raycast->plane.y);

		sprite_cast.transform.x = sprite_cast.inv_det * (raycast->dir.y * sprite_cast.sprite_pos.x - raycast->dir.x * sprite_cast.sprite_pos.y);
		sprite_cast.transform.y = sprite_cast.inv_det * (-raycast->plane.y * sprite_cast.sprite_pos.x + raycast->plane.x * sprite_cast.sprite_pos.y);

		sprite_cast.sprite_sreen_x = (int)((WIN_W / 2) * (1 + sprite_cast.transform.x / sprite_cast.transform.y));



		
		sprite_cast.sprite_h = abs((int)(WIN_H / sprite_cast.transform.y));
		//printf("t y -%f-\n", sprite_cast.transform.y);
		sprite_cast.sp_start_y =  WIN_H / 2 - sprite_cast.sprite_h / 2;
		if (sprite_cast.sp_start_y < 0)
			sprite_cast.sp_start_y = 0;
		sprite_cast.sp_end_y = WIN_H / 2 + sprite_cast.sprite_h / 2;
		if (sprite_cast.sp_end_y >= WIN_H)
			sprite_cast.sp_end_y = WIN_H - 1;


		//printf("sprite h %d sp start y %d sp end y %d\n", sprite_cast.sprite_h, sprite_cast.sp_start_y, sprite_cast.sp_end_y);
		sprite_cast.sprite_w = abs((int)(WIN_H / sprite_cast.transform.y));
		sprite_cast.sp_start_x = sprite_cast.sprite_sreen_x - sprite_cast.sprite_w / 2;
		if (sprite_cast.sp_start_x < 0)
			sprite_cast.sp_start_x = 0;
		sprite_cast.sp_end_x = sprite_cast.sprite_sreen_x + sprite_cast.sprite_w / 2;
		if (sprite_cast.sp_end_x >= WIN_W)
			sprite_cast.sp_end_x = WIN_W - 1;
		sprite_cast.stripe = sprite_cast.sp_start_x;

		
		while (sprite_cast.stripe < sprite_cast.sp_end_x)
		{
			sprite_cast.tex_x = (int)(256 * (sprite_cast.stripe - (-sprite_cast.sprite_w / 2 + sprite_cast.sprite_sreen_x)) * thing_curr->texture->size_x / sprite_cast.sprite_w) / 256;
			if (sprite_cast.transform.x > 0 && sprite_cast.stripe > 0 && sprite_cast.stripe <= WIN_W && sprite_cast.transform.y < raycast->z_buffer[sprite_cast.stripe])
			{
				y = sprite_cast.sp_start_y;
				while (y < sprite_cast.sp_end_y)
				{
					//printf("draw thing\n");
					sprite_cast.b_factor = (y) * 256 - WIN_H * 128 + sprite_cast.sprite_h * 128;
					sprite_cast.tex_y = ((sprite_cast.b_factor * thing_curr->texture->size_y) / sprite_cast.sprite_h) / 256;
					color = get_pixel(thing_curr->texture, sprite_cast.tex_x, sprite_cast.tex_y);
					if (color != NONE_COLOR_XPM)
						set_pixel(data->screen_img, sprite_cast.stripe, y, color);
					y++;
				}
			}
			sprite_cast.stripe++;
		}
		i++;
	}
}

