/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:14:42 by ecortes-          #+#    #+#             */
/*   Updated: 2024/07/09 14:24:29 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_arguments(int argc, char *argv, t_map *map)
{
	size_t	len;

	if (argc != 2)
		ft_error(8, map);
	else
	{
		len = ft_strlen(argv);
		if (len < 4)
			ft_error(1, map);
		if ((ft_strncmp(".ber", argv + (len - 4), 4)))
			ft_error(2, map);
	}
}

void	read_map(char *argv, t_map *map)
{
	int		fd;
	char	*map_str[2];
	char	*aux_str;

	map_str[0] = ft_strdup("");
	fd = open(argv, O_RDONLY);
	if (!fd || fd < 0)
		ft_error(1, map);
	while (1)
	{
		aux_str = get_next_line(fd);
		if (!aux_str)
		{
			map->status = 0;
			break ;
		}
		map_str[1] = ft_strdup(map_str[0]);
		free(map_str[0]);
		map_str[0] = ft_strjoin_2(map_str[1], aux_str);
		free(aux_str);
	}
	map_copys(map_str[0], map);
	free(map_str[0]);
}

int	end_game(void)
{
	exit (0);
	return (0);
}

int	win_game(t_map *map)
{
	if (map->coins == 0)
	{
		ft_printf("%s%s\n", COLOR_GREEN, "CONGRATULATIONS! You win.");
		exit (0);
	}
	return (0);
}

void	coin_counter(t_map *map)
{
	map->coins--;
	if (map->coins == 0)
		ft_printf("%s%s\n", COLOR_GREEN,
			"Now find the exit");
}
