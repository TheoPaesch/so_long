/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:13:26 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/17 15:19:27 by tpaesch          ###   ########.fr       */
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

	if (ft_malloc_str_arr(solong.rows, (void **) dup))
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
		result->exit = 1;
	*tile = '1';
	flood_fill(map, (t_position){pos.y, pos.x + 1}, result);
	flood_fill(map, (t_position){pos.y + 1, pos.x}, result);
	flood_fill(map, (t_position){pos.y, pos.x - 1}, result);
	flood_fill(map, (t_position){pos.y - 1, pos.x}, result);
}

void	map_valid(t_so_long solong, t_flood_result *result)
{
	char	**dup;

	dup = dup_map(solong, &dup);
	result->coins = solong.coins;
	flood_fill(dup, solong.player, &result);
	if (result->coins != 0 && result->exit != 1)
	{
		map_free(dup, solong.rows);
		sl_error(9);
	}
	map_free(dup, solong.rows);
}

// char **dup;
// t_flood_result result;
// result.coins = soglon.coins;
// result.exit = 0;

// dup_map(solong, &dup);
// flood_fill(dup, solong.player, &result);

// if (result.exit != 1 || reslt.coins != 0)
//  error