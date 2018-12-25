/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:30:52 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/25 15:24:17 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define CARD_SIZE		20
# define MAX_CARDS		26
# define MIN_MAP_SIDE	2
# define LEFT			0
# define RIGHT			1
typedef struct	s_sjt
{
	int		num;
	uint8_t	direction;
}				t_sjt;
void	fillit(int fd);
void	assert(int i);
int		validator(int fd, char **set);
void	prepare_tetraminos(char **set);
void	trim(char *tetr);
char	*get_square(char **set, int total);
void	print_square(char *square);
void	get_map(char **map, int map_side);
int		sqr_root_ceiling(int x);
void	pop_arrs(t_sjt arr[], int total);
int		permute(t_sjt arr[], int total);
#endif
