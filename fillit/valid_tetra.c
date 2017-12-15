/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtudor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:45:53 by mtudor            #+#    #+#             */
/*   Updated: 2017/12/15 19:46:34 by mtudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	filled_blocks(t_tetramino tetra)
{
	int		i;
	int		j;
	int		filled;

	filled = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetra.matrix[i][j] == '#')
				filled++;
			j++;
		}
		i++;
	}
	return (filled);
}

static int	is_connected(t_tetramino tetra, int i, int j)
{
	if (i != 0 && tetra.matrix[i - 1][j] == '#')
		return (1);
	if (i != 3 && tetra.matrix[i + 1][j] == '#')
		return (1);
	if (j != 0 && tetra.matrix[i][j - 1] == '#')
		return (1);
	if (j != 3 && tetra.matrix[i][j + 1] == '#')
		return (1);
	return (0);
}

static int	connected_blocks(t_tetramino tetra)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetra.matrix[i][j] == '#' && !is_connected(tetra, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			valid_tetra(t_tetramino *tetra, int tetra_size)
{
	int		i;

	i = 0;
	while (i < tetra_size)
	{
		if (filled_blocks(tetra[i]) != 4)
			return (0);
		if (!connected_blocks(tetra[i]))
			return (0);
		i++;
	}
	return (1);
}
