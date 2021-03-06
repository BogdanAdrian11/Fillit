/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtudor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:24:56 by mtudor            #+#    #+#             */
/*   Updated: 2017/12/29 14:40:10 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		tetra_pos(t_tetramino tetra, int *p, int *q)
{
	*p = 0;
	*q = 0;
	while (tetra.matrix[*p][*q] != '#' && *p != 4)
		if (*q == 3)
		{
			*p = *p + 1;
			*q = 0;
		}
		else
			*q = *q + 1;
}

static void	increm_pos(int *i, int *j, int *p, int *q)
{
	if (*q == 3)
	{
		*i = *i + 1;
		*p = *p + 1;
		*q = 0;
		*j = *j - 3;
	}
	else
	{
		*q = *q + 1;
		*j = *j + 1;
	}
}

static int	place_tetra(t_tetramino tetra, t_fout *out, int i, int j)
{
	int		count;

	count = 0;
	while (tetra.p != 4)
	{
		if (((*out).matrix[i][j] != '.' || i >= (*out).size || j >= (*out).size
				|| i < 0 || j < 0) && tetra.matrix[tetra.p][tetra.q] == '#')
			return (0);
		if (tetra.matrix[tetra.p][tetra.q] == '#')
		{
			(*out).matrix[i][j] = 'A' + tetra.index;
			count++;
		}
		increm_pos(&i, &j, &(tetra.p), &(tetra.q));
	}
	if (count == 4)
	{
		return (1);
	}
	return (0);
}

static int	solve(t_tetramino *tetra, t_fout out, int tetra_size)
{
	int		i;
	int		j;
	int		k;

	if (is_solved(tetra, tetra_size, out))
		return (1);
	k = -1;
	while (++k < tetra_size)
	{
		j = -1;
		while (tetra[k].used == 0 && next_pos(&i, &j, out))
		{
			if (place_tetra(tetra[k], &out, i, j))
			{
				tetra[k].used = 1;
				if (solve(tetra, out, tetra_size))
					return (1);
				tetra[k].used = 0;
			}
			char_change(&out, 'A' + k, '.');
		}
	}
	return (0);
}

void		solve_tetra(t_tetramino *tetra, int tetra_size, t_fout out)
{
	out.size = start_size(tetra_size);
	while (!solve(tetra, out, tetra_size))
		out.size++;
}
