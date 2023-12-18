/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:42:19 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/12/05 15:18:18 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../minilibx_opengl/mlx.h"
#include <math.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../libft/ft_printf.h"
#include "../libft/get_next_line.h"
//#include <mlx.h>
# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_BLUE "\033[0;36m"
# define COLOR_NORMAL "\033[0m"
# define PLAYER "./sprites/player_img.xpm"
# define COIN "./sprites/coin_image.xpm"
# define WALL "./sprites/walls_image.xpm"
# define FLOOR "./sprites/floor_image.xpm"
# define EXIT "./sprites/exit_image.xpm"
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53


typedef struct s_player
{
	int n_player;
	int player_x;
	int player_y;
	int movements;
} t_player;

typedef struct s_img
{
	void *player_img;
	void *coins_img;
	void *walls_img;
	void *exit_img;
	void *floor_img;
} t_img;

typedef struct s_map
{
	int coins;
	int coins_2;
	int coins_3;
	char **map;
	char **map_3;
	char **map_2;
	int status;
	int exit;
	size_t map_width;
	size_t map_height;
	void *mlx;
	void *mlx_win;
	int img_width;
	int img_height;
	int	exit_x;
	int	exit_y;
	t_player  player;
	t_img  img;
} t_map;


void	read_map(char *argv, t_map *map);
void	check_arguments(int argc, char *argv, t_map *map);
void	free_map(t_map *map);
int	check_map(t_map *map);
void	count_elements(t_map *map,t_player *player);
void	check_rectangle(t_map *map);
int	check_border(t_map *map);
int	flood_fill_from_player(t_map *map, int column, int row);
int	flood_fill_from_exit(t_map *map, int column, int row);
void	check_path(t_map *map);
void	draw_map(t_map *map, t_img *s_img);
int	detect_key(int key_code, t_map *map);
void	assign_exit(int column, int row, t_map *map);
void	ft_error(int n, t_map *map);
void	coin_counter(t_map *map);
int	win_game(t_map *map);
int	end_game(void);
void	ft_error(int n, t_map *map);
void init (t_map *map);
void map_copys(char *str, t_map *map);

#endif