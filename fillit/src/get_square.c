/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 20:42:09 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/23 20:42:32 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
