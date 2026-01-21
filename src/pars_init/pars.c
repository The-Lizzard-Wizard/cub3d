/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:03:47 by authomas          #+#    #+#             */
/*   Updated: 2026/01/21 14:45:05 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pars.h"

void	pars_init(t_pars *pars, t_data *data)
{
	pars->c_color_check = 0;
	pars->f_color_check = 0;
	ft_bzero(pars->tex_path_ea, PATH_MAX);
	ft_bzero(pars->tex_path_we, PATH_MAX);
	ft_bzero(pars->tex_path_no, PATH_MAX);
	ft_bzero(pars->tex_path_so, PATH_MAX);
	pars->ceiling_color = &data->ceiling_color;
	pars->floor_color = &data->floor_color;
	pars->map = NULL;
	pars->player = &data->player;
}

void	set_view_next(t_vec2 *p_view_angle, t_vec2 *p_plane, char player_view)
{
	if (player_view == 'W')
	{
		p_view_angle->x = -1;
		p_view_angle->y = 0;
		p_plane->x = 0;
		p_plane->y = -0.66;
	}
	if (player_view == 'E')
	{
		p_view_angle->x = 1;
		p_view_angle->y = 0;
		p_plane->x = 0;
		p_plane->y = 0.66;
	}
}

int	set_player_view(t_vec2 *p_view_angle, t_vec2 *p_plane, char player_view)
{
	if (player_view == 'N')
	{
		p_view_angle->x = 0;
		p_view_angle->y = -1;
		p_plane->x = 0.66;
		p_plane->y = 0;
	}
	if (player_view == 'S')
	{
		p_view_angle->x = 0;
		p_view_angle->y = 1;
		p_plane->x = -0.66;
		p_plane->y = 0;
	}
	set_view_next(p_view_angle, p_plane, player_view);
	return (EXIT_SUCCESS);
}

int	pars_to_data(t_data *data, t_pars *pars)
{
	data->map.width = get_long_line_in_array(pars->map);
	data->map.height = array_len(pars->map);
	data->map.grid = normalize_map(pars->map, data->map.width,
			data->map.height + 1);
	if (!data->map.grid)
	{
		print_error(ER_MALLOC_ER);
		return (EXIT_FAILURE);
	}
	data->textures.tex_east = new_xpm_img(data, pars->tex_path_ea);
	data->textures.tex_west = new_xpm_img(data, pars->tex_path_we);
	data->textures.tex_north = new_xpm_img(data, pars->tex_path_no);
	data->textures.tex_south = new_xpm_img(data, pars->tex_path_so);
	if (data->textures.tex_east == NULL
		|| data->textures.tex_west == NULL
		|| data->textures.tex_north == NULL
		|| data->textures.tex_south == NULL)
	{
		print_error(ER_INIT_TEX);
		return (EXIT_FAILURE);
	}
	set_player_view(&(data->player.view_angle),
		&(data->player.camera_plane), pars->player_view);
	return (EXIT_SUCCESS);
}

int	pars(t_data *data, char **argv)
{
	t_pars	pars;
	int		map_fd;

	pars_init(&pars, data);
	map_fd = open(argv[1], O_RDONLY);
	if (file_checking(argv[1]) == EXIT_FAILURE || map_fd == -1)
	{
		print_error(ER_WRONG_MAP_FILE);
		return (EXIT_FAILURE);
	}
	if (pars_textures(&pars, map_fd) == EXIT_FAILURE)
	{ 
		print_error(ER_MAP_NO_TEX_FOUND);
		return (EXIT_FAILURE);
	}
	if (pars_map(&pars, map_fd, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pars_to_data(data, &pars) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
