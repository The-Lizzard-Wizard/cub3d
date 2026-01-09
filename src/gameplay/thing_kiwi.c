/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thing_kiwi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:53:54 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/09 13:57:27 by authomas         ###   ########lyon.fr   */
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
