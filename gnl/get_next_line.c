/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:02:58 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/11 19:13:57 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

t_fdlst		*get_lst(t_fdlst **first, const int fd)
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

char		*get_lst_line(t_fdlst *l)
{
	char	*tmp;
	char	*sub;

	if (!l->content || !*l->content)
	{
		return (NULL);
	}
	if ((tmp = ft_strchr(l->content, '\n')))
	{
		*tmp = 0;
		sub = ft_strsub(l->content, 0, tmp - l->content);
		l->content = tmp + 1;
	}
	else
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
	else
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

	if (!line)
		return (-1);
	lst = get_lst(&l, fd);
	while ((r = read(fd, buf, BUFF_SIZE)))
		{
			if (r == -1)
				return (-1);
			add_lst_line(lst, buf);
			if (ft_isin(buf, '\n', r))
				break ;
		}
	if ((str = get_lst_line(lst)))
		*line = str;
	ft_strdel(&lst->start);
	return (str != 0 ? 1 : 0);
}









