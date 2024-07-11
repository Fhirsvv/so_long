/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:58:27 by ecortes-          #+#    #+#             */
/*   Updated: 2024/07/11 13:28:35 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//desde el jugador mira las posines adyacentes, si hay moneda
//, se resta una moneda a la cantidad restante la cambias por pared
int	flood_fill_from_player(t_map *map, int column, int row)
{
	if (map->map_2[column][row] != '1')
	{
		if (map->map_2[column][row] == 'C')
			map->coins_2--;
		map->map_2[column][row] = '1';
		if (map->map_2[column][row + 1] != '1'
			&& map->map_2[column][row + 1] != 'E')
			flood_fill_from_player(map, column, row + 1);
		if (map->map_2[column][row - 1] != '1'
			&& map->map_2[column][row - 1] != 'E')
			flood_fill_from_player(map, column, row - 1);
		if (map->map_2[column + 1][row] != '1'
			&& map->map_2[column + 1][row] != 'E')
			flood_fill_from_player(map, column + 1, row);
		if (map->map_2[column - 1][row] != '1'
			&& map->map_2[column - 1][row] != 'E')
			flood_fill_from_player(map, column - 1, row);
	}
	return (map->coins_2);
}

// desde la salida mira las posiciones adyacentes, si hay moneda,
// se resta a la cantidad restante y se cambia por pared
int	flood_fill_from_exit(t_map *map, int column, int row)
{
	if (map->map_3[column][row] != '1')
	{
		if (map->map_3[column][row] == 'C')
			map->coins_3--;
		map->map_3[column][row] = '1';
		if (map->map_3[column][row + 1] != '1')
			flood_fill_from_exit(map, column, row + 1);
		if (map->map_3[column][row - 1] != '1')
			flood_fill_from_exit(map, column, row - 1);
		if (map->map_3[column + 1][row] != '1')
			flood_fill_from_exit(map, column + 1, row);
		if (map->map_3[column - 1][row] != '1')
			flood_fill_from_exit(map, column - 1, row);
	}
	return (map->coins_3);
}

//mediante los dos floodfill se debe poder coger todas as monedas
void	check_path(t_map *map)
{
	if (map->coins_2 > 0 || map->coins_3 > 0)
		ft_error(9, map);
}

void	ft_error(int n, t_map *map)
{
	if (n == 1)
		ft_printf("%sError\nNo such file or directory! \n", COLOR_RED);
	else if (n == 2)
		ft_printf("%sError\nUsage:./so_long maps/<filename>.ber\n", COLOR_RED);
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
