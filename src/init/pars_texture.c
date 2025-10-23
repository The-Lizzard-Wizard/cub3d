/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:09:15 by authomas          #+#    #+#             */
/*   Updated: 2025/10/23 17:18:07 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pars.h"

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

int get_path_by_id(t_pars *pars, char id, char *line)
{
	int i;

	i = 0;
	if (id == 'F')
		if (get_color_f(pars, line) == EXIT_FAILURE)
            return (EXIT_FAILURE);
    else if (id == 'C')
        if (get_color_c(pars, line) == EXIT_FAILURE)
            return (EXIT_FAILURE);
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
    return (EXIT_SUCCESS);
}

int check_tex_line(t_pars *pars, char *line)
{
	int i;
	char id;
	
	i = 0;
	id = 0;
	if (!line)
		return (EXIT_FAILURE);
	while (ft_isspace(line[i]))
		i++;
	get_id(&id, line);
	if (id == 0)
		return (EXIT_FAILURE);
	i += 2;
	while (ft_isspace(line[i]))
		i++;
	if (get_path_by_id(pars, id, line + i) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}


int check_var(t_pars *pars)
{
	if (!pars->c_color_check || !pars->f_color_check)
		return (EXIT_FAILURE);
	if (!*(pars->tex_path_ea) || !*(pars->tex_path_we))
		return (EXIT_FAILURE);
	if (!*(pars->tex_path_no) || !*(pars->tex_path_so))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	pars_textures(t_pars *pars, int map_fd)
{
	char	*line;

    line = get_next_line(map_fd);
	while (line)
    {
        if (*line != '\n')
            if (check_tex_line(pars, line) == EXIT_FAILURE)
            {
                if (check_var(pars) == EXIT_SUCCESS) // check si toutes mes variables sont set et validesgit 
                    return(EXIT_SUCCESS);
                return (EXIT_FAILURE);
            }
        free(line);
        line = get_next_line(map_fd);
    }
	return (EXIT_SUCCESS);
}