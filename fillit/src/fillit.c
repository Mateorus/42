/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:17:24 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/20 14:17:42 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(int fd)
{
	char	**argv;

	if (!(argv = malloc(sizeof(*argv) * (MAX_CARDS + 1))))
	{
		ft_putstr("malloc failed\n");
		exit(0);
	}
	argv[validator(fd, argv)] = 0;
	prepare_tetraminos(argv);
	print_square(argv);
}
