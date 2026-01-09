/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:25:19 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/09 17:01:35 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_out_of_bounds(t_data *data)
{
	if (data->player.pos.x <= 0 || data->player.pos.y <= 0
		|| data->player.pos.x > (double)data->map.width
		|| data->player.pos.y > (double)data->map.height)
	{
		return (1);
	}
	return (0);
}
