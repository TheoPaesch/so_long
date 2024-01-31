/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:02:36 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/13 14:20:42 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #include <stdio.h>

char	*fusion(char *st_buffer, char *read_input)
{
	char	*haa;

	haa = gnl_strjoin(st_buffer, read_input);
	if (!haa)
		return (NULL);
	free(st_buffer);
	return (haa);
}

char	*newline_handeling(char *st_buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (st_buffer[i] && st_buffer[i] != '\n')
		i++;
	if (st_buffer[i] == '\n')
		i++;
	if (!st_buffer[i])
		return (free(st_buffer), NULL);
	temp = gnl_calloc(((gnl_strlen(st_buffer) - i) + 1), sizeof(char));
	if (temp == NULL)
		return (free(st_buffer), NULL);
	while (st_buffer[i] && st_buffer[i] != '\0')
		temp[j++] = st_buffer[i++];
	free(st_buffer);
	return (temp);
}

char	*line_extraction(char *st_buffer)
{
	int		i;
	char	*temp;

	i = 0;
	if (!st_buffer[i])
		return (NULL);
	while (st_buffer[i] && st_buffer[i] != '\n')
		i++;
	if (st_buffer[i] == '\n')
		i++;
	temp = gnl_calloc(i + 1, sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (st_buffer[i] && st_buffer[i] != '\n')
	{
		temp[i] = st_buffer[i];
		i++;
	}
	if (st_buffer[i] == '\n')
		temp[i] = st_buffer[i];
	return (temp);
}

char	*de_read_sandstorm(int fd, char *st_buffer)
{
	char	read_input[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = read(fd, read_input, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		read_input[bytes_read] = '\0';
		st_buffer = fusion(st_buffer, read_input);
		if (!st_buffer)
			return (NULL);
		if (gnl_strchr(read_input, '\n') || bytes_read == 0)
			break ;
		bytes_read = read(fd, read_input, BUFFER_SIZE);
	}
	if (bytes_read <= 0 && st_buffer[0] == '\0')
		return (free(st_buffer), NULL);
	return (st_buffer);
}

char	*get_next_line(int fd)
{
	static char	*st_buffer = NULL;
	char		*line;

	if (st_buffer == NULL)
	{
		st_buffer = gnl_calloc(1, 1);
		if (st_buffer == NULL)
			return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(st_buffer);
		st_buffer = NULL;
		return (NULL);
	}
	st_buffer = de_read_sandstorm(fd, st_buffer);
	if (!st_buffer)
		return (NULL);
	line = line_extraction(st_buffer);
	if (line == NULL)
		return (free(st_buffer), st_buffer = NULL, NULL);
	st_buffer = newline_handeling(st_buffer);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	fd;
// 	int	i;

// 	i = 1;
// 	fd = open("files/one_line_no_nl.txt", O_RDONLY);
// 	while (i <= 20)
// 	{
// 		printf("\nCall #%d: %s", i, get_next_line(fd));
// 		i++;
// 	}
// }
