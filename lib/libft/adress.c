/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:00:27 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/31 19:33:44 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pointer_help(unsigned long n, int *i)
{
	if (n > 15)
	{
		pointer_help(n / 16, i);
		(*i)++;
	}
	write (1, &"0123456789abcdef"[n % 16], 1);
}

int	print_pointer(unsigned long n)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	temp = write (1, "0x", 2);
	if (temp == -1)
		return (-1);
	pointer_help(n, &i);
	return (i + 3);
}

// #include <stdio.h>
// int	main()
// {
// 	unsigned long f = 12353452;
// 	int i = 0;

// 	printf("%p\n", (void *) f);

// 	print_pointer (f, &i);
// 	return (i);
// }
