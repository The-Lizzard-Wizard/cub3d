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
#include <math.h>

void draw_line(t_data *data, int x, int line_height, t_raycast raycast)
{
    int y = 0;
    double wall_coordinate;
    double step = 0;
    double tex_pos = 0;
    int tex_x = 0;
    int tex_y = 0;
    t_color wall_color;

    if (line_height < 0)
        line_height = WIN_H * data->textures.tex_north->size_y;
    int draw_start = (WIN_H / 2 - line_height / 2);
    int draw_end = (WIN_H / 2 + line_height / 2);
    if (raycast.side == 0)
    {
        wall_coordinate = raycast.pos.y + raycast.dist_to_plane * raycast.ray_dir.y;
        wall_coordinate -= floor(wall_coordinate);   
    }
    else
    {
        wall_coordinate = raycast.pos.x + raycast.dist_to_plane * raycast.ray_dir.x;
        wall_coordinate -= floor(wall_coordinate);
    }
    if (raycast.wall_face == 'N')
    {
        tex_x = wall_coordinate * data->textures.tex_north->size_x;
        tex_x = data->textures.tex_west->size_x - tex_x - 1;
        step = 1.0 * data->textures.tex_north->size_y / line_height;
        tex_pos = (draw_start + line_height / 2 - WIN_H / 2) * step;
    }
    else if (raycast.wall_face == 'S')
    {
        tex_x = wall_coordinate * data->textures.tex_south->size_x;
        step = 1.0 * data->textures.tex_south->size_y / line_height;
        tex_pos = (draw_start + line_height / 2 - WIN_H / 2) * step;
    }
    else if (raycast.wall_face == 'W')
    {
        tex_x = wall_coordinate * data->textures.tex_west->size_x;
        step = 1.0 * data->textures.tex_west->size_y / line_height;
        tex_pos = (draw_start + line_height / 2 - WIN_H / 2) * step;
    }
    else if (raycast.wall_face == 'E')
    {
        tex_x = wall_coordinate * data->textures.tex_east->size_x;
        tex_x = data->textures.tex_west->size_x - tex_x - 1;
        step = 1.0 * data->textures.tex_east->size_y / line_height;
        tex_pos = (draw_start + line_height / 2 - WIN_H /2) * step;
    }
    while (y <= draw_start)
    {
        set_pixel(data->screen_img, x, y, data->ceiling_color);
        y++;
    }
    if (draw_start < 0)
        tex_pos += step * (-draw_start);
    while(y < draw_end)
    {
        if (y > WIN_H)
            break ;
        if (raycast.wall_face == 'N')
        {
            tex_y = (int)tex_pos & (data->textures.tex_north->size_y - 1);
            wall_color = get_pixel(data->textures.tex_north, tex_x, tex_y);
            tex_pos += step;
        }
        else if (raycast.wall_face == 'S')
        {
            tex_y = (int)tex_pos & (data->textures.tex_south->size_y - 1);
            wall_color = get_pixel(data->textures.tex_south, tex_x, tex_y);
            tex_pos += step;
        }
        else if (raycast.wall_face == 'W')
        {
            tex_y = (int)tex_pos & (data->textures.tex_west->size_y - 1);
            wall_color = get_pixel(data->textures.tex_west, tex_x, tex_y);
            tex_pos += step;
        }
        else if (raycast.wall_face == 'E')
        {
            tex_y = (int)tex_pos & (data->textures.tex_east->size_y - 1);
            wall_color = get_pixel(data->textures.tex_east, tex_x, tex_y);
            tex_pos += step;
        }
        else
            wall_color = rgba_to_int_color(0, 255, 255, 0);
        set_pixel(data->screen_img, x, y, wall_color);
        y++;
    }
    while(y < WIN_H)
    {
        set_pixel(data->screen_img, x, y, data->floor_color);
        y++;
    }
}
