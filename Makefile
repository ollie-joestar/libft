# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 13:40:55 by oohnivch          #+#    #+#              #
#    Updated: 2024/04/17 16:47:35 by oohnivch         ###   ########.fr        #
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
	@echo "\n$(PURPLE)******** $(NAME) with BONUS Created! ********$(NORMAL)\n"

$(NAME): $(OBJ)
	@$(AR) $@ $(OBJ)
	@echo "\n$(GREEN)******** $(NAME) Created! ********$(NORMAL)\n"

%_bonus.o: %_bonus.c
	@if ! $(CC) $(CFLAGS) -c $< -o $@ $(HEADER) 2> error.txt; then\
		echo "$(RED)!!!!!!!! ERROR !!!!!!!!$(NORMAL)"; \
		echo "$(YELLOW)Error caused by $<$(NORMAL)\n"; \
		sed '$$d' error.txt; \
		echo "\n$(RED)Aborting$(NORMAL)"; \
		exit 1; \
	fi

%.o: %.c
	@if ! $(CC) $(CFLAGS) -c $< -o $@ $(HEADER) 2> error.txt; then\
		echo "$(RED)!!!!!!!! ERROR !!!!!!!!$(NORMAL)"; \
		echo "$(YELLOW)Error caused by $<$(NORMAL)\n"; \
		sed '$$d' error.txt; \
		echo "\n$(RED)Aborting makefile........$(NORMAL)"; \
		exit 1; \
	fi

clean:
	@rm -f $(OBJ) $(BOBJ) error.txt
	@echo "$(YELLOW)Deleting $(words $(OBJ) $(BOBJ)) object file(s) $(NORMAL)"
	@echo "$(GREEN)Deletion success! $(NORMAL)"

fclean: 
	@rm -f $(OBJ) $(BOBJ) $(NAME) error.txt
	@echo "$(YELLOW)Deleting $(NAME) and $(words $(OBJ) $(BOBJ)) object file(s) $(NORMAL)" 
	@echo "$(GREEN)Deletion success! $(NORMAL)"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
