/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprites_draw.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:20:37 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/05 13:10:24 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_sp_loop_y(t_data *data, t_sp_cast *sp_cast,
	int y, t_thing *thing_curr)
{
	t_color	color;

	color = 0;
	while (y < sp_cast->sp_end_y)
	{
		sp_cast->b_factor = y * 256 - WIN_H * 128 + sp_cast->sp_h * 128;
		sp_cast->tex_y = (int)sp_cast->tex_pos;
		color = get_pixel((*thing_curr->texture\
), sp_cast->tex_x, sp_cast->tex_y);
		if (color != NONE_COLOR_XPM)
			set_pixel(data->screen_img, sp_cast->stripe, y, color);
		sp_cast->tex_pos += sp_cast->tex_step_y;
		y++;
	}
}

void	draw_sp(t_data *data, t_sp_cast *sp_cast,
			t_raycast *raycast, t_thing *thing_curr)
{
	int		y;

	y = 0;
	while (sp_cast->stripe < sp_cast->sp_end_x)
	{
		sp_cast->tex_x = (int)(sp_cast->tex_step_x * (\
sp_cast->stripe - (sp_cast->sp_sc_x - sp_cast->sp_w / 2)));
		if (sp_cast->transform.y > 0
			&& sp_cast->stripe > 0 && sp_cast->stripe <= WIN_W
			&& sp_cast->transform.y < raycast->z_buffer[sp_cast->stripe])
		{
			sp_cast->tex_pos = (\
sp_cast->sp_start_y - WIN_H / 2 + sp_cast->sp_h / 2) * sp_cast->tex_step_y;
			y = sp_cast->sp_start_y;
			draw_sp_loop_y(data, sp_cast, y, thing_curr);
		}
		sp_cast->stripe++;
	}
}
