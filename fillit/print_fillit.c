/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtudor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:31:34 by mtudor            #+#    #+#             */
/*   Updated: 2017/12/15 18:39:25 by mtudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_fillit(char **fillit_output, int output_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < output_size)
	{
		j = 0;
		while (j < output_size)
		{
			ft_putchar(fillit_output[i][j]);
			j++;
		}
		i++;
	}
}
