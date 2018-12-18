/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:30:52 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/17 20:34:31 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define MAX_SIZE_OF_FILE 545
# define CARD_SIZE 20
# define MAX_CARDS 26
void	fillit(int fd);
void	ft_assert(int i);
int		validator(int fd, char **argv);
void	write_valid_card(char **argv, char *buf);
int		valid_block(char *buf);
void	ft_putstr(char const *s);
char	*ft_strdup(const char *s1);
#endif
