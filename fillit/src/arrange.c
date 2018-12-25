/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 20:44:10 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/25 15:24:56 by gstiedem         ###   ########.fr       */
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

int		push_block(char *map, char *block, int map_side, int tetr_num)
{
	int i;
	int	len;

	i = 0;
	len = ft_strchr(block, '\n') - block;
	while (*(block + 1))
	{
		if (map[i] == '.' && (ft_isalpha(*block)))
			map[i++] = *block++;
		else if (*block == '\n')
		{
			if (!(i < (map_side + 1) * (map_side - 1)))
				return (pop_block(map, tetr_num));
			i += map_side + 1 - len;
			block++;
		}
		else if (*block++ == '.')
			i++;
		else
			return (pop_block(map, tetr_num));
	}
	return (1);
}

int		try_to_push(char *map, char *block, int map_side, int tetr_num)
{
	while (*map)
	{
		if (*map == '.' && push_block(map, block, map_side, tetr_num))
			return (1);
		map++;
	}
	return (0);
}

int		arrange(char *map, char **set, int map_side, int total)
{
	int		i;
	t_sjt	arr[MAX_CARDS];

	pop_arrs(arr, total);
	i = 0;
	while (permute(arr, total))
	{
		while (i < total)
		{
			if (!try_to_push(map, set[arr[i].num], map_side, arr[i].num))
			{
				i = 0;
				break ;
			}
			i++;
			if (i == total)
				return (1);
		}
	}
	return (0);
}

char	*get_square(char **set, int total)
{
	char	*map;
	int		map_side;

	map_side = sqr_root_ceiling(4 * total);
	map = NULL;
	get_map(&map, map_side);
	while (!arrange(map, set, map_side, total))
		get_map(&map, ++map_side);
	return (map);
}
