/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:30:51 by ecortes-          #+#    #+#             */
/*   Updated: 2024/07/11 12:16:49 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_floor(t_map *map, t_img *img)
{
	int	column;
	int	row;

	column = 0;
	while (map->map[column])
	{
		row = 0;
		while (map->map[column][row])
		{
			mlx_put_image_to_window(map->mlx, map->win, img->floor_img,
				row * 56, column * 56);
			row++;
		}
		column++;
	}
}

void	draw_elements(int column, int row, t_map *map, t_img *img)
{
	if (map->map[column][row] == '1')
		mlx_put_image_to_window(map->mlx, map->win, img->walls_img,
			row * 56, column * 56);
	if (map->map[column][row] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, img->player_img,
			row * 56, column * 56);
	if (map->map[column][row] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, img->coins_img,
			row * 56, column * 56);
	if (map->map[column][row] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, img->exit_img,
			row * 56, column * 56);
}

void	draw_map(t_map *map, t_img *img)
{
	int	columns;
	int	row;

	columns = 0;
	draw_floor(map, img);
	while (map->map[columns])
	{
		row = 0;
		while (map->map[columns][row])
		{
			draw_elements(columns, row, map, img);
			row++;
		}
		columns++;
	}
}
