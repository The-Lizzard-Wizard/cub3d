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

void init_wall_coordinate(t_raycast *raycast)
{
    if (raycast->side == 0)
    {
        raycast->wall_coordinate = raycast->pos.y + raycast->dist_to_plane * raycast->ray_dir.y;
        raycast->wall_coordinate -= floor(raycast->wall_coordinate);   
    }
    else
    {
        raycast->wall_coordinate = raycast->pos.x + raycast->dist_to_plane * raycast->ray_dir.x;
        raycast->wall_coordinate -= floor(raycast->wall_coordinate);
    }
}

void texture_finder(t_data *data, t_raycast raycast, t_cub_img **texture)
{
    if (raycast.wall_face == 'N')
        *texture = data->textures.tex_north;
    else if (raycast.wall_face == 'S')
        *texture = data->textures.tex_south;
    else if (raycast.wall_face == 'E')
        *texture = data->textures.tex_east;
    else
        *texture = data->textures.tex_west;
}

void draw_line(t_data *data, int x, int line_height, t_raycast raycast)
{
    int y;
    t_color wall_color;
    t_cub_img *texture;
    int draw_start;
    int draw_end;

    texture_finder(data, raycast, &texture);
    if (line_height < 0)
        line_height = WIN_H * texture->size_y;
    draw_start = (WIN_H / 2 - line_height / 2);
    draw_end = (WIN_H / 2 + line_height / 2);
    init_wall_coordinate(&raycast);
    if (raycast.wall_face == 'N' || raycast.wall_face == 'E')
    {
        raycast.tex_x = raycast.wall_coordinate * texture->size_x;
        raycast.tex_x = texture->size_x - raycast.tex_x - 1;
        raycast.step = 1.0 * texture->size_y / line_height;
        raycast.tex_pos = (draw_start + line_height / 2 - WIN_H / 2) *raycast.step;
    }
    else
    {
        raycast.tex_x = raycast.wall_coordinate * texture->size_x;
        raycast.step = 1.0 * texture->size_y / line_height;
        raycast.tex_pos = (draw_start + line_height / 2 - WIN_H / 2) * raycast.step;
    }
    y = 0;
    while (y <= draw_start)
    {
        set_pixel(data->screen_img, x, y, data->ceiling_color);
        y++;
    }
    if (draw_start < 0)
        raycast.tex_pos += raycast.step * (-draw_start);
    while(y < draw_end)
    {
        if (y > WIN_H)
            break ;
        raycast.tex_y = (int)raycast.tex_pos & (texture->size_y - 1);
        wall_color = get_pixel(texture, raycast.tex_x, raycast.tex_y);
        raycast.tex_pos += raycast.step;
        set_pixel(data->screen_img, x, y, wall_color);
        y++;
    }
    while(y < WIN_H)
    {
        set_pixel(data->screen_img, x, y, data->floor_color);
        y++;
    }
}
