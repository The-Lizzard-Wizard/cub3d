/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:51:43 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/06 17:25:43 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	raycaster(t_data *data)
{
    t_int_pos2 map_pos;

    t_vec2 dist_to_side;
    t_vec2 next_step_size;

    map_pos.x = (int)data->player.pos_x;
    map_pos.y = (int)data->player.pos_y;

    
}