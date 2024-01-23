/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:27:31 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/23 18:46:56 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	filecheck(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strncmp((argv[1] + (ft_strlen(argv[1]) - 4)), ".ber", 5) != 0)
		{
			sl_error(1);
			exit(EXIT_FAILURE);
		}
	}
	if (argc > 2 || argc < 2)
	{
		sl_error_2(argc + 20);
		exit(EXIT_FAILURE);
	}
	else if (ft_strlen(argv[1]) < 4)
	{
		sl_error(2);
		exit(EXIT_FAILURE);
	}
}

void	sl_rowcheck(t_so_long *solong)
{
	int	i;

	i = 0;
	while (i < solong->rows)
	{
		if (solong->map[i][0] != WALL)
			error_exit(3, *solong);
		else if (solong->map[i][solong->columns - 1] != WALL)
			error_exit(4, *solong);
		i++;
	}
}

void	sl_columncheck(t_so_long *solong)
{
	int	i;

	i = 0;
	while (i < solong->columns)
	{
		if (solong->map[0][i] != WALL)
			error_exit(5, *solong);
		if (solong->map[solong->rows - 1][i] != WALL)
			error_exit(6, *solong);
		i++;
	}
}

void	get_structinfo(t_so_long *solong)
{
	int	x;
	int	y;

	y = 0;
	solong->coins = 0;
	while (y < solong->rows)
	{
		x = 0;
		while (x < solong->columns)
		{
			if (solong->map[y][x] == COINS)
				solong->coins++;
			if (solong->map[y][x] == PLAYER)
			{
				solong->players++;
				solong->player.x = x;
				solong->player.y = y;
			}
			if (solong->map[y][x] == MAP_EXIT)
				solong->exit++;
			x++;
		}
		y++;
	}
}

void	sl_rectanglecheck(t_so_long *solong)
{
	int	i;

	i = 0;
	if (solong->columns < 4 && solong->rows < 4)
		error_exit(7, *solong);
	while (i < solong->rows)
	{
		if ((int)ft_strlen(solong->map[i]) != solong->columns)
			error_exit(8, *solong);
		i++;
	}
}
