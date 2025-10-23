/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:00:51 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/23 17:42:12 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdlib.h>

void	render(t_data *data)
{
	// t_modify mod;
	// mod.x = 0;
	// mod.y = 0;
	// mod.sc_x = 100;
	// mod.sc_y = 2;
	// mod.quad_x = 16;
	// mod.quad_y = 16;
	// mod.quad_sx = 16;
	// mod.quad_sy = 16;
	// draw_img_on_img(data->screen_img, data->rnd_img, mod);
	draw_img(data, data->screen_img, 0, 0);
}
