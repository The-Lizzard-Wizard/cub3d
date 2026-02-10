/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:05:15 by gchauvet          #+#    #+#             */
/*   Updated: 2026/02/10 13:53:35 by authomas         ###   ########lyon.fr   */
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
	if (adj_to_check == ' ' || adj_to_check == '\0')
		print_error(ER_MAP_NOT_CLOSE);
	else
		print_error(ER_MAP_UNEXPECTED_CHAR);
	return (EXIT_FAILURE);
}

int	init_things(t_vec2 pos, char *tile, t_data *data)
{
	t_thing *thing;
	
	pos.x += 0.5;
	pos.y += 0.5;
	if (*tile == 'y')
		thing = add_thing(data, &data->textures.tex_y_key, pos, THING_Y_KEY);
	else if (*tile == 'r')
		thing = add_thing(data, &data->textures.tex_r_key, pos, THING_R_KEY);
	else if (*tile == 'g')
		thing = add_thing(data, &data->textures.tex_g_key, pos, THING_G_KEY);
	else if (*tile == 'b')
		thing = add_thing(data, &data->textures.tex_b_key, pos, THING_B_KEY);
	else if (*tile == 'm')
		thing = add_thing(data, &data->textures.tex_magic, pos, THING_MAGIC_ROD);
	else if (*tile == 'c')
		thing = add_thing(data, &data->textures.anime_tex_banana->img_curr, pos,
			THING_BANANA);
	else if (*tile == 'k')
		thing = add_thing(data, &data->textures.anime_tex_kiwi->img_curr, pos,
			THING_KIWI);
	if (!thing)
		return (EXIT_FAILURE);
	*tile = '0';
	update_sp_info(data);
	return (EXIT_SUCCESS);
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
				if (!init_things(pos, &map[i], data))
					return (-1);
		if (map[i] == '\n')
		{
			pos.y++;
			pos.x = -1;
		}
		i++;
		pos.x++;
	}
	return (player_flag);
}

int	pars_map(t_pars *pars, int map_fd, t_data *data)
{
	char	*map_inline;
	int		nb_player;

	map_inline = get_map(pars, map_fd);
	if (!map_inline)
		return (EXIT_FAILURE);
	nb_player = get_player_and_things(pars, map_inline, data);
	if (nb_player == 0)
		print_error(ER_MAP_NO_PLAYER_FOUND);
	else if (nb_player < 0)
		print_error(ER_MALLOC_ER);
	else if (nb_player > 1)
		print_error(ER_MAP_TOO_MANY_PLAYER);
	if (nb_player != 1)
		return (free_one_and_exit(map_inline, EXIT_FAILURE));
	pars->map = ft_split(map_inline, '\n');
	free_ptr(map_inline);
	if (!pars->map)
		return (EXIT_FAILURE);
	if (map_check(pars->map) == EXIT_FAILURE)
		return (free_array(pars->map, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
