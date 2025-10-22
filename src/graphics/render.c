/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:00:51 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/22 15:52:40 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdlib.h>

void	render(t_data *data)
{
	// draw_img_on_img(data->screen_img, data->rnd_texture, 0, 0);
	// draw_img_on_img(data->screen_img, data->banana, 0, bx);
	//draw_img(data, data->banana, 0, 0);
	//set_pixel(data->screen_img, 10, 10, get_pixel(data->banana, 16, 16));
	draw_img(data, data->screen_img, 0, 0);
}