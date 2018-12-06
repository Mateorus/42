/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:03:08 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/06 22:16:16 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include "libft.h"
# define BUFF_SIZE 32
typedef struct 		s_fdlst
{
	int				fd;
	void			*content;
	size_t			content_size;
	struct s_fdlst	*next;
}					t_fdlst;
int					get_next_line(const int fd, char **line);

#endif
