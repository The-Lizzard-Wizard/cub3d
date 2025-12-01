/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:51:43 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/01 10:41:47 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "math.h"

void raycast_init_subs(t_raycast *raycast, t_data *data)
{
    raycast->pos = data->player.pos;
    raycast->dir = data->player.view_angle;
    raycast->plane = data->player.camera_plane;
}

void raycast_init_x(t_raycast *raycast)
{
    raycast->ray_dir.x = raycast->dir.x + raycast->plane.x * raycast->camera_pos;
    raycast->map.x = (int)raycast->pos.x;
    if (raycast->ray_dir.x == 0)
        raycast->next_step_size.x = 1e30;
    else
        raycast->next_step_size.x = fabs(1 / raycast->ray_dir.x);
    if (raycast->ray_dir.x < 0)
    {
        raycast->step_dir.x = -1;
        raycast->dist_to_side.x = (raycast->pos.x - raycast->map.x) * raycast->next_step_size.x;
    }
    else
    {
        raycast->step_dir.x = 1;
        raycast->dist_to_side.x = (raycast->map.x + 1 - raycast->pos.x) * raycast->next_step_size.x;
    }
}

void raycast_init_y(t_raycast *raycast)
{
    raycast->ray_dir.y = raycast->dir.y + raycast->plane.y * raycast->camera_pos;
    raycast->map.y = (int)raycast->pos.y;
    if (raycast->ray_dir.y == 0)
        raycast->next_step_size.y = 1e30;
    else
        raycast->next_step_size.y = fabs(1 / raycast->ray_dir.y);
    if (raycast->ray_dir.y < 0)
    {
        raycast->step_dir.y = -1;
        raycast->dist_to_side.y= (raycast->pos.y - raycast->map.y) * raycast->next_step_size.y;
    }
    else
    {
        raycast->step_dir.y = 1;
        raycast->dist_to_side.y = (raycast->map.y + 1 - raycast->pos.y) * raycast->next_step_size.y;
    }
}

void wall_face_finder(t_raycast *raycast)
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

void dda(t_raycast *raycast, int *is_hit, t_data *data)
{
    *is_hit = 0;
    while (*is_hit == 0)
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
        if (raycast->map.x >= (int)data->map.width || raycast->map.x < 0 || raycast->map.y >= (int)data->map.height || raycast->map.y < 0)
            return ;
        else if (data->map.grid[raycast->map.y][raycast->map.x] == '1' || data->map.grid[raycast->map.y][raycast->map.x] == 'Y')
            *is_hit = 1;
    }
}



void	raycaster(t_data *data)
{
    t_raycast raycast;
    int x;
    int is_hit;// is the wall hit? very explicit
    int line_height;

    x = -1;
    raycast_init_subs(&raycast, data);
    while (++x < WIN_W)
    {
        raycast.camera_pos = 2 * x / (double)WIN_W - 1; // x coordinate of the ray in the "camera"
        raycast_init_x(&raycast);
        raycast_init_y(&raycast);
        dda(&raycast, &is_hit, data);
        if (is_hit)
        {
            if (raycast.side == 0)
                raycast.dist_to_plane = raycast.dist_to_side.x - raycast.next_step_size.x;
            else
                raycast.dist_to_plane = raycast.dist_to_side.y - raycast.next_step_size.y;
            line_height = WIN_H / raycast.dist_to_plane + 1;
        }
        else
            line_height = 0;
        draw_line(data, x, line_height, raycast);
    }
}


