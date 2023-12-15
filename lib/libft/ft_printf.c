/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:16:08 by tpaesch           #+#    #+#             */
/*   Updated: 2023/11/02 11:37:18 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	switch_print(char c, va_list args)
{
	if (c == 'i' || c == 'd')
		return (print_num(va_arg(args, int)));
	else if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (print_pointer((unsigned long )va_arg(args, void *)));
	else if (c == 'u')
		return (print_dec(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (print_hexl(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (print_hexu(va_arg(args, unsigned int)));
	else if (c == '%')
		return (write(1, "%", 1));
	return (-1);
}

static int	helper(int *i, const char *str, va_list args)
{
	int	temp;
	int	temp2;

	temp2 = 0;
	temp = 0;
	if (str[*i] == '%')
	{
		temp = switch_print(str[++(*i)], args);
		if (temp == -1)
			return (-1);
		return (temp);
	}
	else
	{
		temp = write(1, &str[*i], 1);
		if (temp == -1)
			return (-1);
		return (1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		temp;
	int		temp2;

	temp = 0;
	temp2 = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		temp = helper(&i, str, args);
		if (temp == -1)
			return (-1);
		temp2 += temp;
		i++;
		temp = 0;
	}
	va_end(args);
	return (temp2);
}
