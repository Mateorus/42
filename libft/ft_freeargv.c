/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeargv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:25:47 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/03 18:31:52 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_freeargv(char ***argv)
{
	if (!*argv)
		return (NULL);
	if (!*(*argv))
		free(*(*argv));
	while (*(*argv))
	{
		free(*(*argv));
		(*argv)++;
	}
	free(*(*argv));
	return (NULL);
}
