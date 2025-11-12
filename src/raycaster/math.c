/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:27:02 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/12 14:37:08 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub_math.h"
#include <math.h>
#include "../../inc/cub3d.h"

double	deg_to_rad(double deg)
{
	return (deg * PI / 180.);
}

int		extract_decimal(double dec)
{
	int	res;

	res = (int)((dec - (int)dec) * 100);
	return (res);
}

t_vec2 vect_rot(t_vec2 vec, double angle)
{
	t_vec2 new_vec;

	new_vec.x = vec.x * cos(angle) - sin(angle) * vec.y;
	new_vec.y = vec.x * sin(angle) + cos(angle) * vec.y;
	return (new_vec);
}



