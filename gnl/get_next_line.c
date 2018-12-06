/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:02:58 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/06 23:45:32 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int	get_next_line(const int fd, char **line)
{
	static t_fdlst	**l;
	ssize_t			r;
	char			buf[BUFF_SIZE];

	if (fd < 0 || !line || BUFF_SIZE < 1 ||
		(r = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	if (!(*line = ft_strsub(buf, 0, (ft_strchr(buf, '\n') - buf))))
		return (-1);
	(void)l;
	return (1);
}
