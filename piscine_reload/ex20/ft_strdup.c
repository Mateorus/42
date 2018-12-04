/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:47:59 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/20 15:03:30 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strcpy(char *src, char *dest)
{
	while (*src)
		*dest++ = *src++;
}

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		len;

	len = ft_strlen(src);
	str = malloc(sizeof(*str) * (len + 1));
	ft_strcpy(src, str);
	str[len] = 0;
	return (str);
}
