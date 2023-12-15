/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:33:57 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/22 14:39:23 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	length(int n, int *len)
{
	if (n == 0)
	{
		*len = 1;
		return ;
	}
	if (n < 0)
	{
		(*len)++;
		n *= -1;
	}
	while (n > 0)
	{
		(*len)++;
		n /= 10;
	}
}

static void	reverse_dup(int n, char *str)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (neg)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
}

static void	ft_strrev(char *str, int len)
{
	int		i;
	char	tmp;

	len--;
	i = 0;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	length(n, &len);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	reverse_dup(n, str);
	ft_strrev(str, len);
	return (str);
}
