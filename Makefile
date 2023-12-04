# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akambou <akambou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 11:01:39 by akambou           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/11/17 16:19:36 by akambou          ###   ########.fr        #
=======
#    Updated: 2023/11/23 01:33:29 by akambou          ###   ########.fr        #
>>>>>>> ae4378c96d758d79c89bb26d06a295a81de7d0d3
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = pipexb

CC = gcc

CFLAGS =  -Wall -Wextra -Werror -fsanitize=address -I includes

RM = rm -rf

SRCS = 	src/pipex.c\
		src/utils.c\

BONUS_SRCS = bonus/src/pipex_bonus.c\
			bonus/src/utils_bonus.c\

OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR), $(BONUS_SRCS:.c=.o))

$(NAME) : $(OBJS)
	@make all -sC libft
	@$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
	@echo -e "\033[0;32mPipex created 📚\033[0m"

$(BONUS_NAME) : $(BONUS_OBJS)
	@make all -sC libft
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -Llibft -lft -o $(BONUS_NAME)
	@echo -e "\033[0;32mPipex Bonus created 📚\033[0m"

<<<<<<< HEAD
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
=======
$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;33m\rCompiling -> $< ✅                        \033[0m"

all : $(NAME)
>>>>>>> ae4378c96d758d79c89bb26d06a295a81de7d0d3

bonus : $(BONUS_NAME)

<<<<<<< HEAD
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
=======
fclean : clean
	@$(RM) $(NAME) $(BONUS_NAME) $(OBJS) $(BONUS_OBJS)
	@make fclean -sC libft
	@echo -e "\033[0;31mCleaned Pipex 🧹\033[0m"

clean :
	@$(RM) $(NAME) $(BONUS_NAME) $(OBJS) $(BONUS_OBJS)
	@echo -e "\033[0;31mCleaned objects pipex 🧹\033[0m"
>>>>>>> ae4378c96d758d79c89bb26d06a295a81de7d0d3

re : fclean all

rebonus : fclean bonus

.PHONY: all clean fclean re bonus rebonus
