# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 15:17:53 by fdiaz-gu          #+#    #+#              #
#    Updated: 2023/10/18 13:25:25 by fdiaz-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = ./src/so_long.c ./src/utils.c

OBJS = $(SRCS:.c=.o)
CC = gcc
# CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all  clean fclean re