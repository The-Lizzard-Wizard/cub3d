/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:56:45 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/15 14:23:45 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/define.h"

void	bullet_life(t_data *data, t_thing *bullet_thing)
{
	if (bullet_thing->pos.x < 0 && bullet_thing->pos.y < 0 &&
			bullet_thing->pos.x > data->map.width &&
			bullet_thing->pos.y > data->map.height)
		bullet_thing->del = 1;
	if (data->map.grid[(int)bullet_thing->pos.y][(int)bullet_thing->pos.x] == '1')
		bullet_thing->del = 1;
}

int	shoot(t_data *data)
{
	t_thing	*bullet;
	bullet = add_thing(data, data->textures.tex_magic_shoot, data->player.pos, THING_BULLET);
	bullet->vel.x = data->player.view_angle.x / 5;
	bullet->vel.y = data->player.view_angle.y / 5;
	return (EXIT_SUCCESS);
}