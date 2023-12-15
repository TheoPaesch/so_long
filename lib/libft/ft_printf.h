/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:10:05 by tpaesch           #+#    #+#             */
/*   Updated: 2023/10/31 19:09:18 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		print_num(int n);
int		print_char(char c);
int		print_string(char *g);
int		print_pointer(unsigned long n);
int		print_hexl(unsigned int n);
int		print_hexu(unsigned int n);
int		print_dec(unsigned int n);
void	pointer_help(unsigned long n, int *i);
#endif