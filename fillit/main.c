/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:25:21 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/17 18:51:53 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc != 2)
		return (usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("no such file\n");
		return (1);
	}
	i = fillit(fd);

}
