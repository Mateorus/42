# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 19:28:39 by gstiedem          #+#    #+#              #
#    Updated: 2018/12/20 14:24:11 by gstiedem         ###   ########.fr        #
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
	make -C $(LIB_PATH) && make -C $(LIB_PATH) clean
dbg:
	$(CC) $(CFLAGC) $(DBGFLAGS) $(SRC) $(LIBFLAGS) -o $(NAME)
