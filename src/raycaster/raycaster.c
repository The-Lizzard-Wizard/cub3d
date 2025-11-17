/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:51:43 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/14 15:54:35 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "math.h"

void draw_line(t_data *data, int x, int line_height, int wall_side)
{
    int y = 0;
    t_color wall_color;

    if (wall_side == 0)
        wall_color = rgba_to_int_color(255, 0, 255, 0);
    else
        wall_color = rgba_to_int_color(0, 255, 255, 0);
    while(y < WIN_H)
    {
        if (y < (WIN_H / 2 - line_height / 2))
            set_pixel(data->screen_img, x, y, data->ceiling_color);
        else if (y > (WIN_H / 2 + line_height / 2))
            set_pixel(data->screen_img, x, y, data->floor_color);
        else
            set_pixel(data->screen_img, x, y, wall_color);
        y++;
    }
}

void	raycaster(t_data *data)
{
    t_vec2 pos; // player coordinates
    t_vec2 dir; // player view angle, where he he's looking
    t_vec2 plane; // view plane, normal vector to dir

    // init const

    pos = data->player.pos;
    dir = data->player.view_angle;
    plane = data->player.camera_plane;

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
            next_step_size.x = fabs(1 / ray_dir.x);
        if (ray_dir.y == 0)
            next_step_size.y = 1e30;
        else
            next_step_size.y = fabs(1 / ray_dir.y);
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
            if (map.x >= (int)data->map.width || map.x < 0 || map.y >= (int)data->map.height || map.y < 0)
                break;
            else if (data->map.grid[map.y][map.x] == '1')
                is_hit = 1;
        }
        int line_height;
        if (is_hit)
        {
            // now calculate the distance to the wall from the plane
            if (wall_side == 0)
                dist_to_plane = dist_to_side.x - next_step_size.x;
            else
                dist_to_plane = dist_to_side.y - next_step_size.y;
            line_height = WIN_H / dist_to_plane;
        }
        else
            line_height = 0;
        // le trait a dessiner c'est la hauteur de la window divisé par la distance au plan, la suite c'est de l'affichage
        draw_line(data, x, line_height, wall_side);
        x++;
    }
}


