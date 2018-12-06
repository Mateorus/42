/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:10:26 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/20 16:17:49 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*p;
	int i;

	if (min >= max)
		return (NULL);
	range = max - min;
	p = malloc(sizeof(*p) * range);
	i = 0;
	while (min < max)
		p[i++] = min++;
	return (p);
}
