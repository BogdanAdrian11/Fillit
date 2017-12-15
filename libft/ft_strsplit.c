/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:52:21 by bavram            #+#    #+#             */
/*   Updated: 2017/12/02 14:51:53 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, int *max, char c)
{
	int		size;
	int		i;
	int		j;

	i = 0;
	size = 0;
	*max = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			size++;
			j = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (i - j > *max)
				*max = i - j;
		}
	}
	return (size);
}

static void	split(char *s, char **str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			j = 0;
			while (s[i] != c && s[i] != '\0')
			{
				str[k][j] = s[i];
				i++;
				j++;
			}
			str[k][j] = '\0';
			k++;
		}
	}
	str[k] = 0;
}

char		**ft_strsplit(char const *s, char c)
{
	int		size;
	int		word_max;
	int		i;
	char	**str;

	if (s == NULL)
		return (NULL);
	size = count_words((char *)s, &word_max, c);
	str = (char **)malloc(sizeof(str) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = (char *)malloc(sizeof(*str) * (word_max + 1));
		if (!str[i])
			return (NULL);
		i++;
	}
	split((char *)s, str, c);
	return (str);
}
