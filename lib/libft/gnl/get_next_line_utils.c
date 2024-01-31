/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:59:43 by tpaesch           #+#    #+#             */
/*   Updated: 2024/01/13 14:20:32 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_calloc(size_t count, size_t size)
{
	size_t	completesize;
	size_t	i;
	char	*str;

	i = 0;
	completesize = (count * size);
	str = malloc(completesize);
	if (str == NULL)
		return (NULL);
	while (i < completesize)
		str[i++] = '\0';
	return (str);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*go;

	if (s1 == NULL || s2 == NULL)
		return (free(s1), NULL);
	j = 0;
	i = 0;
	go = gnl_calloc((gnl_strlen(s1) + gnl_strlen(s2) + 1), sizeof(char));
	if (go == NULL)
		return (free(s1), NULL);
	while (s1[i] != '\0')
	{
		go[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		go[i] = s2[j];
		i++;
		j++;
	}
	return (go);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
