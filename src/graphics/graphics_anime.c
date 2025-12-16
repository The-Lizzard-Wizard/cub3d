/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_anime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:05:02 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/16 16:39:40 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_cub_anime	*new_anime(char *frames, int speed)
{
	t_cub_anime	*new_anime;
	char		**frames_paths;
	size_t		i;

	i = 0;
	new_anime = ft_calloc(sizeof(t_cub_anime), 1);
	if (!new_anime)
		return (NULL);
	frames_paths = ft_split(frames, ';');
	if (!frames_paths)
	{
		free_ptr(new_anime);
		return (NULL);
	}
	new_anime->nb_frame = array_len(frames_paths);
	
	new_anime->speed = speed;
	return (new_anime);
}
