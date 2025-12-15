/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thing_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:25:35 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/15 13:48:40 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	take_y_key(t_data *data, t_thing *to_del)
{
	to_del->del = 1;
	data->player.yellow_key = 1;
}

void	take_b_key(t_data *data, t_thing *to_del)
{
	to_del->del = 1;
	data->player.blue_key = 1;
}

void	take_g_key(t_data *data, t_thing *to_del)
{
	to_del->del = 1;
	data->player.green_key = 1;
}

void	take_r_key(t_data *data, t_thing *to_del)
{
	to_del->del = 1;
	data->player.red_key = 1;
}