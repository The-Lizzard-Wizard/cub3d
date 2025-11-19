/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:20:43 by authomas          #+#    #+#             */
/*   Updated: 2025/11/18 14:39:52 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void draw_line(t_data *data, int x, int line_height, t_raycast raycast)
{
    int y = 0;
    // double perp_dist_to_wall;
    // double wall_coordinate;
    t_color wall_color;

    if (raycast.wall_face == 'N')
    {
    //     perp_dist_to_wall = (raycast.dist_to_side.y - raycast.next_step_size.y);
    //     wall_coordinate = raycast.pos.y + perp_dist_to_wall * raycast.ray_dir.y;
        wall_color = rgba_to_int_color(255, 0, 0, 0);
    }
    else if (raycast.wall_face == 'S')
        wall_color = rgba_to_int_color(0, 255, 0, 0);
    else if (raycast.wall_face == 'W')
        wall_color = rgba_to_int_color(0, 0, 255, 0);
    else if (raycast.wall_face == 'E')
        wall_color = rgba_to_int_color(255, 0, 255, 0);
    else
    {
        // perp_dist_to_wall = (raycast.dist_to_side.x - raycast.next_step_size.x);
        // wall_coordinate = raycast.pos.x + perp_dist_to_wall * raycast.ray_dir.x;
        wall_color = rgba_to_int_color(0, 255, 255, 0);
    }
     
    while(y < WIN_H)
    {
        if (y <= (WIN_H / 2 - line_height / 2))
            set_pixel(data->screen_img, x, y, data->ceiling_color);
        else if (y > (WIN_H / 2 + line_height / 2))
            set_pixel(data->screen_img, x, y, data->floor_color);
        else
            set_pixel(data->screen_img, x, y, wall_color);
        y++;
    }
}