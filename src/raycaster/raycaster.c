/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:51:43 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/19 17:34:23 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "math.h"

char	map_square_finder(t_data *data, int x, int y)
{
	if (x >= (int)data->map.width || x < 0
		|| y >= (int)data->map.height || y < 0)
		return ('0');
	return (data->map.grid[y][x]);
}

void	wall_hit(t_data *data, t_raycast *ray, int *is_hit)
{
	if (map_square_finder(data, ray->map.x, ray->map.y) == '1'
		|| map_square_finder(data, ray->map.x, ray->map.y) == 'Y'
		|| map_square_finder(data, ray->map.x, ray->map.y) == 'B'
		|| map_square_finder(data, ray->map.x, ray->map.y) == 'G'
		|| map_square_finder(data, ray->map.x, ray->map.y) == 'R'
		|| map_square_finder(data, ray->map.x, ray->map.y) == 'D')
		*is_hit = 1;
}

void	dda(t_raycast *raycast, int *is_hit, t_data *data)
{
	int	render_dist;

	render_dist = 0;
	*is_hit = 0;
	while (*is_hit == 0 && render_dist <= 100)
	{
		if (raycast->dist_to_side.x < raycast->dist_to_side.y)
		{
			raycast->dist_to_side.x += raycast->next_step_size.x;
			raycast->map.x += raycast->step_dir.x;
			raycast->side = 0;
		}
		else
		{
			raycast->dist_to_side.y += raycast->next_step_size.y;
			raycast->map.y += raycast->step_dir.y;
			raycast->side = 1;
		}
		wall_face_finder(raycast);
		wall_hit(data, raycast, is_hit);
		render_dist++;
	}
}

void	process_dist(t_raycast *raycast, int *line_height)
{
	if (raycast->side == 0)
		raycast->dist_to_plane = raycast->dist_to_side.x
			- raycast->next_step_size.x;
	else
		raycast->dist_to_plane = raycast->dist_to_side.y
			- raycast->next_step_size.y;
	*line_height = WIN_H / raycast->dist_to_plane + 1;
}

void	raycaster(t_data *data)
{
	t_raycast	raycast;
	int			x;
	int			is_hit;
	int			line_height;

	x = -1;
	ft_bzero(&raycast, sizeof(t_raycast));
	raycast_init_subs(&raycast, data);
	while (++x < WIN_W)
	{
		raycast.camera_pos = 2 * x / (double)WIN_W - 1;
		raycast_init_x(&raycast);
		raycast_init_y(&raycast);
		dda(&raycast, &is_hit, data);
		if (is_hit)
			process_dist(&raycast, &line_height);
		else
			line_height = 0;
		draw_line(data, x, line_height, raycast);
		raycast.z_buffer[x] = raycast.dist_to_plane;
	}
	sp_casting(data, &raycast);
}
