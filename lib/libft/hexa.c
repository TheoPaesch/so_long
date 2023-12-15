/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:58:18 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/31 19:10:05 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexl(unsigned int n)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	if (n > 15)
	{
		temp = print_hexl(n / 16);
		if (temp == -1)
			return (-1);
		i += temp;
	}
	temp = 0;
	temp = write (1, &"0123456789abcdef"[n % 16], 1);
	if (temp == -1)
		return (-1);
	i += temp;
	return (i);
}

int	print_hexu(unsigned int n)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	if (n > 15)
	{
		temp = print_hexu(n / 16);
		if (temp == -1)
			return (-1);
		i += temp;
	}
	temp = 0;
	temp = write (1, &"0123456789ABCDEF"[n % 16], 1);
	if (temp == -1)
		return (-1);
	i += temp;
	return (i);
}
