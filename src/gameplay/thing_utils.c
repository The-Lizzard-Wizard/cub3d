/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thing_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:57:15 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/31 17:01:05 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/define.h"
#include <stdio.h>
#include <math.h>

int	get_nb_things(t_thing *list)
{
	t_thing	*curr_thing;
	int	nb;

	nb = 1;
	if (list == NULL)
		return (0);
	curr_thing = list;
	while (curr_thing->next != NULL)
	{
		curr_thing = curr_thing->next;
		nb++;
	}
	return (nb);
}

t_thing	*get_thing_by_id(t_thing *list, int id)
{
	t_thing	*curr_thing;
	int		i;

	i = 0;
	if (list == NULL)
		return (NULL);
	curr_thing = list;
	while (curr_thing->next != NULL && i < id)
	{
		if (curr_thing->next == NULL)
			return (NULL);
		curr_thing = curr_thing->next;
		i++;
	}
	return (curr_thing);
}

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

int	free_thing_list(t_data *data, int code)
{
	t_thing	*curr_thing;
	t_thing	*next_thing;

	curr_thing = NULL;
	next_thing = NULL;
	if (!data->thing_list)
		return (code);
	curr_thing = data->thing_list;
	while (curr_thing != NULL)
	{
		if (curr_thing->next)
			next_thing = curr_thing->next;
		else
			next_thing = NULL;
		del_thing(data, curr_thing);
		curr_thing = next_thing;
	}
	return (code);
}

int	update_sp_info(t_data *data)
{
	data->nb_thing = get_nb_things(data->thing_list);
	if (data->sp_distance)
		free_ptr(data->sp_distance);
	if (data->sp_order)
		free_ptr(data->sp_order);
	data->sp_distance = ft_calloc(data->nb_thing, sizeof(double));
	if (!data->sp_distance)
		return (EXIT_FAILURE);
	data->sp_order = ft_calloc(data->nb_thing, sizeof(int));
	if (!data->sp_order)
		return (free_one_and_exit(data->sp_distance, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
