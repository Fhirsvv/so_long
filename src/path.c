/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:58:27 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/04 18:49:04 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	flood_fill_from_player(t_map *map, int column, int row)
{			
	
	// printf("MAPA:%s\n", map->map[0]);
	// printf("MAPA:%s\n", map->map[1]);
	// printf("MAPA:%s\n", map->map[2]);
	// printf("------------------------\n");
	if (map->map[column][row] != '1')
	{		
		if (map->map[column][row] == 'C')
		{
			map->coins--;
			// ft_printf("COIN:%i\n", map->coins);
			}
		map->map[column][row] = '1';
		if (map->map[column][row + 1] != '1'
			&& map->map[column][row + 1] != 'E')
			flood_fill_from_player(map, column, row + 1);
		if (map->map[column][row - 1] != '1'
			&& map->map[column][row - 1] != 'E')
			flood_fill_from_player(map, column, row - 1);
		if (map->map[column + 1][row] != '1'
			&& map->map[column + 1][row] != 'E')
			flood_fill_from_player(map, column + 1, row);
		if (map->map[column - 1][row] != '1'
			&& map->map[column - 1][row] != 'E')
			flood_fill_from_player(map, column - 1, row);
	}
	// ft_printf("COIN:%s%i\n",COLOR_RED ,map->coins);
	return (map->coins);
}

int	flood_fill_from_exit(t_map *map2, int column, int row)
{
	printf("floodfillfromexit:%s%i\n", COLOR_GREEN, map2->coins);
	
	if (map2->map[column][row] != '1')
	{
		if (map2->map[column][row] == 'C')
			map2->coins--;
		printf("floodfillfromexit:%s%i\n", COLOR_GREEN, map2->coins);
		map2->map[column][row] = '1';
		if (map2->map[column][row + 1] != '1')
			flood_fill_from_exit(map2, column, row + 1);
		if (map2->map[column][row - 1] != '1')
			flood_fill_from_exit(map2, column, row - 1);
		if (map2->map[column + 1][row] != '1')
			flood_fill_from_exit(map2, column + 1, row);
		if (map2->map[column - 1][row] != '1')
			flood_fill_from_exit(map2, column - 1, row);
	}	
	// printf("%s%i\n", COLOR_BLUE, map->coins);
	return (map2->coins);
}


void	check_path(t_map map, t_map map2)
{
	int i;
	int j;

	printf("%i\n", map.coins);printf("MAPA:%s\n", map2.map[0]);
	printf("MAPA:%s\n", map2.map[1]);
	printf("MAPA:%s\n\n", map2.map[2]);
	i = flood_fill_from_player(&map, map.player.player_y, map.player.player_x);
	printf("MAPA:%s\n", map2.map[0]);
	printf("MAPA:%s\n", map2.map[1]);
	printf("MAPA:%s\n", map2.map[2]);
	j = flood_fill_from_exit(&map2, map2.exit_y, map2.exit_x);
	
	printf("COINs1:%i\n", i);
	printf("COINs2:%i\n", j);
	if (i > 0 || j > 0)
		ft_error(9, &map);
}

void	ft_error(int n, t_map *map)
{
	if (n == 1)
		ft_printf("%sError\nNo such file or directory! \n", COLOR_RED);
	else if (n == 2)
		ft_printf("%sError\nUsage: ./so_long maps/<filename>.ber \n", COLOR_RED);
	else if (n == 3)
		ft_printf("%sError\nTry create one valid map! \n", COLOR_RED);
	else if (n == 4)
		ft_printf("%sError\nMap has invalid characters! \n", COLOR_RED);
	else if (n == 5)
		ft_printf("%sError\nMap is not a rectangle! \n", COLOR_RED);
	else if (n == 6)
		ft_printf("%sError\nMap is not surrounded by walls! \n", COLOR_RED);
	else if (n == 7)
		ft_printf("%sError\nKey data in map is missing or incorrect \n",
			COLOR_RED);
	else if (n == 8)
		ft_printf("%sError\nTwo arguments please \n", COLOR_RED);
	else if (n == 9)
		ft_printf("%sError\nMap has not a valid path\n", COLOR_RED);
	else if (n == 10)
		ft_printf("%sError\nFailed to open the image.\n", COLOR_RED);
	if (map->status == 1)
		free_map(map);
	exit(n);
}