# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 13:40:55 by oohnivch          #+#    #+#              #
#    Updated: 2024/04/17 15:20:14 by oohnivch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#									Variables								   #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = -I.
NAME = libft.a
AR = ar rcs

NORMAL = \033[0m
GREEN = \033[1;32m
BLUE = \033[0;34m
PURPLE = \033[1;35m
RED = \033[0;31m
YELLOW = \033[0;33m


# **************************************************************************** #
#									Source Files							   #
# **************************************************************************** #

CSRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_toupper.c ft_tolower.c

SSRC = ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
	   ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c \
	   ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	   ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c

MSRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_calloc.c

FSRC = ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c 

BSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	   ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	   ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRC = $(CSRC) $(SSRC) $(MSRC) $(FSRC)
OBJ = $(SRC:%.c=%.o)
BOBJ = $(BSRC:%.c=%.o)

# **************************************************************************** #
#									Rules									   #
# **************************************************************************** #

all: $(NAME)

bonus: $(OBJ) $(BOBJ)
	@$(AR) $(NAME) $(OBJ) $(BOBJ)
	@echo "$(PURPLE)$(NAME) with BONUS Created!$(NORMAL)"

$(NAME): $(OBJ)
	@$(AR) $@ $(OBJ)
	@echo "$(GREEN)$(NAME) Created!$(NORMAL)"

%_bonus.o: %_bonus.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)
	@echo "$(YELLOW)$<	$(BLUE)$@ $(NORMAL)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)
	@echo "$(YELLOW)$<		$(BLUE)$@ $(NORMAL)"

clean:
	@rm -f $(OBJ) $(BOBJ)
	@echo "$(RED)Deleting $(words $(OBJ) $(BOBJ)) object files $(NORMAL)"
	@echo "$(GREEN)Deletion success! $(NORMAL)"

fclean: 
	@rm -f $(OBJ) $(BOBJ) $(NAME)
	@echo "$(RED)Deleting $(NAME) and $(words $(OBJ) $(BOBJ)) object files $(NORMAL)" 
	@echo "$(GREEN)Deletion success! $(NORMAL)"

re: fclean all

rebonus: fclean bonus

joestar: sax

sax:
	@curl -L s.42l.fr/joestar | bash

.PHONY: all clean fclean re bonus
