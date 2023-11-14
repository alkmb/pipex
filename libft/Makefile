# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akambou <akambou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 22:13:50 by akambou           #+#    #+#              #
#    Updated: 2023/11/11 12:49:03 by akambou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -I $(INCL)

INCL = libft.h

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
 		ft_strlen.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strlcpy.c \
		ft_strlcat.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_bzero.c \
		ft_calloc.c ft_strdup.c ft_atoi.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_putstr_fd.c \
		ft_putchar_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_strmapi.c \
		ft_striteri.c ft_split.c ft_lstmap_bonus.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c \
		 ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		 ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)
	ranlib $(NAME)
	@touch $@
%.o : %.c Makefile $(INCL)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
