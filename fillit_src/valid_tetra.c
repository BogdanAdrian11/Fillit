/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtudor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:45:53 by mtudor            #+#    #+#             */
/*   Updated: 2017/12/29 13:39:38 by bavram           ###   ########.fr       */
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
	int		con;

	con = 0;
	if (i != 0 && tetra.matrix[i - 1][j] == '#')
		con++;
	if (i != 3 && tetra.matrix[i + 1][j] == '#')
		con++;
	if (j != 0 && tetra.matrix[i][j - 1] == '#')
		con++;
	if (j != 3 && tetra.matrix[i][j + 1] == '#')
		con++;
	return (con);
}

static int	connected_blocks(t_tetramino tetra)
{
	int		i;
	int		j;
	int		con;
	int		counter;

	i = 0;
	counter = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			con = is_connected(tetra, i, j);
			if (tetra.matrix[i][j] == '#' && con == 0)
				return (0);
			if (tetra.matrix[i][j] == '#')
				counter = counter + con;
			j++;
		}
		i++;
	}
	if (counter < 6)
		return (0);
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
