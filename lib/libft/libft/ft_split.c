/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:33:57 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/24 17:17:39 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcounter(char const *s, char c)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			w++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (w);
}

static size_t	wordlen(const char *s, char c, int *i)
{
	size_t	j;

	j = 0;
	while (s[*i] == c)
		(*i)++;
	while (s[*i] != c && s[*i] != '\0')
	{
		(*i)++;
		j++;
	}
	return (j);
}

static char	**free_all(char **test)
{
	int	i;

	i = 0;
	while (test && test[i] != NULL)
	{
		free(test[i]);
		i++;
	}
	free(test);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		w;
	int		i;
	int		j;
	size_t	arnb;
	char	**test;

	if (s == NULL)
		return (NULL);
	i = 0;
	arnb = 0;
	w = wordcounter(s, c);
	test = (char **)ft_calloc((w + 1), sizeof(char *));
	if (!test)
		return (NULL);
	while (arnb < (unsigned long)w)
	{
		j = wordlen(s, c, &i);
		test[arnb] = ft_substr(s, (i - j), j);
		if (!test[arnb])
			return (free_all(test));
		arnb++;
	}
	test[arnb] = NULL;
	return (test);
}
