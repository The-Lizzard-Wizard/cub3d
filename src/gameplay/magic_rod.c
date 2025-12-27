/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_rod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:56:45 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/27 15:38:37 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/define.h"

void	take_magic_rod(t_data *data, t_thing *rod)
{
	data->player.magic_rod = 1;
	rod->del = 1;
}

void	bullet_life(t_data *data, t_thing *bullet_thing)
{
	if (bullet_thing->pos.x < 0 || bullet_thing->pos.y < 0 ||
			(int)bullet_thing->pos.x >= (int)data->map.width ||
			(int)bullet_thing->pos.y >= (int)data->map.height)
	{
		bullet_thing->del = 1;
		return ;
	}
	else if (data->map.grid[(int)bullet_thing->pos.y][(int)bullet_thing->pos.x] == '1')
		bullet_thing->del = 1;
}

int	shoot(t_data *data)
{
	t_thing	*bullet;
	t_vec2	spawn_pos;

	spawn_pos.x = data->player.pos.x + (data->player.view_angle.x / 2);
	spawn_pos.y = data->player.pos.y + (data->player.view_angle.y / 2);
	bullet = add_thing(data, &data->textures.anime_tex_magic_shoot->img_curr, spawn_pos, THING_BULLET);
	bullet->vel.x = data->player.view_angle.x / 5;
	bullet->vel.y = data->player.view_angle.y / 5;
	return (EXIT_SUCCESS);
}