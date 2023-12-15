/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:40:05 by tpaesch           #+#    #+#             */
/*   Updated: 2023/12/15 17:51:59 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		exit(0);
	}
}

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(600, 400, "so_long", true);
	mlx_key_hook(mlx, on_key_pressed, NULL);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
