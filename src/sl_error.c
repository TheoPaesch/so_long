/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:24:22 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/17 17:36:02 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_error(int e)
{
	if (e == 1)
		ft_printf("%s", "this is the wrong file format!");
	if (e == 2)
		ft_printf("%s", "insufficient file! are zou trolling?");
	if (e == 3)
		ft_printf("%s", "first row isn't all WALLS, map invalid.");
	if (e == 4)
		ft_printf("%s", "last row isn't all WALLS, map invalid.");
	if (e == 5)
		ft_printf("%s", "first column isn't all WALLS, map invalid.");
	if (e == 6)
		ft_printf("%s", "last column isn't all WALLS, map invalid.");
	if (e == 7)
		ft_printf("%s", "Map is not big enough.");
	if (e == 8)
		ft_printf("%s", "Map isn't a rectangle.");
	if (e == 9)
		ft_printf("%s", "Map has no valid path to complete.");
	if (e == 10)
		ft_printf("%s", "something went wrong in mapparsing or mapsizing.");
	if (e == 21 || e == 20)
		ft_printf("%s", "too few arguments!");
	if (e > 22)
		ft_printf("%s", "too many arguments!");
}

void	error_exit(int e, t_so_long solong)
{
	sl_error(e);
	map_free(solong.map, solong.rows);
	exit(1);
}
