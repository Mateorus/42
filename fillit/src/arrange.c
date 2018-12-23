/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 20:44:10 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/23 21:56:41 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		pop_block(char *map, int tetr_num)
{
	char	c;

	c = 'A' + tetr_num;
	while (*map)
	{
		if (*map == c)
			*map = '.';
		map++;
	}
	return (0);
}
/* TO_DO: doesn't work when map[i] is '.'!!!!!!!*/

int		push_block(char *map, char *block, int map_side, int tetr_num)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	while (*(block + 1))
	{
		if (map[i] != '.' && !(map[i] == '\n' && *block == '\n'))
			return (pop_block(map, tetr_num));
		if (*block == '\n')
		{
			if (!(i < (map_side + 1) * (map_side - 1)))
				return (pop_block(map, tetr_num));
			i += map_side + 1 - len;
			len = 0;
			block++;
			continue;
		}
		map[i] = *block;
		i++;
		len++;
		block++;
	}
	return (1);
}

int		try_to_push(char *map, char *block, int map_side, int tetr_num)
{
	while (*map)
	{
		if (push_block(map, block, map_side, tetr_num))
			return (1);
		map++;
	}
	return (0);
}

int		arrange(char *map, char **set, int map_side)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (!try_to_push(map, set[i], map_side, i))
			return(0);
		i++;
	}
	return (1);
}

char	*get_square(char **set)
{
	char	*map;
	int		map_side;

	map_side = MIN_MAP_SIDE;
	map = NULL;
	get_map(&map, map_side);
	while (1)
	{
		if (!(arrange(map, set, map_side)))
			get_map(&map, ++map_side);
		else
			break ;
	}
	return (map);
}
