/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 20:46:45 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/23 21:02:25 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_map(char **map, int map_side)
{
	int	i;
	int	size;

	ft_strdel(map);
	size = map_side * map_side + map_side;
	if (!(*map = malloc(sizeof(**map) * (size + 1))))
	{
		ft_putstr("malloc failed\n");
		exit(0);
	}
	(*map)[size] = 0;
	i = 0;
	while (i < size)
	{
		if (!((i + 1) % (map_side + 1)))
			(*map)[i] = '\n';
		else
			(*map)[i] = '.';
		i++;
	}
}

void	assert(int i)
{
	if (!i)
	{
		ft_putstr("error\n");
		exit(0);
	}
}


