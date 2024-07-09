# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 16:13:36 by ecortes-          #+#    #+#              #
#    Updated: 2024/07/08 12:01:53 by ecortes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRC_DIR = ./src
SRC = check_map.c  draw_game.c hooks.c inits.c path.c utils.c so_long.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -rf


LIBFT_DIR = ./libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)


MLX_PATH = mlx_linux/
MINILIBX:= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz


all: $(NAME)
	@echo " \033[36m[ OK ] | READY TO PLAY!\033[0m"

$(NAME): $(OBJS)	
	@make  -C $(LIBFT_DIR)	
	@gcc $(CFLAGS) $(OBJS) $(MINILIBX) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS) $(LIBFT_A)

fclean: clean	
	@$(RM) $(NAME) $(B_NAME) $(OBJS)
	@make -C $(LIBFT_DIR) fclean	

re: fclean	
	@make all

.PHONY: all  clean fclean re