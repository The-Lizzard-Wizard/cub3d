/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:53:32 by authomas          #+#    #+#             */
/*   Updated: 2026/01/09 16:55:28 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "math.h"

void	raycast_init_subs(t_raycast *raycast, t_data *data)
{
	raycast->pos = data->player.pos;
	raycast->dir = data->player.view_angle;
	raycast->plane = data->player.camera_plane;
	raycast->step = 0;
	raycast->tex_pos = 0;
	raycast->tex_x = 0;
	raycast->tex_y = 0;
}

void	raycast_init_x(t_raycast *raycast)
{
	raycast->ray_dir.x = raycast->dir.x + raycast->plane.x
		* raycast->camera_pos;
	raycast->map.x = floor(raycast->pos.x);
	if (raycast->ray_dir.x == 0)
		raycast->next_step_size.x = 1e30;
	else
		raycast->next_step_size.x = fabs(1 / raycast->ray_dir.x);
	if (raycast->ray_dir.x < 0)
	{
		raycast->step_dir.x = -1;
		raycast->dist_to_side.x = (raycast->pos.x - raycast->map.x)
			* raycast->next_step_size.x;
	}
	else
	{
		raycast->step_dir.x = 1;
		raycast->dist_to_side.x = (raycast->map.x + 1 - raycast->pos.x)
			* raycast->next_step_size.x;
	}
}

void	raycast_init_y(t_raycast *raycast)
{
	raycast->ray_dir.y = raycast->dir.y + raycast->plane.y
		* raycast->camera_pos;
	raycast->map.y = floor(raycast->pos.y);
	if (raycast->ray_dir.y == 0)
		raycast->next_step_size.y = 1e30;
	else
		raycast->next_step_size.y = fabs(1 / raycast->ray_dir.y);
	if (raycast->ray_dir.y < 0)
	{
		raycast->step_dir.y = -1;
		raycast->dist_to_side.y = (raycast->pos.y - raycast->map.y)
			* raycast->next_step_size.y;
	}
	else
	{
		raycast->step_dir.y = 1;
		raycast->dist_to_side.y = (raycast->map.y + 1 - raycast->pos.y)
			* raycast->next_step_size.y;
	}
}

void	wall_face_finder(t_raycast *raycast)
{
	if (raycast->side == 0 && raycast->ray_dir.x < 0)
		raycast->wall_face = 'E';
	else if (raycast->side == 0 && raycast->ray_dir.x > 0)
		raycast->wall_face = 'W';
	else if (raycast->side == 1 && raycast->ray_dir.y < 0)
		raycast->wall_face = 'S';
	else if (raycast->side == 1 && raycast->ray_dir.y > 0)
		raycast->wall_face = 'N';
}
