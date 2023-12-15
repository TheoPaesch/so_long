/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:33:57 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/21 15:37:36 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*arnold;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	if (end == 0)
		return (ft_calloc(1, 1));
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > start && ft_strchr(set, s1[end]) != NULL)
		end--;
	arnold = malloc(((end - start) + 2) * sizeof(char));
	if (arnold == NULL)
		return (NULL);
	while (start <= end)
		arnold[i++] = s1[start++];
	arnold[i] = '\0';
	return (arnold);
}
