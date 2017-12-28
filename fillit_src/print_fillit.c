/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtudor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:31:34 by mtudor            #+#    #+#             */
/*   Updated: 2017/12/19 18:56:03 by mtudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_fillit(t_fout out)
{
	int	i;
	int	j;

	i = 0;
	while (i < out.size)
	{
		j = 0;
		while (j < out.size)
		{
			ft_putchar(out.matrix[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
