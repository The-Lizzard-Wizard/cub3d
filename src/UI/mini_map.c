/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:58:38 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/06 15:37:57 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../../inc/cub3d.h"

int	init_mini_map(t_data *data)
{
	data->map.width = get_long_line_in_array(data->map.grid);
	data->map.height = get_tablen(data->map.grid);
	data->ui.minimap_img = new_img(data, data->map.width, data->map.height);
	return (EXIT_SUCCESS);
}
