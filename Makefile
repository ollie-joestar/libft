# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 13:40:55 by oohnivch          #+#    #+#              #
#    Updated: 2024/04/16 16:26:56 by oohnivch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = .
NAME = libft.a

SRC = $(shell find -type f -name "*.c") 

OBJ = $(SRC:%.c=%.o)

bonus: all

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

clean:
	rm -f $(OBJ)

fclean: 
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re
