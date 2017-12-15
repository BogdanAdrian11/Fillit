/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:07:53 by bavram            #+#    #+#             */
/*   Updated: 2017/11/30 16:12:52 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		length;
	char	*str;

	length = ft_strlen((char *)s);
	while (length >= 0)
	{
		if (s[length] == (char)c)
		{
			str = (char *)(s + length);
			return (str);
		}
		length--;
	}
	return (NULL);
}
