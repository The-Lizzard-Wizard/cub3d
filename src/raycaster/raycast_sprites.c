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
	sp_cast->inv_det = 1.0 / (raycast->plane.x * raycast->dir.y
			- raycast->dir.x * raycast->plane.y);
	sp_cast->transform.x = sp_cast->inv_det * (raycast->dir.y
			* sp_cast->sp_pos.x - raycast->dir.x * sp_cast->sp_pos.y);
	sp_cast->transform.y = sp_cast->inv_det * (-raycast->plane.y
			* sp_cast->sp_pos.x + raycast->plane.x * sp_cast->sp_pos.y);
	sp_cast->sp_sc_x = (int)((WIN_W / 2)
			* (1 + sp_cast->transform.x / sp_cast->transform.y));
	sp_cast->size_factor = WIN_H / sp_cast->transform.y;
	if (sp_cast->size_factor == INFINITY)
		sp_cast->size_factor = 0;
	sp_cast->sp_h = (int)sp_cast->size_factor;
	sp_cast->sp_w = (int)sp_cast->size_factor;
	sp_cast->sp_start_y = -sp_cast->sp_h / 2 + WIN_H / 2;
}

void	sp_casting(t_data *data, t_raycast *raycast)
{
	int			i;
	t_thing		*thing_curr;
	t_sp_cast	sp_cast;

	sort_sp(data, *raycast);
	i = 0;
	while (i < data->nb_thing)
	{
		thing_curr = get_thing_by_id(data->thing_list, data->sp_order[i]);
		init_sp_cast(&sp_cast, raycast, thing_curr);
		init_sp_cast_2(&sp_cast);
		sp_cast.tex_step_x = (double)(*thing_curr->texture)->size_x
			/ sp_cast.sp_w;
		sp_cast.tex_step_y = (double)(*thing_curr->texture)->size_y
			/ sp_cast.sp_h;
		sp_cast.tex_pos = (sp_cast.sp_start_y - WIN_H / 2 + sp_cast.sp_h / 2)
			* sp_cast.tex_step_y;
		draw_sp(data, &sp_cast, raycast, thing_curr);
		i++;
	}
}
