/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:33:57 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/24 17:14:03 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	helper(size_t *len, unsigned int *start, const char *s)
{
	size_t	tmp;

	if (((*len) - (*start)) > ft_strlen(s))
	{
		if ((*len) < (*start))
			tmp = (*start) - (*len);
		else
			tmp = ft_strlen(s) - *start;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
	{
		substr = ft_calloc(1, sizeof(char));
		if (!substr)
			return (NULL);
		return (substr);
	}
	i = 0;
	helper(&len, &start, s);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = ft_calloc((len + 1), sizeof(char));
	if (!substr)
		return (NULL);
	while (i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
