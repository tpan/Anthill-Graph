/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:39:31 by tpan              #+#    #+#             */
/*   Updated: 2017/06/27 16:39:32 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	new_connection_array(t_room *room, int neighbor)
{
	room->connections = (int*)malloc(sizeof(int));
	room->connections[0] = neighbor;
}

void	add_connection_array(t_room *room, int neighbor)
{
	int *tmp;
	int i;

	i = 0;
	tmp = (int*)malloc(((*room).c_count + 1) * sizeof(int));
	if (tmp == NULL)
		throw_error(GENERIC);
	while (i < (*room).c_count)
	{
		tmp[i] = (*room).connections[i];
		i++;
	}
	tmp[i] = neighbor;
	if ((*room).connections)
		free((*room).connections);
	(*room).connections = tmp;
}

void	add_connection(t_lemin *everything, int room, int neighbor)
{
	int i;

	i = 0;
	if (room > (*everything).r_ct)
		return ;
	while (i < (*everything).rooms[room].c_count)
	{
		if ((*everything).rooms[room].connections)
			if ((*everything).rooms[room].connections[i] == neighbor)
				return ;
		i++;
	}
	add_connection_array(&everything->rooms[room], neighbor);
	everything->rooms[room].c_count++;
}
