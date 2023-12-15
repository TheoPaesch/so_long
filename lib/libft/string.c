/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:35:52 by tpaesch           #+#    #+#             */
/*   Updated: 2023/11/02 11:18:49 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *g)
{
	int	i;
	int	temp;

	i = 0;
	if (g == NULL)
		return (write (1, "(null)", 6));
	while (g[i] != '\0')
	{
		temp = 0;
		temp = write(1, &g[i], 1);
		if (temp == -1)
			return (-1);
		i++;
	}
	return (i);
}
