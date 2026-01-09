/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:25:34 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/09 17:20:37 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MATH_H
# define CUB_MATH_H

# include "cub3d.h"

# define PI 3.14159

double	deg_to_rad(double deg);
int		extract_decimal(double dec);
t_vec2	vect_rot(t_vec2 vec, double angle);

#endif