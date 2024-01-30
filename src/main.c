/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:40:05 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/30 16:36:54 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_so_long		solong;
	t_flood_result	result;

	solong.moves = 0;
	filecheck(argc, argv);
	if (map_get_size(argv[1], &solong))
	{
		sl_error(10);
		exit(EXIT_FAILURE);
	}
	if (map_parse(argv[1], &solong))
		error_exit(10, solong);
	sl_rowcheck(&solong);
	sl_columncheck(&solong);
	get_structinfo(&solong);
	sl_rectanglecheck(&solong);
	map_valid(solong, &result);
	solong.mlx = mlx_init(solong.columns * PXL,
			solong.rows * PXL, "SUPA MURIU", false);
	if (!solong.mlx)
		error_exit(11, solong);
	load_images(&solong);
	mlx_key_hook(solong.mlx, on_key_pressed, &solong);
	mlx_loop(solong.mlx);
	end_exit(&solong, 0);
}
