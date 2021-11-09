/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:47:04 by ajuan             #+#    #+#             */
/*   Updated: 2021/11/09 11:40:30 by ajuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*dest;

	dest = malloc ((sizeof(char)) * (ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static int	intlen(int a)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	if (a <= 0)
	{
		neg = 1;
		a *= -1;
	}
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i + neg);
}

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*s;

	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	len = intlen(n);
	s = malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	s[len] = 0;
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
		neg = 1;
	}
	while (len-- > 0 + neg)
	{
		s[len] = n % 10 + 48;
		n /= 10;
	}
	return (s);
}
