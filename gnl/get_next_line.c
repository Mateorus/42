/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:02:58 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/10 20:40:24 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	**find_fd_content(t_fdlst **start, const int fd)
{
	t_fdlst	*tmp;

	if (!*start)
	{
		*start = malloc(sizeof(t_fdlst));
		(*start)->fd = fd;
		(*start)->next = NULL;
		(*start)->content = NULL;
	}
	tmp = *start;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (&tmp->content);
		tmp = tmp->next;
	}
	tmp = malloc(sizeof(t_fdlst));
	tmp->next = *start;
	tmp->fd = fd;
	tmp->content = NULL;
	*start = tmp;
	return (&tmp->content);
}

char	*get_lst_line(char **lst_content, char *buf)
{
	char	*tmp;
	char	*sub;

	if (!(*lst_content))
		*lst_content = ft_strdup(buf);
	else
	{
		tmp = ft_strjoin(*lst_content, buf);
		free(*lst_content);
		*lst_content = tmp;
	}
	if ((tmp = ft_strchr(*lst_content, '\n')))
	{
		*tmp = 0;
		sub = ft_strsub(*lst_content, 0, tmp - *lst_content);
		tmp = ft_strdup(tmp + 1);
		free(*lst_content);
		*lst_content = tmp;
		return (sub);
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	static t_fdlst	*l;
	ssize_t			r;
	char			buf[BUFF_SIZE + 1];
	char			**str;

	if (fd < 0 || !line || BUFF_SIZE < 1 ||
		(r = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	if (!r)
		return (0);
	buf[r] = 0;
	while (!(*line = get_lst_line(find_fd_content(&l, fd), buf)))
	{
		if (!(r = read(fd, buf, BUFF_SIZE)) && !*line)
		{
			str = find_fd_content(&l, fd);
			*line = ft_strdup(*str);
			ft_strdel(str);
			return (1);
		}
		buf[r] = 0;
	}
	return (1);
}
