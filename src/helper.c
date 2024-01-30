/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:25:58 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/30 17:51:25 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	get_info(t_so_long *solong, int x, int y, int id)
{
	if (id == 1)
	{
		solong->players++;
		solong->player.x = x;
		solong->player.y = y;
	}
	if (id == 2)
	{
		solong->exit_x = x;
		solong->exit_y = y;
		solong->exit++;
	}
	if (solong->players > 1 || solong->exit > 1)
		error_exit(13, *solong);
}

int	map_parse(const char *fspath, t_so_long *data)
{
	int		fd;
	char	*line;
	int		i;

	if (ft_malloc_str_arr(data->rows, &data->map))
		return (1);
	fd = open(fspath, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_line(fd);
		if (line == NULL)
			break ;
		data->map[i] = line;
		i++;
	}
	close(fd);
	if (i != data->rows)
		return (map_free(data->map, i), 1);
	return (0);
}
