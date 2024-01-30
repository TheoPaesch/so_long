/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:24:22 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/30 19:03:15 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_error(int e)
{
	if (e == 1)
		ft_printf("%s", "this is the wrong file format!\n");
	if (e == 2)
		ft_printf("%s", "insufficient file! are you trolling?\n");
	if (e == 3)
		ft_printf("%s", "first row isn't all WALLS, map invalid.\n");
	if (e == 4)
		ft_printf("%s", "last row isn't all WALLS, map invalid.\n");
	if (e == 5)
		ft_printf("%s", "first column isn't all WALLS, map invalid.\n");
	if (e == 6)
		ft_printf("%s", "last column isn't all WALLS, map invalid.\n");
	if (e == 7)
		ft_printf("%s", "Map is not big enough.\n");
	if (e == 8)
		ft_printf("%s", "Map isn't a rectangle.\n");
	if (e == 9)
		ft_printf("%s", "No valid path. Or too many exits.\n");
	if (e == 10)
		ft_printf("%s", "something went wrong in mapparsing or mapsizing.\n");
	if (e == 11)
		ft_printf("%s", "mlx_init failed\n");
	if (e > 11)
		sl_error_2(e);
}

void	sl_error_2(int e)
{
	if (e == 12)
		ft_printf("%s", "map duplication failed!\n");
	if (e == 13)
		ft_printf("%s", "too many players or exits!\n");
	if (e == 14)
		ft_printf("%s", "no coins available!\n");
	if (e == 15)
		ft_printf("%s", "no exits!\n");
	if (e == 16)
		ft_printf("%s", "no player to be found!\n");
	if (e == 21 || e == 20)
		ft_printf("%s", "too few arguments!\n");
	if (e > 22)
		ft_printf("%s", "too many arguments!\n");
}

void	error_exit(int e, t_so_long solong)
{
	sl_error(e);
	map_free(solong.map, solong.rows);
	exit(EXIT_FAILURE);
}

void	end_exit(t_so_long *solong, int id)
{
	map_free(solong->map, solong->rows);
	mlx_close_window(solong->mlx);
	mlx_terminate(solong->mlx);
	if (id == 1)
	{
		ft_printf("%s", "\nYOU BEAT THE GAME!! YOU'RE SUCH A GREAT GAMER!!\n");
		exit(EXIT_SUCCESS);
	}
	if (id == 0)
	{
		ft_printf("%s", "\nsad gamer noises, why u no finish game?\n");
		exit(EXIT_FAILURE);
	}
}
