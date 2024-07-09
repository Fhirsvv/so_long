/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:10:21 by ecortes-          #+#    #+#             */
/*   Updated: 2024/07/09 14:24:51 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_copys(char *str, t_map *map)
{
	if (strlen(str) == 0)
		ft_error(1, map);
	map->status = 1;
	map->map = ft_split(str, '\n');
	map->map_2 = ft_split(str, '\n');
	map->map_3 = ft_split(str, '\n');
}

void	assign_exit(int column, int row, t_map *map)
{
	map->exit_x = row;
	map->exit_y = column;
	map->exit++;
}

int	main(int argc, char **argv)
{
	t_map	map;

	check_arguments(argc, argv[1], &map);
	read_map(argv[1], &map);
	check_rectangle(&map);
	check_border(&map);
	init(&map);
	check_map(&map);
	count_elements(&map, &map.player);
	flood_fill_from_player(&map, map.player.player_y, map.player.player_x);
	flood_fill_from_exit(&map, map.player.player_y, map.player.player_x);
	check_path(&map);
	draw_map(&map, &map.img);
	mlx_key_hook(map.win, key_hook, &map);
	mlx_hook(map.win, 17, 0, end_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
