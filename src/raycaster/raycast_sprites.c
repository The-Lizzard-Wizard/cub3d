/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:42:33 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/30 15:14:35 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <limits.h>
#include <math.h>

void	swap_order(t_data *data, int i, int j)
{
	int		tmp;
	double	dtmp;

	tmp = data->sp_order[i];
	dtmp = data->sp_distance[i];
	data->sp_order[i] = data->sp_order[j];
	data->sp_order[j] = tmp;
	data->sp_distance[i] = data->sp_distance[j];
	data->sp_distance[j] = dtmp;
}

void	sort_sp(t_data *data, t_raycast raycast)
{
	int		i;
	int		j;
	t_thing	*thing_curr;
	t_vec2	dxy;

	i = 0;
	while (i < data->nb_thing)
	{
		thing_curr = get_thing_by_id(data->thing_list, i);
		data->sp_order[i] = i;
		dxy.x = raycast.pos.x - thing_curr->pos.x;
		dxy.y = raycast.pos.y - thing_curr->pos.y;

		data->sp_distance[i] = dxy.x * dxy.x + dxy.y * dxy.y;
		i++;
	}
	i = 0;
	j = 0;
	while (i < data->nb_thing)
	{
		j = i + 1;
		while (j < data->nb_thing)
		{
			if (data->sp_distance[j] > data->sp_distance[i])
				swap_order(data, j, i);
			j++;
		}
		i++;
	}
}

void	init_sp_cast_2(t_sp_cast *sp_cast)
{
	if (sp_cast->sp_start_y < 0)
		sp_cast->sp_start_y = 0;
	sp_cast->sp_end_y = sp_cast->sp_h / 2 + WIN_H / 2;
	if (sp_cast->sp_end_y >= WIN_H)
		sp_cast->sp_end_y = WIN_H - 1;
	sp_cast->sp_start_x = sp_cast->sp_sc_x - sp_cast->sp_w / 2;
	if (sp_cast->sp_start_x < 0)
		sp_cast->sp_start_x = 0;
	sp_cast->sp_end_x = sp_cast->sp_sc_x + sp_cast->sp_w / 2;
	if (sp_cast->sp_end_x >= WIN_W)
		sp_cast->sp_end_x = WIN_W - 1;
	sp_cast->stripe = sp_cast->sp_start_x;
}

void	init_sp_cast(t_sp_cast *sp_cast,
			t_raycast *raycast, t_thing *thing_curr)
{
	sp_cast->sp_pos.x = thing_curr->pos.x - raycast->pos.x;
	sp_cast->sp_pos.y = thing_curr->pos.y - raycast->pos.y;
	sp_cast->inv_det = 1.0 / (raycast->plane.x * raycast->dir.y - \
		raycast->dir.x * raycast->plane.y);
	sp_cast->transform.x = sp_cast->inv_det * (raycast->dir.y * \
		sp_cast->sp_pos.x - raycast->dir.x * sp_cast->sp_pos.y);
	sp_cast->transform.y = sp_cast->inv_det * (-raycast->plane.y * \
		sp_cast->sp_pos.x + raycast->plane.x * sp_cast->sp_pos.y);
	sp_cast->sp_sc_x = (int)((WIN_W / 2) * (1 + sp_cast->transform.x / \
		sp_cast->transform.y));
	sp_cast->size_factor = WIN_H / sp_cast->transform.y;
	sp_cast->sp_h = (int)sp_cast->size_factor;
	sp_cast->sp_w = (int)sp_cast->size_factor;
	sp_cast->sp_start_y =  -sp_cast->sp_h / 2 + WIN_H / 2;
}

void	darw_sp(t_data *data, t_sp_cast *sp_cast,
			t_raycast *raycast, t_thing *thing_curr)
{
	int		y;
	t_color	color;

	y = 0;
	while (sp_cast->stripe < sp_cast->sp_end_x)
	{
		sp_cast->tex_x = (int)(sp_cast->tex_step_x * (sp_cast->stripe - (sp_cast->sp_sc_x - sp_cast->sp_w / 2)));
		if (sp_cast->transform.y > 0 && sp_cast->stripe > 0 && sp_cast->stripe <= WIN_W && sp_cast->transform.y < raycast->z_buffer[sp_cast->stripe])
		{
			sp_cast->tex_pos = (sp_cast->sp_start_y - WIN_H/2 + sp_cast->sp_h/2) * sp_cast->tex_step_y;
			y = sp_cast->sp_start_y;
			while (y < sp_cast->sp_end_y)
			{
				sp_cast->b_factor = (y) * 256 - WIN_H * 128 + sp_cast->sp_h * 128;
				sp_cast->tex_y = (int)sp_cast->tex_pos;
				color = get_pixel((*thing_curr->texture), sp_cast->tex_x, sp_cast->tex_y);
				if (color != NONE_COLOR_XPM)
					set_pixel(data->screen_img, sp_cast->stripe, y, color);
				sp_cast->tex_pos += sp_cast->tex_step_y;
				y++;
			}
		}
		sp_cast->stripe++;
	}
}

void	sp_casting(t_data *data, t_raycast *raycast)
{
	int	i;
	t_thing *thing_curr;
	t_sp_cast	sp_cast;

	sort_sp(data, *raycast);
	i = 0;
	while (i < data->nb_thing)
	{
		thing_curr = get_thing_by_id(data->thing_list, data->sp_order[i]);
		init_sp_cast(&sp_cast, raycast, thing_curr);
		init_sp_cast_2(&sp_cast);
		sp_cast.tex_step_x = (double)(*thing_curr->texture)->size_x / sp_cast.sp_w;
		sp_cast.tex_step_y = (double)(*thing_curr->texture)->size_y / sp_cast.sp_h;
		sp_cast.tex_pos = (sp_cast.sp_start_y - WIN_H/2 + sp_cast.sp_h/2) * sp_cast.tex_step_y;
		darw_sp(data, &sp_cast, raycast, thing_curr);
		i++;
	}
}

