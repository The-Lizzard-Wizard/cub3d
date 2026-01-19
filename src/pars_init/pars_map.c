/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:05:15 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/13 15:31:09 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../../inc/pars.h"

int	is_valid_adj(char adj_to_check)
{
	if (BONUS)
	{
		if (adj_to_check == '0' || adj_to_check == '1' || adj_to_check == 'y'
			|| adj_to_check == 'r' || adj_to_check == 'g' || adj_to_check == 'b'
			|| adj_to_check == 'D' || adj_to_check == 'Y' || adj_to_check == 'B'
			|| adj_to_check == 'G' || adj_to_check == 'R')
		return (EXIT_SUCCESS);
	}
	else
	{
		if (adj_to_check == '0' || adj_to_check == '1')
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void	init_things(t_vec2 pos, char *tile, t_data *data)
{
	pos.x += 0.5;
	pos.y += 0.5;
	if (*tile == 'y')
		add_thing(data, &data->textures.tex_y_key, pos, THING_Y_KEY);
	else if (*tile == 'r')
		add_thing(data, &data->textures.tex_r_key, pos, THING_R_KEY);
	else if (*tile == 'g')
		add_thing(data, &data->textures.tex_g_key, pos, THING_G_KEY);
	else if (*tile == 'b')
		add_thing(data, &data->textures.tex_b_key, pos, THING_B_KEY);
	else if (*tile == 'm')
		add_thing(data, &data->textures.tex_magic, pos, THING_MAGIC_ROD);
	else if (*tile == 'c')
		add_thing(data, &data->textures.anime_tex_banana->img_curr, pos,
			THING_BANANA);
	else if (*tile == 'k')
		add_thing(data, &data->textures.anime_tex_kiwi->img_curr, pos,
			THING_KIWI);
	else
		return ;
	*tile = '0';
	update_sp_info(data);
}

void	player_view_init(t_pars *pars, char *tile, t_vec2 pos, int *player_flag)
{
	pars->player_view = *tile;
	*tile = '0';
	pars->player->pos.x = pos.x + 0.5;
	pars->player->pos.y = pos.y + 0.5;
	*player_flag += 1;
}

int	get_player_and_things(t_pars *pars, char *map, t_data *data)
{
	int		i;
	int		player_flag;
	t_vec2	pos;

	i = 0;
	player_flag = 0;
	pos.x = 0;
	pos.y = 0;
	while (map[i])
	{
		if (map[i] == 'N' || map[i] == 'S' || map[i] == 'E' || map[i] == 'W')
			player_view_init(pars, &map[i], pos, &player_flag);
		else if (map[i] != '0' && map[i] != '1')
			if (BONUS)
				init_things(pos, &map[i], data);
		if (map[i] == '\n')
		{
			pos.y++;
			pos.x = -1;
		}
		i++;
		pos.x++;
	}
	return (!(player_flag == 1));
}

int	pars_map(t_pars *pars, int map_fd, t_data *data)
{
	char	*map_inline;

	map_inline = get_map(pars, map_fd);
	if (!map_inline
		|| get_player_and_things(pars, map_inline, data) == EXIT_FAILURE)
	{
		print_error(ER_MAP_NO_PLAYER_FOUND);
		return (EXIT_FAILURE);
	}
	pars->map = ft_split(map_inline, '\n');
	free_ptr(map_inline);
	if (!pars->map)
	{
		print_error(ER_MALLOC_ER);
		return (EXIT_FAILURE);
	}
	if (map_check(pars->map) == EXIT_FAILURE)
	{
		print_error(ER_MAP_UNEXPECTED_CHAR);
		free_array(pars->map, EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
