/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:30:38 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/30 17:51:21 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

char	*get_line(int fd)
{
	size_t	len;
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line);
	if (len == 0)
		return (line);
	len--;
	if (line[len] == '\n')
		line[len] = '\0';
	return (line);
}

int	ft_malloc(size_t size, void **ptr)
{
	*ptr = malloc(size);
	return (*ptr == NULL);
}

int	ft_malloc_str_arr(size_t size, char ***arr)
{
	if (ft_malloc((size + 1) * sizeof(char *), (void **) arr))
		return (1);
	(*arr)[size] = NULL;
	return (0);
}

int	map_get_size(const char *fspath, t_so_long *solong)
{
	char	*line;
	int		fd;
	int		len;

	fd = open(fspath, O_RDONLY);
	solong->rows = 0;
	solong->columns = 0;
	while (1)
	{
		line = get_line(fd);
		if (line == NULL)
			break ;
		len = ft_strlen(line);
		free(line);
		if (len == 0)
			return (close(fd), 1);
		if (solong->columns == 0)
			solong->columns = len;
		else if (len != solong->columns)
			return (close(fd), 1);
		solong->rows++;
	}
	close(fd);
	return (0);
}

void	map_free(char **map, int i)
{
	while (i--)
		free(map[i]);
	free(map);
}
