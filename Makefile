# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 13:40:55 by oohnivch          #+#    #+#              #
#    Updated: 2024/04/16 20:03:47 by oohnivch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = .
NAME = libft.a

SRC = \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_putnbr_fd.c \
	  ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c 

BSRC = \
		   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		   ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		   ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:%.c=%.o)
BOBJ = $(BSRC:$.c=%.o)

bonus: $(NAME) $(BOBJ)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean:
	rm -f $(OBJ)

fclean: 
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re
