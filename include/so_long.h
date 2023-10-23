/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:42:19 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/23 17:52:13 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include "../minilibx_opengl/mlx.h"
# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_BLUE "\033[0;36m"
# define TEST "./sprites/Down.xpm"
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

typedef struct s_map
{
    int     coins;
    int     coins_copy;
    int     exit;
    int     exit_copy;
    int     n_players;
    int     player_x;
    int     player_y;
    char    **map;
    char    **map_copy;
    size_t     map_width;
    size_t     map_height;
    int     init_pos;   
    void    *mlx;
    void    *mlx_win;
    int     img_width;
    int     img_height;    
    int     movements;
    void    *player_img;
    void    *coins_img;
    void    *walls_img;
    void    *exit_img;
    void    *floor_img;
            
}t_map;

void    check_arguments(int argc, char *argv);
void    read_map(char *argv, t_map *map);
int     check_char_map(t_map *map);
void	check_rectangle(t_map *map);
void	check_elements_number(t_map *map);
int     check_border(t_map *map);
void	flood_fill(t_map *map, int column, int row);
void    check_path(t_map *map);
int	    end_game();
int     detect_key(int key_code, t_map *map);
void    draw_map(t_map *map);
void    ft_error(int n);

#endif