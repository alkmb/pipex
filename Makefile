# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akambou <akambou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:43:23 by akambou           #+#    #+#              #
#    Updated: 2023/11/11 12:48:39 by akambou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS =  -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	src/pipex.c\
		src/utils.c\
		libft/libft.a\

$(NAME) :
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

