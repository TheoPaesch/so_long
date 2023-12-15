/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:02:43 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/24 12:42:41 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0 && (haystack == NULL || needle == NULL))
		return (NULL);
	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j]
			&& haystack[i + j] != '\0' && (i + j) < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (NULL);
}
