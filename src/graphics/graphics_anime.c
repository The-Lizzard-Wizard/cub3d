/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_anime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:05:02 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/17 15:48:43 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_cub_anime	*new_anime(t_data *data, char *frames, int speed)
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
	new_anime->frames = ft_calloc(sizeof(t_cub_anime), new_anime->nb_frame);
	if (!new_anime->frames)
	{
		free_ptr(frames_paths);
		free_ptr(new_anime);
		return (NULL);
	}
	while ((int)i < new_anime->nb_frame)
	{
		new_anime->frames[i] = new_xpm_img(data, frames_paths[i]);
		if (new_anime->frames[i] == NULL)
			ft_printf("%s\n", frames_paths[i]);
		//add error gestion here
		i++;
	}
	new_anime->speed = speed;
	new_anime->time_bf = 0;
	new_anime->frame_curr = 0;
	new_anime->img_curr = new_anime->frames[0];
	printf("anime ptr %p\n", new_anime->img_curr);
	return (new_anime);
}

void	update_anime(t_cub_anime *anime)
{
	anime->time_bf++;
	if (anime->time_bf > anime->speed)
	{
		anime->time_bf = 0;
		anime->frame_curr++;
		if (anime->frame_curr >= anime->nb_frame)
			anime->frame_curr = 0;
		anime->img_curr = anime->frames[anime->frame_curr];
	}
}
