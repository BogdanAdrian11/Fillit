/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:53:00 by bavram            #+#    #+#             */
/*   Updated: 2017/12/04 17:29:22 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t n;
	size_t i;

	n = 0;
	while (*(dest + n) != '\0')
	{
		n++;
	}
	i = 0;
	while (*(src + i) != '\0' && i < nb)
	{
		*(dest + n) = *(src + i);
		i++;
		n++;
	}
	*(dest + n) = '\0';
	return (dest);
}
