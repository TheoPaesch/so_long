/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:02:29 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/20 13:58:05 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	int		i;
	char	*str2;

	i = 0;
	while (str1[i] != '\0')
		i++;
	str2 = malloc ((i + 1) * sizeof(char));
	if (str2 == NULL)
		return (str2);
	i = 0;
	while (str1[i] != '\0')
	{
		str2[i] = str1[i];
		i++;
	}
	if (str1[i] == '\0')
		str2[i] = '\0';
	return (str2);
}
