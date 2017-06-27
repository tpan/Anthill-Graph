/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 01:15:42 by tpan              #+#    #+#             */
/*   Updated: 2017/06/27 01:15:43 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_ant_arr(int **ant_arr, int num_ants)
{
	int i;

	i = 0;
	(*ant_arr) = (int*)malloc(sizeof(int) * (num_ants + 1));
	while (i <= num_ants)
	{
		(*ant_arr)[i] = -1;
		i++;
	}
}

void	print_name(t_lemin *everything, int *ant_arr, int i)
{
	ft_printf("L%d-%s ", i,
			everything->rooms[everything->path.pathfinder[ant_arr[i]]].name);
}

void	print_ants(t_lemin *everything)
{
	int *ant_arr;
	int i;

	init_ant_arr(&ant_arr, everything->ant_count);
	i = 1;
	ant_arr[i] = 1;
	while (1)
	{
		i = 1;
		while (ant_arr[i] < 0 && i < everything->ant_count + 1)
			i++;
		if (i > everything->ant_count)
			break ;
		while (i <= everything->ant_count && ant_arr[i] != -1)
		{
			print_name(everything, ant_arr, i);
			ant_arr[i]++;
			if (ant_arr[i] == everything->path.index)
				ant_arr[i] = -1;
			i++;
		}
		ft_putchar('\n');
		ant_arr[i] = 1;
	}
	free(ant_arr);
}
