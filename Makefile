# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akambou <akambou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 11:01:39 by akambou           #+#    #+#              #
#    Updated: 2023/11/17 16:19:36 by akambou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -I includes
RM = rm -rf

SRCS = src/pipex.c src/utils.c
OBJS = ${SRCS:.c=.o}
NAME = pipex
HEADER = includes/pipex.h

BONUS_SRCS = bonus/src/pipex_bonus.c bonus/src/utils_bonus.c
OBJSBONUS = ${BONUS_SRCS:.c=.o}
BONUS_NAME = pipex_bonus

all: $(NAME)

$(NAME): $(OBJS) $(HEADER) Makefile
	@make -C libft > /dev/null
	@echo "🔨 Building $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME) > /dev/null
	@echo "✅ Done building $(NAME)!"

$(BONUS_NAME): $(OBJSBONUS) $(HEADER) Makefile
	@make -C libft > /dev/null
	@echo "🔨 Building $(BONUS_NAME)..."
	@$(CC) $(CFLAGS) $(OBJSBONUS) libft/libft.a -o $(BONUS_NAME) > /dev/null
	@echo "✅ Done building $(BONUS_NAME)!"

bonus: $(BONUS_NAME)

fclean: clean
	@echo "🧹 Cleaning up executables..."
	@$(RM) $(NAME) $(BONUS_NAME) > /dev/null
	@make fclean -C libft > /dev/null
	@echo "✅ Done cleaning up executables!"

clean:
	@echo "🧹 Cleaning up..."
	@$(RM) $(OBJS) $(OBJSBONUS) > /dev/null
	@make clean -C libft  > /dev/null
	@echo "✅ Done cleaning up!"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
