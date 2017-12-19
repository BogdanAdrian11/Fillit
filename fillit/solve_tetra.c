/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtudor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:24:56 by mtudor            #+#    #+#             */
/*   Updated: 2017/12/19 19:02:41 by mtudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	start_size(int tetra_size)
{
	int		i;

	i = 0;
	while ((i + 1) * (i + 1) <= tetra_size)
		i++;
	return (i);
}

static void	char_change(t_fout *out, char c1, char c2)
{
	int		i;
	int		j;

	i = 0;
	while (i < out.size)
	{
		j = 0;
		while (j < out.size)
		{
			if (out.matrix[i][j] == c1)
				out.matrix[i][j] = c2;
			j++;
		}
		i++;
	}
}

static int	place_tetra(t_tetramino tetra, t_fout *out, int i, int j)
{
	return (1);
}

static int	solve(t_tetramino *tetra, t_fout *out, int k, int tetra_size)
{
	int		i;
	int		j;

	if (k == tetra_size)
		return (1);
	i = 0;
	j = 0;
	while (i < out.size)
	{
		while (j < out.size)
		{
			if (place_tetra(tetra[k], out, i, j))
			{
				char_change(out, '#', 'A' + k);
				return (solve(tetra, out, k + 1, tetra_size));
			}
			j++;
		}
		i++;
	}
	char_change(out, 'A' + k, '.');
	return (0);
}

void		solve_tetra(t_tetramino *tetra, int tetra_size, t_fout *out)	//crestem iterativ sizeurile
{
	out.size = start_size(tetra_size);
	while (!solve(tetra, &out, 0, tetra_size))
		out.size++;
}
