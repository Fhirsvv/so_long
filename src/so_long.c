/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:10:21 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/04 16:16:20 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	assign_exit(int column, int row, t_map *map)
{
	map->exit_x = row;
	map->exit_y = column;
	map->exit++;
}

int main(int argc, char **argv)
{
	t_map map;
	t_player player;
	t_img img;
	check_arguments(argc, argv, &map);
	read_map(argv, &map);
	init(&map, &img, &player);
	check_map(&map);
	count_elements(&map, &player);
	check_rectangle(&map);
	check_border(&map);
	check_path(map, player);
	draw_map(&map, &img);
	mlx_key_hook(map.mlx_win, detect_key, &map);
	mlx_hook(map.mlx_win, 17, 0, end_game, &map);
	mlx_loop(map.mlx);
	return (0);
}