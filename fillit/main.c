/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:25:21 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/14 20:26:21 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			fd;
	int			total;
	uint16_t	arr[MAX_CARDS];

	if (argc != 2)
		return (usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (1);
	


	total = validator(fd, arr);
	for (int i = 0; i < total; i++)
		printf("%d", arr[i]);



}
