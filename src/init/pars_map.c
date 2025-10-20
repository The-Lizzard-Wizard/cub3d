/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:05:15 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/20 13:48:40 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../../libft/libft.h"
#include "../../minilibx-linux/mlx.h"
#include "../../inc/cub3d.h"

int	pars_textures(t_data *data, int map_fd)
{
	char	*line;
	int		with;
	int		height;

	with = TEXTURE_W;
	height = TEXTURE_H;
	line = get_next_line(map_fd);
	if (!line)
		return (EXIT_FAILURE);
	data->textures.tex_north = mlx_xpm_file_to_image(data->mlx_ptr, line + 3, &with, &height);
	free(line);
	line = get_next_line(map_fd);
	if (!line)
		return (EXIT_FAILURE);
	data->textures.tex_east = mlx_xpm_file_to_image(data->mlx_ptr, line + 3, &with, &height);
	free(line);
	line = get_next_line(map_fd);
	if (!line)
		return (EXIT_FAILURE);
	data->textures.tex_west = mlx_xpm_file_to_image(data->mlx_ptr, line + 3, &with, &height);
	free(line);
	line = get_next_line(map_fd);
	if (!line)
		return (EXIT_FAILURE);
	data->textures.tex_east = mlx_xpm_file_to_image(data->mlx_ptr, line + 3, &with, &height);
	free(line);
	return (EXIT_SUCCESS);
}

int	pars_map(t_data *data, char **argv)
{
	char	*map_str;
	int		map_fd;

	(void)map_str;
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		return (EXIT_FAILURE);
	if (pars_textures(data, map_fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}