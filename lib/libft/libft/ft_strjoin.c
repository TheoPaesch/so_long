/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:33:57 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/24 12:51:32 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*go;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = 0;
	i = 0;
	go = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (go == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		go[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		go[i] = s2[j];
		i++;
		j++;
	}
	go[i] = '\0';
	return (go);
}
