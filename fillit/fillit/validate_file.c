/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:49:31 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/14 21:22:46 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			valid_block(uint16_t card)
{
	return (1);
}

uint16_t	get_valid_card(char *buf)
{
	int			i;
	int			count;
	char		c;
	uint16_t	tetr;

	tetr = 0;
	count = 0;
	i = 0;
	while (i < CARD_SIZE - 4)
	{
		c = *buf++;
		if (c != '#' && c != '.' && c != '\n')
			return (0);
		if (i > 0 && !(i % 4) && (c != '\n'))
			return (0);
		if (c == '#')
		{
			tetr |= 1UL << i;
			count++;
		}
		if (c != '\n')
			i++;
	}
	if (buf[i] != '\n' || buf[i] != 0 || count != 4)
		return (0);
	return (tetr);
}

int			validator(int fd, uint16_t *arr)
{
	int			i;
	int			r;
	int			total;
	char		buf[MAX_SIZE_OF_FILE + 1];

	r = read(fd, buf, MAX_SIZE_OF_FILE + 1);
	if (!(r >= CARD_SIZE && r <= MAX_SIZE_OF_FILE) ||
		((r + 1) % (CARD_SIZE + 1)) != 0)
		return (-1);
	buf[r] = 0;
	total = (r + 1) / (CARD_SIZE + 1);
	i = 0;
	r = 0;
	while (i < total)
	{
		arr[i] = get_valid_card(&buf[r]);
		if (!(arr[i]) || !(valid_block(arr[i])))
			return (-1);
		r += CARD_SIZE + 1;
	}
	return (total);
}
