/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:17:24 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/23 18:01:19 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(int fd)
{
	char	**argv;
	char	*square;

	if (!(argv = malloc(sizeof(*argv) * (MAX_CARDS + 1))))
	{
		ft_putstr("malloc failed\n");
		exit(0);
	}
	argv[validator(fd, argv)] = 0;
	prepare_tetraminos(argv);
	square = get_square(argv);
	print_square(square);
}
