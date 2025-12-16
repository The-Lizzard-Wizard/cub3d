/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:05:15 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/16 15:10:39 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../../inc/pars.h"

char *get_map(t_pars *pars, int map_fd)
{
	char *map_inline;
	char *tmp;

	map_inline = ft_strdup(pars->line);
	free(pars->line);
	pars->line = get_next_line(map_fd);
	while (pars->line)
	{
		tmp = ft_strjoin(map_inline, pars->line);
		free(map_inline);
		if (!tmp)
		{
			return (NULL);
		}
		map_inline = tmp;
		free(pars->line);
		pars->line = get_next_line(map_fd);
	}
	return (map_inline);
}

void	print_char_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
}

int is_valid_adj(char adj_to_check)
{
	if (adj_to_check == '0' || adj_to_check == '1' || adj_to_check == 'y' || adj_to_check == 'r' || adj_to_check == 'g' || adj_to_check == 'b'
		|| adj_to_check == 'D' || adj_to_check == 'Y' || adj_to_check == 'B'|| adj_to_check == 'G' || adj_to_check == 'R')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}


int map_check(char **map)
{
	size_t x;
	size_t y;

	y = 0;
	while (map[y])
	{
		x = 0;
		
		while (map[y][x])
		{
			if (map[y][x] == '0')
			{
				if (x == 0 || is_valid_adj(map[y][x - 1]) == EXIT_FAILURE)
					return (EXIT_FAILURE);
				if (is_valid_adj(map[y][x + 1]) == EXIT_FAILURE)
					return (EXIT_FAILURE);
				if (!map[y + 1] || ft_strlen(map[y + 1]) < x || is_valid_adj(map[y + 1][x]) == EXIT_FAILURE)
					return (EXIT_FAILURE);
				if(y == 0 || ft_strlen(map[y - 1]) < x || is_valid_adj(map[y - 1][x]) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

void init_things(t_vec2 pos, char *tile, t_data *data)
{
	if (*tile == 'y')
	{
		add_thing(data, data->textures.tex_y_key, pos, THING_Y_KEY);
		*tile = '0';
	}
	else if (*tile == 'r')
	{
		add_thing(data, data->textures.tex_r_key, pos, THING_R_KEY);
		*tile = '0';
	}
	else if (*tile == 'g')
	{
		add_thing(data, data->textures.tex_g_key, pos, THING_G_KEY);
		*tile = '0';
	}
	else if (*tile == 'b')
	{
		add_thing(data, data->textures.tex_b_key, pos, THING_B_KEY);
		*tile = '0';
	}
	else if (*tile == 'm')
	{
		add_thing(data, data->textures.tex_magic_rod, pos, THING_MAGIC_ROD);
		*tile = '0';
	}
	else
		return ;
	update_sprite_info(data);
}

int get_player_and_things(t_pars *pars, char *map, t_data *data)
{
	int i;
	int player_flag;
	size_t x;
	size_t y;
	t_vec2 pos;

	i = 0;
	player_flag = 0;
	y = 0;
	x = 0;
	while (map[i])
	{
		if (map[i] == 'N' || map[i] == 'S' || map[i] == 'E' || map[i] == 'W')
		{
			pars->player_view = map[i];
			map[i] = '0';
			pars->player->pos.x = (double)x + 0.5;
			pars->player->pos.y = (double)y + 0.5;
			player_flag += 1;
		}
		else if (map[i] != '0' && map[i] != '1')
		{
			pos.x = x + 0.5;
			pos.y = y + 0.5;
			init_things(pos, &map[i], data);
		}
		if (map[i] == '\n')
		{
			y++;
			x = -1;
		}
		i++;
		x++;
	}
	if (player_flag == 1)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int pars_map(t_pars *pars, int map_fd, t_data *data)
{
	char *map_inline;

	map_inline = get_map(pars, map_fd);
	if (!map_inline || get_player_and_things(pars, map_inline, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	pars->map = ft_split(map_inline, '\n');
	free(map_inline);
	if (!pars->map)
		return (EXIT_FAILURE);
	if (map_check(pars->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	print_char_array(pars->map);
	printf("player view: %c\npos_x: %f\npos_y: %f\n", pars->player_view, pars->player->pos.x, pars->player->pos.y);
	
	return (EXIT_SUCCESS);
}