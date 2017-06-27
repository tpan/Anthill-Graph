/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 01:14:57 by tpan              #+#    #+#             */
/*   Updated: 2017/06/27 01:14:59 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	burn_them_all(t_lemin *lemin)
{
	int i;

	i = 0;
	while (i < (*lemin).r_ct)
	{
		free((*lemin).rooms[i].name);
		free((*lemin).rooms[i].connections);
		i++;
	}
	free((*lemin).rooms);
	free((*lemin).path.pathfinder);
}

int		main(void)
{
	t_lemin lemin;

	parse_input(&lemin);
	if (!find_path(&lemin.rooms, &lemin.path, lemin.start))
		throw_error(GENERIC);
	ft_putchar('\n');
	print_ants(&lemin);
	burn_them_all(&lemin);
}
