/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:00:51 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/27 13:10:25 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdlib.h>

void	render(t_data *data)
{
	t_modify mod;
	mod.x = 0;
	mod.y = 0;
	mod.quad_x = 0;
	mod.quad_y = 0;
	mod.quad_sx = 0;
	mod.quad_sy = 0;
	mod.text_space = 12;
	mod.sc_x = 2;
	mod.sc_y = 3;
	mod.x = 0;
	put_text_on_img(data->screen_img, data->rnd_img,
		"ELECTRIC wizard\n-Dopethrone-\n\
1 - Vinum Sabbathi\n\
2 - Funeralopolis\n\
3 - Weird Tales-Electric Frost/Golgotha/Altar of Melektaus\n\
4 - Barbariann\n\
5 - I, The Witchfinder\n\
6 - The Hills Have Eyes\n\
7 - We Hate You\n\
8 - Dopethrone\n\
9 - Mind Transferal", mod);
	draw_img(data, data->screen_img, 0, 0);
}
