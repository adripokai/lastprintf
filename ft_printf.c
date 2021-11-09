/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:01:14 by ajuan             #+#    #+#             */
/*   Updated: 2021/11/09 10:36:48 by ajuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list			ap;
	int				i;
	int				size;

	va_start(ap, s);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == '%')
			size += ft_getflag(s[++i], ap);
		else
			size += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (size);
}
