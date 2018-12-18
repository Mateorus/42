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
DBGFLAGS=-g
LIBFLAGS=-L ./libft -lft -I $(INCLUDES)
SRC=./src/*.c
INCLUDES=./libft
LIB_PATH=./libft

.PHONY: $(LIB_PATH)

all: $(NAME)

$(NAME): $(LIB_PATH)
	$(CC) $(CFLAGS) $(SRC) $(LIBFLAGS) -o $(NAME)
clean:

fclen: clean
	rm -rf $(NAME)

re: clean $(NAME)

$(LIB_PATH):
	make -C $(LIB_PATH)
dbg:
	$(CC) $(CFLAGC) $(DBGFLAGS) $(SRC) $(LIBFLAGS) -o $(NAME)
