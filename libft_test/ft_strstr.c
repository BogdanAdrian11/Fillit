/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 13:51:03 by bavram            #+#    #+#             */
/*   Updated: 2017/12/04 17:35:15 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i_str;
	int		j_str;
	int		i_tofind;

	if (*(to_find) == '\0')
		return ((char *)str);
	i_str = 0;
	while (*(str + i_str) != '\0')
	{
		i_tofind = 0;
		j_str = i_str;
		while (*(str + j_str) == *(to_find + i_tofind) &&
				(*(str + j_str) != '\0') && (*(to_find + i_tofind)))
		{
			j_str++;
			i_tofind++;
		}
		if (j_str - i_str == i_tofind &&
				i_tofind != 0 && *(to_find + i_tofind) == '\0')
			return ((char *)(str + i_str));
		i_str++;
	}
	return ((char *)0);
}
