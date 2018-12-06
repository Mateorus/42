/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:26:52 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/20 12:38:10 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	check;
	int	res;

	if (nb < 1)
		return (0);
	check = 1;
	res = check * check;
	while (res <= nb)
	{
		if (res == nb)
			return (check);
		check++;
		res = check * check;
	}
	return (0);
}
