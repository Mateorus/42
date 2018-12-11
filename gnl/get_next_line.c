/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:02:58 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/11 16:05:23 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	**find_fd_content(t_fdlst **first, const int fd)
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
			return (&tmp->content);
		tmp = tmp->next;
	}
	tmp = malloc(sizeof(t_fdlst));
	tmp->next = *first;
	tmp->fd = fd;
	tmp->content = NULL;
	*first = tmp;
	return (&tmp->content);
}

char	*get_lst_line(char **lst_content, ssize_t r)
{
	char	*tmp;
	char	*sub;

	sub = NULL;
	if ((tmp = ft_strchr(*lst_content, '\n')))
	{
		*tmp = 0;
		sub = ft_strsub(*lst_content, 0, tmp - *lst_content);
		tmp = ft_strdup(tmp + 1);
		ft_strdel(lst_content);
		*lst_content = tmp;
	}
	else if (r < BUFF_SIZE)
	{
		sub = ft_strdup(*lst_content);
		ft_strdel(lst_content);
	}
	return (sub);
}

void	add_lst_line(char **lst_content, char *buf)
{
	char	*tmp;

	if (!(*lst_content))
		*lst_content = ft_strdup(buf);
	else if (*buf)
	{
		tmp = ft_strjoin(*lst_content, buf);
		ft_strdel(lst_content);
		*lst_content = tmp;
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_fdlst	*l;
	ssize_t			r;
	char			buf[BUFF_SIZE + 1];
	char			*str;
	char			**content;

	if (fd < 0 || !line || BUFF_SIZE < 1 ||
		(r = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[r] = 0;
	content = find_fd_content(&l, fd);
	add_lst_line(content, buf);
	while (!(str = get_lst_line(content, r)))
	{
		if ((r = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[r] = 0;
		add_lst_line(content, buf);
	}
	if (!*content && !r && !*str)
		return (0);
	else
		*line = str;
	return (1);
}
