/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thing_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:25:35 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/03 16:52:00 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	take_y_key(t_data *data, t_thing *to_del)
{
	del_thing(data, to_del);
	data->player.yellow_key = 1;
}

void	take_b_key(t_data *data, t_thing *to_del)
{
	del_thing(data, to_del);
	data->player.blue_key = 1;
}

void	take_g_key(t_data *data, t_thing *to_del)
{
	del_thing(data, to_del);
	data->player.green_key = 1;
}

void	take_r_key(t_data *data, t_thing *to_del)
{
	del_thing(data, to_del);
	data->player.red_key = 1;
}