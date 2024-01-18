/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:27:31 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/17 17:23:49 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	filecheck1(int argc, char **argv)
{
	int			i;
	const char	*ber = ".ber";

	if (argc == 2 && ft_strlen(argv[1]) >= 4)
	{
		i = 0;
		while (i++ != 5)
		{
			if (argv[1][ft_strlen(argv[1] - 4 + i)] != ber[i])
			{
				sl_error(1);
				exit(1);
			}
		}
	}
}

void	filecheck2(int argc, char **argv, t_so_long solong)
{
	if (argc > 2 || argc < 2)
	{
		sl_error(argc + 20);
		exit(1);
	}
	else if (ft_strlen(argv[1]) < 4)
	{
		sl_error(2);
		exit(1);
	}
}

void	sl_rowcheck(t_so_long *solong)
{
	int	i;

	i = 0;
	while (i < solong->rows)
	{
		if (solong->map[i][0] != WALL)
			error_exit(3);
		else if (solong->map[i][solong->columns - 1] != WALL)
			error_exit(4);
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
			error_exit(5);
		if (solong->map[solong->rows - 1][i] != WALL)
			error_exit(6);
		i++;
	}
}

void	get_structinfo(t_so_long *solong)
{
	int	x;
	int	y;

	y = 0;
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
		error_exit(7);
	while (i < solong->rows)
	{
		if (ft_strlen(solong->map[i]) != solong->columns)
			error_exit(8);
		i++;
	}
}
