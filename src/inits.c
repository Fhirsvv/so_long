/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:40:05 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/05 15:34:49 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init (t_map *map)
{
	map->coins = 0;
	map->exit = 0;
	map->player.n_player = 0;
	map->player.movements = 0;
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->map_height * 56,
			map->map_width * 56, "So_Long");
	map->img.player_img = mlx_xpm_file_to_image(map->mlx, PLAYER,
			&map->img_width, &map->img_height);
	map->img.coins_img = mlx_xpm_file_to_image(map->mlx, COIN,
			&map->img_width, &map->img_height);
	map->img.walls_img = mlx_xpm_file_to_image(map->mlx, WALL,
			&map->img_width, &map->img_height);
	map->img.exit_img = mlx_xpm_file_to_image(map->mlx, EXIT,
			&map->img_width, &map->img_height);
	map->img.floor_img = mlx_xpm_file_to_image(map->mlx, FLOOR,
			&map->img_width, &map->img_height);
	if (map->img.player_img == NULL || map->img.coins_img == NULL
		|| map->img.walls_img == NULL || map->img.exit_img == NULL
		|| map->img.floor_img == NULL)
		ft_error(10, map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}
