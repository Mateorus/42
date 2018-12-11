/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:02:58 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/11 17:34:29 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

t_fdlst		*find_lst(t_fdlst **first, const int fd)
{
	t_fdlst	*tmp;

	if (!*first)
	{
		*first = malloc(sizeof(t_fdlst));
		(*first)->fd = fd;
		(*first)->next = NULL;
		(*first)->content = NULL;
	}
	tmp = *first;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = malloc(sizeof(t_fdlst));
	tmp->next = *first;
	tmp->fd = fd;
	tmp->content = NULL;
	*first = tmp;
	return (tmp);
}

char		*get_lst_line(t_fdlst *l, ssize_t r)
{
	char	*tmp;
	char	*sub;

	sub = NULL;
	if ((tmp = ft_strchr(l->content, '\n')))
	{
		*tmp = 0;
		sub = ft_strsub(l->content, 0, tmp - l->content);
		l->content = tmp + 1;
	}
	else if (r < BUFF_SIZE)
	{
		sub = ft_strdup(l->content);
		ft_strdel(&l->start);
		l->content = NULL;
	}
	return (sub);
}

void		add_lst_line(t_fdlst *l, char *buf)
{
	char	*tmp;

	if (!l->content)
	{
		l->content = ft_strdup(buf);
		l->start = l->content;
	}
	else if (*buf)
	{
		tmp = ft_strjoin(l->content, buf);
		ft_strdel(&l->start);
		l->content = tmp;
		l->start = l->content;
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_fdlst	*l;
	t_fdlst			*lst;
	ssize_t			r;
	char			buf[BUFF_SIZE + 1];
	char			*str;

	if (fd < 0 || !line || BUFF_SIZE < 1 ||
		(r = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[r] = 0;
	lst = find_lst(&l, fd);
	add_lst_line(lst, buf);
	while (!(str = get_lst_line(lst, r)))
	{
		if ((r = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[r] = 0;
		add_lst_line(lst, buf);
	}
	if (!lst->content && !r && !*str)
	{
		free(str);
		return (0);
	}
	else
		*line = str;
	return (1);
}
