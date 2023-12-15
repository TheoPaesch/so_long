/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:00:18 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/09 19:20:28 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	temp;
	int	cnt2;

	cnt2 = 1;
	i = 0;
	temp = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		cnt2++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		temp = (temp * 10) + (str[i] - '0');
		i++;
	}
	if (cnt2 == 2)
		temp = (temp * (-1));
	return (temp);
}
