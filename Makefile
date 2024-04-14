# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 16:54:58 by jleon-la          #+#    #+#              #
#    Updated: 2024/04/14 17:01:29 by jleon-la         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT = utils/libft.a
INCLUDES = -I include
SRCS = 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C utils/libft
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C utils/libft clean
		rm -f $(OBJS)

fclean: clean
	$(MAKE) -C utils/libft fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re