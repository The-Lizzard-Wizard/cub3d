/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:01:29 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/11 16:13:08 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_ui_img(t_data *data)
{
	if (!data->ui.player_img)
		return (EXIT_FAILURE);
	if (!data->ui.wall_img)
		return (EXIT_FAILURE);
	if (!data->ui.floor_img)
		return (EXIT_FAILURE);
	if (!data->ui.minimap_frame)
		return (EXIT_FAILURE);
	if (!data->ui.font)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_ui(t_data *data)
{
	data->ui.player_img = new_xpm_img(data, "textures/player.xpm");
	data->ui.wall_img = new_xpm_img(data, "textures/minimap_wall.xpm");
	data->ui.floor_img = new_xpm_img(data, "textures/minimap_floor.xpm");
	data->ui.minimap_frame = new_xpm_img(data, "textures/minimap_frame.xpm");
	data->ui.font = new_xpm_img(data, "textures/font.xpm");
	if (check_ui_img(data) == EXIT_FAILURE)
	{
		print_error(ER_INIT_UI_IMG);
		return (EXIT_FAILURE);
	}
	if (init_mini_map(data) == EXIT_FAILURE)
	{
		print_error(ER_INIT_UI_MIMP);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}