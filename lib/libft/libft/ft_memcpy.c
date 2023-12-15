/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:02:18 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/11 18:05:45 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*doc;
	unsigned char	*suc;
	size_t			i;

	if (dst == 0 && !src)
		return (NULL);
	doc = (unsigned char *)dst;
	suc = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		doc[i] = suc[i];
		i++;
	}
	return (doc);
}
