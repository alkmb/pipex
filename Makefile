# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akambou <akambou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 11:01:39 by akambou           #+#    #+#              #
#    Updated: 2023/11/15 16:13:58 by akambou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = pipexb

CC = gcc

CFLAGS =  -Wall -fsanitize=address -I includes

RM = rm -rf

SRCS = 	src/pipex.c\
		includes/pipex.h\
		src/utils.c\
		libft/libft.a\

BONUS_SRCS = bonus/src/pipex_bonus.c\
			bonus/src/utils_bonus.c\
			bonus/includes/pipex_bonus.h\
			libft/libft.a\

$(NAME) :
	@make all -C libft
	@echo "🔨 Building $(NAME)..."
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "✅ Done building $(NAME)!"

$(BONUS_NAME) :
	@make all -C libft
	@echo "🔨 Building $(BONUS_NAME)..."
	@$(CC) $(CFLAGS) $(BONUS_SRCS) -o $(BONUS_NAME)
	@echo "✅ Done building $(BONUS_NAME)!"

all : $(NAME)

bonus : $(BONUS_NAME)

fclean : clean
	@echo "🧹 Cleaning up executables..."
	@$(RM) $(NAME) $(BONUS_NAME)
	@make fclean -C libft
	@echo "✅ Done cleaning up executables!"

clean :
	@echo "🧹 Cleaning up..."
	@$(RM) $(NAME) $(BONUS_NAME)
	@make clean -C libft
	@echo "✅ Done cleaning up!"

re : fclean all

rebonus : fclean bonus

.PHONY: all clean fclean re bonus rebonus
