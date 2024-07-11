/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:48:38 by ecortes-          #+#    #+#             */
/*   Updated: 2024/07/11 13:27:44 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//si no es un simbolo permitido out
int	check_map(t_map *map)
{
	int		row;
	int		column;

	column = 0;
	while (map->map[column])
	{
		row = 0;
		while (map->map[column][row])
		{
			if (map->map[column][row] != '0' && map->map[column][row] != '1' &&
				map->map[column][row] != 'C' && map->map[column][row] != 'E' &&
				map->map[column][row] != 'P')
				ft_error(4, map);
			row++;
		}
		column++;
	}
	return (1);
}

//posicin a posicion viendo que hay y guardando el numero de cosas
void	count_elements(t_map *map, t_player *player)
{
	int		column;
	int		row;	

	column = -1;
	while (map->map[++column])
	{
		row = -1;
		while (map->map[column][++row])
		{
			if (map->map[column][row] == 'C')
				map->coins++;
			else if (map->map[column][row] == 'E')
				assign_exit(column, row, map);
			else if (map->map[column][row] == 'P')
			{
				player->player_y = column;
				player->player_x = row;
				player->n_player++;
			}
		}
	}
	if (map->coins < 1 || map->exit != 1 || player->n_player != 1)
		ft_error(7, map);
	map->coins_2 = map->coins;
	map->coins_3 = map->coins;
}

void	check_rectangle(t_map *map)
{
	size_t	columns;

	columns = 0;
	map->map_width = 0;
	map->map_height = ft_strlen(map->map[columns]);
	while (map->map[columns])
	{
		map->map_width++;
		columns++;
	}
	columns = 0;
	while (map->map_width > columns)
	{
		if (map->map_height != ft_strlen(map->map[columns]))
			ft_error(5, map);
		columns++;
	}
}

int	check_border(t_map *map)
{
	int		column;
	int		row;	

	column = 0;
	while (map->map[column])
	{
		row = 0;
		while (map->map[column][row])
		{
			if (map->map[0][row] != '1'
				|| map->map[column][0] != '1'
				|| map->map[map->map_width - 1][row] != '1'
				|| map->map[column][map->map_height - 1] != '1')
				ft_error(6, map);
			row++;
		}
		column++;
	}
	return (1);
}
