/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:30:52 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/20 14:20:42 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define CARD_SIZE 20
# define MAX_CARDS 26

void	fillit(int fd);
void	ft_assert(int i);
int		validator(int fd, char **argv);
void	prepare_tetraminos(char **argv);
void	print_square(char **argv);
#endif
