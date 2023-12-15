/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:33:57 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/24 12:48:57 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*brr;
	unsigned int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	brr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (brr == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		brr[i] = f(i, s[i]);
		i++;
	}
	brr[i] = '\0';
	return (brr);
}
