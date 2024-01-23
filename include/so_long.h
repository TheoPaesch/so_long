/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:40:19 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/23 20:08:52 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/ft_printf.h"
# include <math.h>
# include <stdlib.h>
# define SO_LONG_H
# define WALL '1'
# define COINS 'C'
# define FLOOR '0'
# define PLAYER 'P'
# define MAP_EXIT 'E'
# define PXL 32

typedef struct s_position
{
	int	y;
	int	x;
}	t_position;

typedef struct s_so_long
{
	char			**map;
	int32_t			rows;
	int32_t			columns;
	int32_t			coins;
	int32_t			players;
	int32_t			exit;
	mlx_t			*mlx;
	mlx_image_t		*coin_front;
	mlx_image_t		*coin_side;
	mlx_image_t		*grass;
	mlx_image_t		*koopa;
	mlx_image_t		*mario_back;
	mlx_image_t		*mario_front;
	mlx_image_t		*mario_left;
	mlx_image_t		*mario_right;
	mlx_image_t		*wall;
	mlx_image_t		*peach;
	t_position		player;
}	t_so_long;

typedef struct s_flood_result
{
	int	coins;
	int	exit;
}	t_flood_result;

int		map_get_size(const char *fspath, t_so_long *solong);
int		map_parse(const char *fspath, t_so_long *data);
int		dup_map(t_so_long solong, char ***dup);
void	filecheck(int argc, char **argv);
void	sl_rowcheck(t_so_long *solong);
void	sl_columncheck(t_so_long *solong);
void	get_structinfo(t_so_long *solong);
void	sl_rectanglecheck(t_so_long *solong);
void	sl_error(int e);
void	sl_error_2(int e);
void	map_free(char **map, int i);
void	flood_fill(char **map, t_position pos, t_flood_result *result);
void	on_key_pressed(mlx_key_data_t key_data, void *param);
void	error_exit(int e, t_so_long solong);
int		ft_malloc_str_arr(size_t size, char ***arr);
void	player_movement(t_so_long *solong, int x, int y, char dir);
void	map_valid(t_so_long solong, t_flood_result *result);
void	end_exit(t_so_long *solong, int id);
int		load_images(t_so_long *sl);
void	im_to_win(t_so_long *sl);
int		load_texture(const char *fspath, mlx_image_t **tex, mlx_t *mlx);
void	reload(t_so_long *sl, int32_t x, int32_t y, char dir);

#endif