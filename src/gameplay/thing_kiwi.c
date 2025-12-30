/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thing_kiwi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:53:54 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/30 14:00:45 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/define.h"
#include "../../inc/cub_math.h"

void	take_chicken(t_data *data, t_thing *kiwi)
{
	kiwi->del = 1;
	data->player.kiwi++;
}