/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 12:46:32 by bavram            #+#    #+#             */
/*   Updated: 2017/12/04 16:48:07 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(*str) * (ft_strlen(src) + 1));
	if (str == (char *)0)
	{
		return (str);
	}
	i = 0;
	while (*(src + i) != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
