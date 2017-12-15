/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 21:16:05 by bavram            #+#    #+#             */
/*   Updated: 2017/12/01 19:10:25 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power_of_ten(int nb)
{
	int i;

	i = 1;
	while (nb > 9)
	{
		i *= 10;
		nb /= 10;
	}
	return (i);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		power;
	int		digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	power = power_of_ten(n);
	while (power > 0)
	{
		digit = (n / power) % 10;
		c = digit + '0';
		write(fd, &c, 1);
		power /= 10;
	}
}
