/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:06:13 by bavram            #+#    #+#             */
/*   Updated: 2017/12/04 16:54:39 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l1;
	size_t	l2;
	size_t	i;

	i = 0;
	l1 = ft_strlen(dst);
	l2 = ft_strlen(src);
	if (size > (l1 + 1))
	{
		while (i < (size - l1 - 1))
		{
			dst[l1 + i] = src[i];
			i++;
		}
		dst[l1 + i] = '\0';
	}
	if (size >= l1)
	{
		return (l1 + l2);
	}
	return (l2 + size);
}
