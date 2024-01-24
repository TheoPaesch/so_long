/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:46:46 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/24 00:03:38 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	on_key_pressed(mlx_key_data_t key_data, void *param)
{
	t_so_long	*solong;

	if (key_data.action != MLX_PRESS)
		return ;
	solong = param;
	if ((key_data.key == MLX_KEY_UP) || (key_data.key == MLX_KEY_W))
		player_movement(solong, solong->player.x, solong->player.y - 1, 'W');
	else if ((key_data.key == MLX_KEY_DOWN) || key_data.key == MLX_KEY_S)
		player_movement(solong, solong->player.x, solong->player.y + 1, 'S');
	else if ((key_data.key == MLX_KEY_RIGHT) || (key_data.key == MLX_KEY_D))
		player_movement(solong, solong->player.x + 1, solong->player.y, 'D');
	else if ((key_data.key == MLX_KEY_LEFT) || (key_data.key == MLX_KEY_A))
		player_movement(solong, solong->player.x - 1, solong->player.y, 'A');
	else if (key_data.key == MLX_KEY_ESCAPE)
	{
		end_exit(solong, 0);
		exit(0);
	}
}

void	player_movement(t_so_long *solong, int x, int y, char dir)
{
	if (solong->map[y][x] == '0')
		reload(solong, x, y, dir);
	else if (solong->map[y][x] == 'C')
	{
		solong->coins--;
		reload(solong, x, y, dir);
	}
	else if (solong->map[y][x] == 'E' && solong->coins == 0)
	{
		reload(solong, x, y, dir);
		end_exit(solong, 1);
	}
}

void	reload(t_so_long *sl, int x, int y, char dir)
{
	static int	i = 0;

	i++;
	ft_printf("%i\n", i);
	mlx_image_to_window(sl->mlx, sl->grass, sl->player.x * PXL,
		sl->player.y * PXL);
	sl->map[sl->player.y][sl->player.x] = '0';
	sl->map[y][x] = 'P';
	sl->player.y = y;
	sl->player.x = x;
	mlx_image_to_window(sl->mlx, sl->grass, x * PXL, y * PXL);
	if (dir == 'W')
		mlx_image_to_window(sl->mlx, sl->mario_back, sl->player.x * PXL,
			sl->player.y * PXL);
	else if (dir == 'S')
		mlx_image_to_window(sl->mlx, sl->mario_front, sl->player.x * PXL,
			sl->player.y * PXL);
	else if (dir == 'A')
		mlx_image_to_window(sl->mlx, sl->mario_left, sl->player.x * PXL,
			sl->player.y * PXL);
	else if (dir == 'D')
		mlx_image_to_window(sl->mlx, sl->mario_right, sl->player.x * PXL,
			sl->player.y * PXL);
}
