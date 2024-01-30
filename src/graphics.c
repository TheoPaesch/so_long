/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:28:36 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/30 14:38:58 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_texture(const char *fspath, mlx_image_t **tex, mlx_t *mlx)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png(fspath);
	*tex = mlx_texture_to_image(mlx, temp);
	mlx_delete_texture(temp);
	return (*tex == NULL);
}

int	load_images(t_so_long *sl)
{
	if (load_texture("Images/grass.png", &sl->grass, sl->mlx))
		return (1);
	if (load_texture("Images/coin_front.png", &sl->coin_front, sl->mlx))
		return (1);
	if (load_texture("Images/mario_back.png", &sl->mario_back, sl->mlx))
		return (1);
	if (load_texture("Images/mario_front.png", &sl->mario_front, sl->mlx))
		return (1);
	if (load_texture("Images/mario_right.png", &sl->mario_right, sl->mlx))
		return (1);
	if (load_texture("Images/mario_left.png", &sl->mario_left, sl->mlx))
		return (1);
	if (load_texture("Images/wall.png", &sl->wall, sl->mlx))
		return (1);
	if (load_texture("Images/peach.png", &sl->peach, sl->mlx))
		return (1);
	im_to_win(sl);
	return (0);
}

void	im_to_win(t_so_long *sl)
{
	int32_t	x;
	int32_t	y;

	y = -1;
	while (++y < sl->rows)
	{
		x = -1;
		while (++x < sl->columns)
		{
			mlx_image_to_window(sl->mlx, sl->grass, x * PXL, y * PXL);
			if (sl->map[y][x] == '1')
				mlx_image_to_window(sl->mlx, sl->wall, x * PXL, y * PXL);
			else if (sl->map[y][x] == 'P')
				mlx_image_to_window(sl->mlx, sl->mario_front, x * PXL, y * PXL);
			else if (sl->map[y][x] == 'E' )
			{
				if (sl->coins == 0)
					mlx_image_to_window(sl->mlx, sl->peach, x * PXL, y * PXL);
				else
					mlx_image_to_window(sl->mlx, sl->grass, x * PXL, y * PXL);
			}
			else if (sl->map[y][x] == 'C')
				mlx_image_to_window(sl->mlx, sl->coin_front, x * PXL, y * PXL);
		}
	}
}
