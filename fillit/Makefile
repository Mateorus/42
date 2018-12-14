# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 19:28:39 by gstiedem          #+#    #+#              #
#    Updated: 2018/12/14 21:35:40 by gstiedem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit.o
CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRC=./$(NAME)/*.c
INCLUDES=./$(NAME)


$(NAME):
	gcc -o fillit.o  main.c ./fillit/*.c -I ./fillit -I./libft -L ./libft -l ft -g	
