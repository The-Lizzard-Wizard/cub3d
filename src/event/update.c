/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:36:00 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/11 15:07:57 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdlib.h>

int	update(t_data *data)
{
	data->player.pos.x += 0.001;
	//data->player.pos.y -= 0.001;
	render(data);
	return (EXIT_SUCCESS);
}