# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akambou <akambou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 09:50:01 by akambou           #+#    #+#              #
#    Updated: 2023/11/17 16:04:45 by akambou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -o$(INCL)

INCL = libft.h

SRCS = $(wildcard *.c)
BONUS = $(wildcard *_bonus.c)

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR), $(BONUS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating library 🔨"
	@ar rcs $(NAME) $(OBJ) > /dev/null
	@ranlib $(NAME) > /dev/null
	@echo "Library created✅."

bonus: $(OBJ_BONUS)
	@echo "Creating bonus library 🔨"
	@ar rcs $(NAME) $(OBJ_BONUS) > /dev/null
	@ranlib $(NAME) > /dev/null
	@touch $@
	@echo "Bonus library created✅."

$(OBJ_DIR)%.o : %.c Makefile $(INCL)
	@echo "Compiling $< 🔨"
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null
	@echo "Compiled $<✅."

clean:
	@echo "Cleaning object files 🔨"
	@rm -rf $(OBJ) > /dev/null
	@echo "Cleaned object files✅."

fclean: clean
	@echo "Cleaning library 🔨"
	@rm -rf $(NAME) > /dev/null
	@echo "Cleaned library✅."

re: fclean all

.PHONY: all clean fclean re
