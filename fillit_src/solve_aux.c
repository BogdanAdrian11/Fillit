/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:56:43 by bavram            #+#    #+#             */
/*   Updated: 2017/12/28 16:17:22 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		start_size(int tetra_size)
{
	int		i;

	i = 0;
	while ((i + 1) * (i + 1) <= tetra_size * 4)
		i++;
	return (i);
}

void	char_change(t_fout *out, char c1, char c2)
{
	int		i;
	int		j;

	i = 0;
	while (i < (*out).size)
	{
		j = 0;
		while (j < (*out).size)
		{
			if ((*out).matrix[i][j] == c1)
				(*out).matrix[i][j] = c2;
			j++;
		}
		i++;
	}
}

int		is_solved(t_tetramino *tetra, int tetra_size, t_fout out)
{
	int		i;

	i = 0;
	while (i < tetra_size)
	{
		if (tetra[i].used == 0)
			return (0);
		i++;
	}
	print_fillit(out);
	return (1);
}

int		next_pos(int *i, int *j, t_fout out)
{
	if (*j == -1)
		*i = 0;
	if (*j < out.size - 1)
		*j = *j + 1;
	else
	{
		*j = 0;
		if (*i < out.size - 1)
			*i = *i + 1;
		else
			return (0);
	}
	return (1);
}
