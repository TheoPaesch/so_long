/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:02:08 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/11 18:43:25 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	cc;

	if (n == 0)
		return (0);
	cc = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (n - 1 > i && str[i] != cc)
		i++;
	if (str[i] == cc)
		return ((void *) &str[i]);
	return (0);
}
