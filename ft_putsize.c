/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:04:27 by ajuan             #+#    #+#             */
/*   Updated: 2021/11/09 10:23:43 by ajuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putbase(unsigned long long nb, char *base)
{
	if (nb >= ft_strlen(base))
		putbase(nb / ft_strlen(base), base);
	ft_putchar_fd(base[nb % ft_strlen(base)], 1);
}

int	ft_putsize(unsigned long long i, char *base, void *ptr)
{
	int	size;

	if (ptr)
		i = (unsigned long long)ptr;
	size = 0;
	putbase(i, base);
	if (i == 0)
		return (1);
	while (i)
	{
		i /= ft_strlen(base);
		size++;
	}
	return (size);
}
