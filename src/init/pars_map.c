/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:05:15 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/26 12:17:01 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../../inc/pars.h"

char *get_map(t_pars *pars, int map_fd)
{
    char *map_inline;

    map_inline = ft_strdup(pars->line);
    free(pars->line);
    pars->line = get_next_line(map_fd);
    while (pars->line)
    {
        map_inline = ft_strjoin(map_inline, pars->line);
        if (!map_inline)
            return (NULL);
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
    if (adj_to_check == '0' || adj_to_check == '1')
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}


int map_check(t_pars *pars, char **map)
{
    (void)pars;
    size_t x;
    size_t y;

    y = 0;
    while (map[y])
    {
        x = 0;
        printf("map pars at x: %ld, y: %ld\n", x, y);
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

int get_player(t_pars *pars, char *map)
{
    int i;
    int player_flag;
    size_t x;
    size_t y;

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
            pars->player->pos_x = (double)x;
            pars->player->pos_y = (double)y;
            player_flag += 1;
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

int pars_map(t_pars *pars, int map_fd)
{
    char *map_inline;
    char **map;

    map_inline = get_map(pars, map_fd);
    if (!map_inline || get_player(pars, map_inline) == EXIT_FAILURE)
    {
        return (EXIT_FAILURE);
    }
    map = ft_split(map_inline, '\n');
    free(map_inline);
    if (!map)
        return (EXIT_FAILURE);
    print_char_array(map);
    printf("player view: %c\npos_x: %f\npos_y: %f\n", pars->player_view, pars->player->pos_x, pars->player->pos_y);
    if (map_check(pars, map) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}