# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 16:13:36 by ecortes-          #+#    #+#              #
#    Updated: 2023/12/20 18:55:33 by ecortes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRC_DIR = ./src
SRC = check_map.c  draw_game.c hooks.c inits.c path.c utils.c so_long.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -rf


LIBFT_DIR = ./libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

NAME = so_long

MLX_PATH = minilibx_opengl/
MINILIBX:= -L $(MLX_PATH) $(MLX_PATH)libmlx.a -lmlx #-framework OpenGL -framework AppKit

all: $(NAME)
	@echo " \033[36m[ OK ] | READY TO PLAY!\033[0m"

$(NAME): $(OBJS)	
	@make  -C $(LIBFT_DIR)	
	@gcc $(CFLAGS) $(OBJS) $(MINILIBX) $(LIBFT) -o $(NAME)

# B = .

# $(B_NAME): $(BONUS_OBJS)		
# 	@make bonus -C $(LIBFT_DIR)	
# 	@gcc $(CFLAGS) $(BONUS_OBJS)  $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(B_NAME)	

clean:
	$(RM) $(OBJS) $(LIBFT_A)

fclean: clean	
	@$(RM) $(NAME) $(B_NAME) $(OBJS)
	@make -C $(LIBFT_DIR) fclean	

re: fclean	
	@make all

.PHONY: all  clean fclean re