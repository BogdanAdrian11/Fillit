/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:59:36 by bavram            #+#    #+#             */
/*   Updated: 2017/12/01 19:07:27 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			str = (char *)(s + i);
			return (str);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		str = (char *)(s + i);
		return (str);
	}
	return (NULL);
}
