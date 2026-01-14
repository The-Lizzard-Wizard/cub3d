/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_rod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:56:45 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/14 16:20:10 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/define.h"

void	take_magic_rod(t_data *data, t_thing *rod)
{
	data->player.magic_rod = 1;
	rod->del = 1;
}

void	destroy_kiwi(t_data *data, t_thing *bull)
{
	t_thing	*curr_thing;
	t_thing	*next_thing;

	if (!data->thing_list)
		return ;
	next_thing = NULL;
	curr_thing = data->thing_list;
	while (curr_thing != NULL)
	{
		if (bull->pos.x >= curr_thing->pos.x - (THING_BOX_W * 2) / 2
			&& bull->pos.x <= curr_thing->pos.x + (THING_BOX_W * 2) / 2
			&& bull->pos.y >= curr_thing->pos.y - (THING_BOX_H * 2) / 2
			&& bull->pos.y <= curr_thing->pos.y + (THING_BOX_H * 2) / 2)
		{
			if (curr_thing->type == THING_KIWI)
			{
				add_thing(data, &data->textures.tex_chicken,
					curr_thing->pos, THING_CHICKEN);
				curr_thing->del = 1;
				bull->del = 1;
			}
		}
		curr_thing = curr_thing->next;
	}
}

void	bullet_life(t_data *data, t_thing *bull)
{
	destroy_kiwi(data, bull);
	if (bull->pos.x < 0 || bull->pos.y < 0
		|| (int)bull->pos.x >= (int)data->map.width
		|| (int)bull->pos.y >= (int)data->map.height)
	{
		bull->del = 1;
		return ;
	}
	else if (data->map.grid[(int)bull->pos.y][(int)bull->pos.x] == '1')
		bull->del = 1;
}

int	shoot(t_data *data)
{
	t_thing	*bullet;
	t_vec2	spawn_pos;

	spawn_pos.x = data->player.pos.x + (data->player.view_angle.x / 2);
	spawn_pos.y = data->player.pos.y + (data->player.view_angle.y / 2);
	bullet = add_thing(data, &data->textures.anime_tex_magic_shoot->img_curr,
			spawn_pos, THING_BULLET);
	if (!bullet)
		return (EXIT_FAILURE);
	bullet->vel.x = data->player.view_angle.x / 5;
	bullet->vel.y = data->player.view_angle.y / 5;
	return (EXIT_SUCCESS);
}
