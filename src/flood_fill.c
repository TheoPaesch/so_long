/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:13:26 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/30 17:46:13 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strdup2(char *str, char **dup)
{
	*dup = ft_strdup(str);
	return (*dup == NULL);
}

int	dup_map(t_so_long solong, char ***dup)
{
	int	i;

	if (ft_malloc_str_arr(solong.rows, dup))
		return (1);
	i = 0;
	while (i < solong.rows)
	{
		if (ft_strdup2(solong.map[i], &(*dup)[i]))
			return (map_free(*dup, i), 1);
		i++;
	}
	return (0);
}

void	flood_fill(char **map, t_position pos, t_flood_result *result)
{
	char	*tile;

	tile = &(map[pos.y][pos.x]);
	if (*tile == '1')
		return ;
	else if (*tile == 'C')
		result->coins--;
	else if (*tile == 'E')
		result->exit++;
	*tile = '1';
	flood_fill(map, (t_position){pos.y, pos.x + 1}, result);
	flood_fill(map, (t_position){pos.y + 1, pos.x}, result);
	flood_fill(map, (t_position){pos.y, pos.x - 1}, result);
	flood_fill(map, (t_position){pos.y - 1, pos.x}, result);
}

void	map_valid(t_so_long solong, t_flood_result *result)
{
	int		ret;
	char	**dup;

	ret = dup_map(solong, &dup);
	if (ret == 1)
		error_exit(12, solong);
	if (solong.coins == 0)
		error_exit(14, solong);
	if (solong.exit == 0)
		error_exit(15, solong);
	if (solong.players == 0)
		error_exit(16, solong);
	result->coins = solong.coins;
	result->exit = 0;
	flood_fill(dup, solong.player, result);
	if (result->coins != 0 || result->exit != 1)
	{
		map_free(dup, solong.rows);
		map_free(solong.map, solong.rows);
		sl_error(9);
		exit(1);
	}
	map_free(dup, solong.rows);
}
