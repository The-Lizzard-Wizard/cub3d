/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:51:43 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/13 13:41:30 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "math.h"

void	raycaster(t_data *data)
{
    t_int_pos2 pos; // player coordinates
    t_vec2 dir; // player view angle, where he he's looking
    t_vec2 plane; // view plane, normal vector to dir

    // init const

    pos.x = (int)data->player.pos.x;
    pos.y = (int)data->player.pos.y;
    dir = data->player.view_angle;
    plane.x = 0;
    plane.y = 0.66;

    while(1)
    {
        int x = 0;
        t_vec2 ray_dir; // ray direction vector
        t_vec2 dist_to_side; // the distance from the player to the first x side/y side (rn it's the first step)
        t_vec2 next_step_size; // the distance from the x side / y side to the next one
        t_int_pos2 map; // the square of the map the ray is in
        double dist_to_plane; // distance of the wall to the plane
        while (x < WIN_W)
        {
            //init not const
            double camera_pos = 2 * x / (double)WIN_W - 1; // x coordinate of the ray in the "camera"
            ray_dir.x = dir.x + plane.x * camera_pos;
            ray_dir.y = dir.y + plane.y * camera_pos;
            map.x = (int)pos.x;
            map.y = (int)pos.y;
            if (ray_dir.x == 0)
                next_step_size.x = 1e30;
            else
                next_step_size.x = abs(1 / ray_dir.x);
            if (ray_dir.y == 0)
                next_step_size.y = 1e30;
            else
                next_step_size.y = abs(1 / ray_dir.y);
            t_vec2 step_dir; // the direction of the next step of the ray
            int is_hit = 0; // is the wall hit? very explicit
            int wall_side; // which wall was hit? very explicit too
            if (ray_dir.x < 0)
            {
                step_dir.x = -1;
                dist_to_side.x = (pos.x - map.x) * next_step_size.x;
            }
            else
            {
                step_dir.x = 1;
                dist_to_side.x = (map.x + 1 - pos.x) * next_step_size.x;
            }
            if (ray_dir.y < 0)
            {
                step_dir.y = -1;
                dist_to_side.y = (pos.y - map.y) * next_step_size.y;
            }
            else
            {
                step_dir.y = 1;
                dist_to_side.y = (map.y + 1 - pos.y) * next_step_size.y;
            }
            // actual DDA part
            while (is_hit == 0)
            {
                if (dist_to_side.x < dist_to_side.y)
                {
                    dist_to_side.x += next_step_size.x;
                    map.x += step_dir.x;
                    wall_side = 0;
                }
                else
                {
                    dist_to_side.y += next_step_size.y;
                    map.y += step_dir.y;
                    wall_side = 1;
                }
                if (data->map.grid[map.x][map.y] == '1')
                    is_hit = 1;
            }
            // now calculate the distance to the wall from the plane
            if (wall_side == 0)
                dist_to_plane = dist_to_side.x - next_step_size.x;
            else
                dist_to_plane = dist_to_side.y - next_step_size.y;

            // le trait a dessiner c'est la hauteur de la window divisé par la distance au plan, la suite c'est de l'affichage
            x++;
        }
    }
}