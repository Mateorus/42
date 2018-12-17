# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 19:28:39 by gstiedem          #+#    #+#              #
#    Updated: 2018/12/17 13:00:54 by gstiedem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRC=./$(NAME)/*.c
INCLUDES=./$(NAME)

all: $(NAME)

$(NAME):
	gcc -o fillit  main.c ./src/*.c -I ./src -I./libft -L ./libft -l ft -g	

clean:
	rm -rf $(NAME)

re: clean $(NAME)
