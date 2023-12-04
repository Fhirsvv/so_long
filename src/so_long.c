/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:10:21 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/04 18:53:40 by ecortes-         ###   ########.fr       */
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
	int i;
	int j;
	
	t_map map;
	check_arguments(argc, argv[1], &map);
	read_map(argv[1], &map);
	init(&map, &map.img, &map.player);
	check_map(&map);
	count_elements(&map, &map.player);
	check_rectangle(&map);
	check_border(&map);
	check_path(map, map);
	i = flood_fill_from_player(map, map.player.player_y, map.player.player_x);
	j = flood_fill_from_exit(map, map.exit_y, map.exit_x);
	draw_map(&map, &map.img);
	mlx_key_hook(map.mlx_win, detect_key, &map);
	mlx_hook(map.mlx_win, 17, 0, end_game, &map);
	mlx_loop(map.mlx);
	return (0);
}