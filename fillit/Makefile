# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 19:28:39 by gstiedem          #+#    #+#              #
#    Updated: 2018/12/14 20:15:27 by gstiedem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRC=./$(NAME)/*.c
INCLUDES=./$(NAME)

all:
	$(NAME)
$(NAME):
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(SRC)
	
