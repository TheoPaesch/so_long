/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:40:05 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/17 17:36:35 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void	on_key_pressed(mlx_key_data_t key_data, void *param)
{
	(void)param;
	if (key_data.key == MLX_KEY_UP)
	{
	}
	else if (key_data.key == MLX_KEY_DOWN)
	{
	}
	else if (key_data.key == MLX_KEY_RIGHT)
	{
	}
	else if (key_data.key == MLX_KEY_LEFT)
	{
	}
	else if (key_data.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(param);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_so_long		solong;
	t_flood_result	result;

	filecheck1(argc, argv);
	filecheck2(argc, argv, solong);
	if (map_parse(argv[1], &solong))
		error_exit();
	if (map_get_size(argv[1], &solong))
		error_exit();
	sl_rowcheck(&solong);
	sl_columncheck(&solong);
	get_structinfo(&solong);
	sl_rectanglecheck(&solong);
	map_valid(solong, &result);

}

// int	main(int argc, char **argv)
// {
// 	t_so_long solong;

// 	(void) argc;

// 	if (map_get_size(argv[1], &solong))
// 		return (1);
// 	printf("%d\n", solong.rows);
// 	printf("%d\n", solong.columns);
// 	if (map_parse(argv[1], &solong))
// 		return (1);
// 	while (*solong.map != NULL)
// 	{
// 		printf("%s\n", *solong.map);
// 		solong.map++;
// 	}


// 	// mlx_t	*mlx;

// 	// mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
// 	// if (!mlx)
// 	// 	error();
// 	// mlx = mlx_init(600, 400, "so_long", true);
// 	// mlx_key_hook(mlx, on_key_pressed, NULL);
// 	// mlx_loop(mlx);
// 	return (EXIT_SUCCESS);
// }