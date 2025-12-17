/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thing_banana.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:45:08 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/17 15:47:59 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/define.h"

void	take_banana(t_data *data, t_thing *banana)
{
	data->player.banana++;
	banana->del = 1;
}
