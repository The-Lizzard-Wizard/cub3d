/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:05:15 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/21 13:41:14 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../../libft/libft.h"
#include "../../minilibx-linux/mlx.h"
#include "../../inc/cub3d.h"


t_color rgba_to_int_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	t_color color;

	color = r << 24 + g << 16 + b << 8 + a;
	return (color);
}

void get_id(char *id, char *line)
{
	if (*line == 'F' && ft_isspace(*(line + 1)))
		*id = 'F';
	if (*line == 'C' && ft_isspace(*(line + 1)))
		*id = 'C';
	if (*line == 'N' && *(line + 1) == 'O' && ft_isspace(*(line + 2)))
		*id = 'N';
	if (*line == 'S' && *(line + 1) == 'O' && ft_isspace(*(line + 2)))
		*id = 'S';
	if (*line == 'E' && *(line + 1) == 'A' && ft_isspace(*(line + 2)))
		*id = 'E';
	if (*line == 'W' && *(line + 1) == 'E' && ft_isspace(*(line + 2)))
		*id = 'W';
}

void get_path_by_id(t_pars *pars, char *id, char *line)
{
	int i;

	i = 0;
	if (id == 'F' || id == 'C')
		//do stuff
		;
	while (!ft_isspace(line[i]))
		i++;
	if (id == 'N')
		ft_strlcpy(pars->tex_path_no, line, i);
	else if (id == 'S')
		ft_strlcpy(pars->tex_path_so, line, i);
	else if (id == 'E')
		ft_strlcpy(pars->tex_path_ea, line, i);
	else if (id == 'W')
		ft_strlcpy(pars->tex_path_we, line, i);
}

int check_tex_line(t_pars *pars, char *line)
{
	int i;
	char id;
	
	i = 0;
	id = 0;
	if (!line || *line == '\n')
		return (EXIT_FAILURE);
	while (ft_isspace(line[i]))
		i++;
	get_id(&id, line);
	if (id == 0)
		return (EXIT_FAILURE);
	i += 2;
	while (ft_isspace(line[i]))
		i++;
	get_path_by_id(pars, &id, line + i);
}


int	pars_textures(t_pars *pars, int map_fd) //enlever toutes ces conneries et faire une boucle qui marche
{
	char	*line;

	line = get_next_line(map_fd);
	if(!check_tex_line)
		return (EXIT_FAILURE);
	free(line);
	line = get_next_line(map_fd);
	if(!check_tex_line)
		return (EXIT_FAILURE);
	free(line);
	line = get_next_line(map_fd);
	if(!check_tex_line)
		return (EXIT_FAILURE);
	free(line);
	line = get_next_line(map_fd);
	if(!check_tex_line)
		return (EXIT_FAILURE);
	free(line);
	return (EXIT_SUCCESS);
}

int	pars_map(t_data *data, char **argv)
{
	t_pars pars;
	int		map_fd;
	
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		return (EXIT_FAILURE);
	if (pars_textures(&pars, map_fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}