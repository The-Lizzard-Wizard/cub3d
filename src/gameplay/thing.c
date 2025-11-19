/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:55:25 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/19 16:09:19 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/define.h"
#include <stdio.h>

t_thing	*get_last_thing(t_thing *thing_list)
{
	t_thing	*curr_thing;

	if (thing_list == NULL)
		return (NULL);
	curr_thing = thing_list;
	while (curr_thing->next != NULL)
		curr_thing = curr_thing->next;
	return (curr_thing);
}

int	add_thing(t_data *data, t_cub_img *texture, t_vec2 pos, int type)
{
	t_thing	*new_thing;
	t_thing	*last_thing;

	new_thing = malloc(sizeof(t_thing));
	if (!new_thing)
		return (EXIT_FAILURE);
	new_thing->texture = texture;
	new_thing->next = NULL;
	new_thing->pos.x = pos.x;
	new_thing->pos.y = pos.y;
	new_thing->type = type;
	if (data->thing_list == NULL)
	{
		data->thing_list = new_thing;
		return (EXIT_SUCCESS);
	}
	else
		last_thing = get_last_thing(data->thing_list);
	last_thing->next = new_thing;
	return (EXIT_SUCCESS);
}
