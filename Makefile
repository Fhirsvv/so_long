# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 16:13:36 by ecortes-          #+#    #+#              #
#    Updated: 2023/12/04 14:08:55 by ecortes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRC_DIR = ./src
SRC = 

OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_DIR)/, $(BONUS:.c=.o))
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
AR = ar
ARFLAGS = rcs
RM = rm -rf
B_NAME = so_long_bonus

LIBFT_DIR = ./libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

NAME = so_long

all: $(NAME)
	@echo " \033[36m[ OK ] | READY TO PLAY!\033[0m"

$(NAME): $(OBJS)	
	@make bonus -C $(LIBFT_DIR)	
	@gcc $(CFLAGS) $(OBJS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)	

B = .

$(B_NAME): $(BONUS_OBJS)		
	@make bonus -C $(LIBFT_DIR)	
	@gcc $(CFLAGS) $(BONUS_OBJS)  $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(B_NAME)	

bonus: $(B)

$(B): $(B_NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(LIBFT_A)

fclean: clean	
	@$(RM) $(NAME) $(B_NAME) $(BONUS_OBJS) $(OBJS)
	@make -C $(LIBFT_DIR) fclean	

re: fclean	
	@make all

.PHONY: all  clean fclean re