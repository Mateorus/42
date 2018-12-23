/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:32:40 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/23 20:42:02 by gstiedem         ###   ########.fr       */
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

int		pop_block(char *map, int tetr_num)
{
	char	c;

	c = 'A' + tetr_num;
	while (*map)
	{
		if (*map == c)
			c = '.';
		map++;
	}
	return (0);
}

int		push_block(char *map, char *block, int map_side, int tetr_num)
{
	int i;
	int	len;

	i = 0;
	while (*(block + 1))
	{
		if (map[i] != '.' || (map[i] == '\n' && *block != '\n'))
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
	}
	return (0);
}

int		arrange(char *map, char **set, int map_side)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (try_to_push(map, set[i], map_side, i))
			
	}
	return (1);
}














