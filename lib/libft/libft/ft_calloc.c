/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:01:47 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/14 16:21:44 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*notastring;
	size_t	completesize;

	completesize = (count * size);
	notastring = malloc (count * size);
	if (notastring == NULL)
		return (NULL);
	ft_bzero (notastring, completesize);
	return (notastring);
}
