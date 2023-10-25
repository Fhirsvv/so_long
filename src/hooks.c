/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:33:15 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/25 15:25:03 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//*: Asignación movimientos (arriba, abajo, dcha, izq)
#include "../include/so_long.h"

void	go_up(t_map *map)
{
	if (map->map[map->player_y - 1][map->player_x] == 'C')
		coin_counter(map);
	map->map[map->player_y - 1][map->player_x] = 'P';
	map->map[map->player_y][map->player_x] = '0';
	map->player_y = map->player_y - 1;
	map->movements++;
	ft_printf("\nMovimientos: %d", map->movements);
}

void	go_down(t_map *map)
{
	if (map->map[map->player_y + 1][map->player_x] == 'C')
		coin_counter(map);
	map->map[map->player_y + 1][map->player_x] = 'P';
	map->map[map->player_y][map->player_x] = '0';
	map->player_y = map->player_y + 1;
	map->movements++;
	ft_printf("\nMovimientos: %d", map->movements);
}

void	go_right(t_map *map)
{
	if (map->map[map->player_y][map->player_x + 1] == 'C')
		coin_counter(map);
	map->map[map->player_y][map->player_x + 1] = 'P';
	map->map[map->player_y][map->player_x] = '0';
	map->player_x = map->player_x + 1;
	map->movements++;
	ft_printf("\nMovimientos: %d", map->movements);
}

void	go_left(t_map *map)
{
	if (map->map[map->player_y][map->player_x - 1] == 'C')
		coin_counter(map);
	map->map[map->player_y][map->player_x - 1] = 'P';
	map->map[map->player_y][map->player_x] = '0';
	map->player_x = map->player_x + 1;
	map->movements++;
	ft_printf("\nMovimientos: %d", map->movements);
}

//* FUNCION PARA GANAR CUANDO RECOJA TODAS LAS MONEDAS				
int	detect_key(int key_code, t_map *map)
{	
	printf("%s\n","hola");
	printf("%i\nCOLUMN", map->player_y);
	printf("%i\nrow", map->player_x);
	if (key_code == ESC)
		end_game();
	if (map->coins == 0 && ((key_code == A
				&& map->map[map->player_y][map->player_x - 1] == 'E')
		|| (key_code == D && map->map[map->player_y][map->player_x + 1] == 'E')
		|| (key_code == S && map->map[map->player_y + 1][map->player_x] == 'E')
		|| (key_code == W
			&& map->map[map->player_y - 1][map->player_x] == 'E')))
		win_game(map);
	if (key_code == A && map->map[map->player_y][map->player_x - 1] != 'E'
		&& key_code == A && map->map[map->player_y][map->player_x - 1] != '1')
		go_left(map);
	if (key_code == D && map->map[map->player_y][map->player_x + 1] != 'E'
		&& key_code == D && map->map[map->player_y][map->player_x + 1] != '1')
		go_right(map);
	if (key_code == S && map->map[map->player_y + 1][map->player_x] != 'E'
		&& key_code == S && map->map[map->player_y + 1][map->player_x] != '1')
		go_down(map);
	if (key_code == W && map->map[map->player_y - 1][map->player_x] != 'E'
		&& key_code == W && map->map[map->player_y - 1][map->player_x] != '1')
		go_up(map);
	return (1);
}
