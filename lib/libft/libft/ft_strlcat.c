/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:02:32 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/24 12:50:43 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	if (dstsize == 0 && dst == NULL)
		return (0);
	i = 0;
	len = ft_strlen(dst);
	if (!src || dstsize <= len)
		return (dstsize + ft_strlen(src));
	while (src[i] && len + i + 1 < dstsize)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}
