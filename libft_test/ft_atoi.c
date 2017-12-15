/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:48:42 by exam              #+#    #+#             */
/*   Updated: 2017/12/01 17:21:45 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int index;
	int negativ;
	int	nr;

	index = 0;
	negativ = 0;
	while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t'
		|| str[index] == '\v' || str[index] == '\f' || str[index] == '\r')
		index++;
	if (str[index] == '-')
	{
		negativ = 1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	nr = 0;
	while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9')
	{
		nr = nr * 10 - 48 + str[index];
		index++;
	}
	if (negativ == 1)
		nr = nr * (-1);
	return (nr);
}
