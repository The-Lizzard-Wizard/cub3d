/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:27:02 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/05 17:06:14 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub_math.h"
#include <math.h>
#include "../../inc/cub3d.h"

double	deg_to_rad(double deg)
{
	return (deg * PI / 180.);
}

t_vec2 vect_rot(t_vec2 vec, double angle)
{
	t_vec2 new_vec;

	new_vec.x = sin(angle);
	new_vec.y = cos(angle);
}



