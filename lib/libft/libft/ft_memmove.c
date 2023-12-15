/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:02:20 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/11 16:10:20 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*doc;
	unsigned char	*suc;

	doc = (unsigned char *)dst;
	suc = (unsigned char *)src;
	i = 0;
	if (doc < suc)
	{
		while (len > i)
		{
			doc[i] = suc[i];
			i++;
		}
	}
	else if (suc < doc)
	{
		i = len;
		while ((i) > 0)
		{
			i--;
			doc[i] = suc[i];
		}
	}
	return (dst);
}
