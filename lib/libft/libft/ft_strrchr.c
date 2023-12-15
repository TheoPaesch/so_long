/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:02:45 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/15 13:27:30 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*adress;
	int		i;
	char	tst;

	tst = (char)c;
	adress = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == tst)
			adress = (char *)&s[i];
		i++;
	}
	if (tst == s[i])
		return ((char *)&s[i]);
	return (adress);
}
