# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 16:54:58 by jleon-la          #+#    #+#              #
#    Updated: 2024/04/29 17:49:18 by jleon-la         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
LIBFT_LIB = src/libft/
LIBFT_FLAGS = -L src/libft/ -lft
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM		= rm -f

SRC =	src/main.c \
		src/data.c \
		src/sort.c \
		src/aux.c \
		src/moves.c \

OBJS = $(SRC:%.c=%.o)

all:	$(NAME)

.c.o:
		$(CC) -I includes/. $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		@make -C $(LIBFT_LIB)
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)

clean:
		$(RM) */*.o

fclean:	clean
		$(RM) $(NAME)
		@make -C $(LIBFT_LIB) fclean

re:		fclean all

.PHONY : all clean fclean re
