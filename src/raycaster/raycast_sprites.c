/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:42:33 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/12 18:32:04 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <limits.h>
#include <math.h>

void	swap_order(t_data *data, int i, int j)
{
	int		tmp;
	double	dtmp;

	tmp = data->sprite_order[i];
	dtmp = data->sprite_distance[i];
	data->sprite_order[i] = data->sprite_order[j];
	data->sprite_order[j] = tmp;
	data->sprite_distance[i] = data->sprite_distance[j];
	data->sprite_distance[j] = dtmp;
}

void	sort_sprite(t_data *data, t_raycast raycast)
{
	int		i;
	t_thing	*thing_curr;

	i = 0;
	while (i < data->nb_thing)
	{
		thing_curr = get_thing_by_id(data->thing_list, i);
		data->sprite_order[i] = i;
		data->sprite_distance[i] = ((raycast.pos.x - thing_curr->pos.x) * (raycast.pos.x - thing_curr->pos.x) + (raycast.pos.y - thing_curr->pos.y) * raycast.pos.y - thing_curr->pos.y);
		i++;
	}
	i = 0;
	j = 0;
	while (i < data->nb_thing)
	{
		j = i + 1;
		while (j < data->nb_thing)
		{
			if (data->sprite_distance[j] > data->sprite_distance[i])
				swap_order(data, i, j);
			j++;
		}
		i++;
	}
}

void	init_sprite_cast(t_sprite_cast *sprite_cast, t_raycast *raycast, t_thing *thing_curr)
{
	sprite_cast->sprite_pos.x = thing_curr->pos.x - raycast->pos.x;
	sprite_cast->sprite_pos.y = thing_curr->pos.y - raycast->pos.y;
	sprite_cast->inv_det = 1.0 / (raycast->plane.x * raycast->dir.y - raycast->dir.x * raycast->plane.y);
	sprite_cast->transform.x = sprite_cast->inv_det * (raycast->dir.y * sprite_cast->sprite_pos.x - raycast->dir.x * sprite_cast->sprite_pos.y);
	sprite_cast->transform.y = sprite_cast->inv_det * (-raycast->plane.y * sprite_cast->sprite_pos.x + raycast->plane.x * sprite_cast->sprite_pos.y);
	sprite_cast->sprite_sreen_x = (int)((WIN_W / 2) * (1 + sprite_cast->transform.x / sprite_cast->transform.y));
	sprite_cast->size_factor = WIN_H / sprite_cast->transform.y;
	sprite_cast->sprite_h = (int)sprite_cast->size_factor;
	sprite_cast->sprite_w = (int)sprite_cast->size_factor;
	sprite_cast->sp_start_y =  -sprite_cast->sprite_h / 2 + WIN_H / 2;
if (sprite_cast->sp_start_y < 0)
		sprite_cast->sp_start_y = 0;
	sprite_cast->sp_end_y = sprite_cast->sprite_h / 2 + WIN_H / 2;
	if (sprite_cast->sp_end_y >= WIN_H)
		sprite_cast->sp_end_y = WIN_H - 1;
	sprite_cast->sp_start_x = sprite_cast->sprite_sreen_x - sprite_cast->sprite_w / 2;
	if (sprite_cast->sp_start_x < 0)
		sprite_cast->sp_start_x = 0;
	sprite_cast->sp_end_x = sprite_cast->sprite_sreen_x + sprite_cast->sprite_w / 2;
	if (sprite_cast->sp_end_x >= WIN_W)
		sprite_cast->sp_end_x = WIN_W - 1;
	sprite_cast->stripe = sprite_cast->sp_start_x;
}

void	darw_sprite(t_data *data, t_sprite_cast *sprite_cast, t_raycast *raycast, t_thing *thing_curr)
{
	int		y;
	t_color	color;

	y = 0;
	while (sprite_cast->stripe < sprite_cast->sp_end_x)
	{
		sprite_cast->tex_x = (int)(sprite_cast->tex_step_x * (sprite_cast->stripe - (sprite_cast->sprite_sreen_x - sprite_cast->sprite_w / 2)));
		if (sprite_cast->transform.y > 0 && sprite_cast->stripe > 0 && sprite_cast->stripe <= WIN_W && sprite_cast->transform.y < raycast->z_buffer[sprite_cast->stripe])
		{
			sprite_cast->tex_pos = (sprite_cast->sp_start_y - WIN_H/2 + sprite_cast->sprite_h/2) * sprite_cast->tex_step_y;
			y = sprite_cast->sp_start_y;
			while (y < sprite_cast->sp_end_y)
			{
				sprite_cast->b_factor = (y) * 256 - WIN_H * 128 + sprite_cast->sprite_h * 128;
				sprite_cast->tex_y = (int)sprite_cast->tex_pos;
				color = get_pixel(thing_curr->texture, sprite_cast->tex_x, sprite_cast->tex_y);
				if (color != NONE_COLOR_XPM)
					set_pixel(data->screen_img, sprite_cast->stripe, y, color);
				sprite_cast->tex_pos += sprite_cast->tex_step_y;
				y++;
			}
		}
		sprite_cast->stripe++;
	}
}

void	sprite_casting(t_data *data, t_raycast *raycast)
{
	int	i;
	t_thing *thing_curr;
	t_sprite_cast	sprite_cast;

	sort_sprite(data, *raycast);
	i = 0;
	while (i < data->nb_thing)
	{
		thing_curr = get_thing_by_id(data->thing_list, data->sprite_order[i]);
		init_sprite_cast(&sprite_cast, raycast, thing_curr);
		sprite_cast.tex_step_x = (double)thing_curr->texture->size_x / sprite_cast.sprite_w;
		sprite_cast.tex_step_y = (double)thing_curr->texture->size_y / sprite_cast.sprite_h;
		sprite_cast.tex_pos = (sprite_cast.sp_start_y - WIN_H/2 + sprite_cast.sprite_h/2) * sprite_cast.tex_step_y;
		darw_sprite(data, &sprite_cast, raycast, thing_curr);
		i++;
	}
}

