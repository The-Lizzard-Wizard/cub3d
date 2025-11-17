/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:36:00 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/17 12:38:53 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdlib.h>

int	update(t_data *data)
{
	t_vec2	next_move;

	next_move = data->player.pos;
	move(data, &next_move);
	if (data->game_state.toggle_collide == 1)
	{
		if (collide(data, next_move, 1) == 0)
			data->player.pos.x = next_move.x;
		if (collide(data, next_move, 2) == 0)
			data->player.pos.y = next_move.y;
	}
	else
		data->player.pos = next_move;
	render(data);
	return (EXIT_SUCCESS);
}
