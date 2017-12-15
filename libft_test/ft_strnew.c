/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:33:29 by bavram            #+#    #+#             */
/*   Updated: 2017/12/01 17:15:01 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc((size + 1) * sizeof(*str));
	if (str)
	{
		i = 0;
		while (i <= size)
		{
			str[i] = '\0';
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}
