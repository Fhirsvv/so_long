/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:50:21 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/04 18:43:50 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	go_up(t_map *map, t_player *player, t_img *img)
{
	if (map->map[player->player_y - 1][player->player_x] == 'C')
		coin_counter(map);
	map->map[player->player_y - 1][player->player_x] = 'P';
	map->map[player->player_y][player->player_x] = '0';
	player->player_y = player->player_y - 1;
	player->movements++;
	ft_printf("Movimientos: %s%d\n", COLOR_NORMAL, player->movements);
	draw_map(map, img);
}

void	go_down(t_map *map, t_player *player, t_img *img)
{
	if (map->map[player->player_y + 1][player->player_x] == 'C')
		coin_counter(map);
	map->map[player->player_y + 1][player->player_x] = 'P';
	map->map[player->player_y][player->player_x] = '0';
	player->player_y = player->player_y + 1;
	player->movements++;
	ft_printf("Movimientos: %s%d\n", COLOR_NORMAL, player->movements);
	draw_map(map, img);
}

void	go_right(t_map *map, t_player *player, t_img *img)
{
	if (map->map[player->player_y][player->player_x + 1] == 'C')
		coin_counter(map);
	map->map[player->player_y][player->player_x + 1] = 'P';
	map->map[player->player_y][player->player_x] = '0';
	player->player_x = player->player_x + 1;
	player->movements++;
	ft_printf("Movimientos: %s%d\n", COLOR_NORMAL, player->movements);
	draw_map(map, img);
}

void	go_left(t_map *map, t_player *player, t_img *img)
{
	if (map->map[player->player_y][player->player_x - 1] == 'C')
		coin_counter(map);
	map->map[player->player_y][player->player_x - 1] = 'P';
	map->map[player->player_y][player->player_x] = '0';
	player->player_x = player->player_x - 1;
	player->movements++;
	ft_printf("Movimientos: %s%d\n", COLOR_NORMAL, player->movements);
	draw_map(map, img);
}

int	detect_key(int key_code, t_map *map)
{
	if (key_code == ESC)
		end_game();
	if (map->coins == 0 && ((key_code == A
				&& map->map[map->player.player_y][map->player.player_x - 1] == 'E')
		|| (key_code == D && map->map[map->player.player_y][map->player.player_x + 1] == 'E')
		|| (key_code == S && map->map[map->player.player_y + 1][map->player.player_x] == 'E')
		|| (key_code == W
			&& map->map[map->player.player_y - 1][map->player.player_x] == 'E')))
		win_game(map);
	if (key_code == A && map->map[map->player.player_y][map->player.player_x - 1] != 'E'
		&& key_code == A && map->map[map->player.player_y][map->player.player_x - 1] != '1')
		go_left(map, &map->player, &map->img);
	if (key_code == D && map->map[map->player.player_y][map->player.player_x + 1] != 'E'
		&& key_code == D && map->map[map->player.player_y][map->player.player_x + 1] != '1')
		go_right(map, &map->player, &map->img);
	if (key_code == S && map->map[map->player.player_y + 1][map->player.player_x] != 'E'
		&& key_code == S && map->map[map->player.player_y + 1][map->player.player_x] != '1')
		go_down(map, &map->player, &map->img);
	if (key_code == W && map->map[map->player.player_y - 1][map->player.player_x] != 'E'
		&& key_code == W && map->map[map->player.player_y - 1][map->player.player_x] != '1')
		go_up(map, &map->player, &map->img);
	return (1);
}