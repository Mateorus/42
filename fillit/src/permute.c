/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 11:46:00 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/25 15:30:47 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

					/* Steinhaus–Johnson–Trotter algorithm */
#include "fillit.h"


int		permute(t_sjt arr[], int total)
{
	int	tmp;
	if (arr[0].num == 1)
		return (0);
	tmp = arr[0].num;
	arr[0].num = arr[1].num;
	arr[1].num = tmp;
	return (1);
}
