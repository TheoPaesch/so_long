/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:33:35 by tpaesch           #+#    #+#             */
/*   Updated: 2023/11/02 11:29:48 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_logic(int n, int *i)
{
	int	temp;

	temp = 0;
	if (n < 0)
	{
		temp = write (1, "-", 1);
		if (temp == -1)
			return (-1);
		*i += temp;
		n = -n;
	}
	temp = 0;
	if (n > 9)
	{
		if (num_logic(n / 10, i) == -1)
			return (-1);
	}
	temp = write (1, &"0123456789"[n % 10], 1);
	if (temp == -1)
		return (-1);
	*i += temp;
	return (*i);
}

int	print_num(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	if (num_logic(n, &i) == -1)
		return (-1);
	return (i);
}

int	print_dec(unsigned int n)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	if (n > 9)
	{
		temp = print_dec(n / 10);
		if (temp == -1)
			return (-1);
		i += temp;
	}
	temp = 0;
	temp = write (1, &"0123456789"[n % 10], 1);
	if (temp == -1)
		return (-1);
	i += temp;
	return (i);
}
