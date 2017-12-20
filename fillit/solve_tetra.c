/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtudor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:24:56 by mtudor            #+#    #+#             */
/*   Updated: 2017/12/20 18:27:27 by mtudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	start_size(int tetra_size)
{
	int		i;

	i = 0;
	while ((i + 1) * (i + 1) <= tetra_size * 4)
		i++;
	return (i);
}

static void	char_change(t_fout *out, char c1, char c2)
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

static int	place_tetra(t_tetramino tetra, t_fout *out, int i, int j)	//returns 1 if the place is possible, then places it
{
	int		p;
	int		q;
	int		count;

	count = 0;
	p = 0;
	q = 0;
	while (tetra.matrix[p][q] != '#' && p != 4)
		if(q == 3)
		{
			p++;
			q = 0;
		}
		else
			q++;
	while (p != 4)		//i si j sunt gresite rau
	{
		if (((*out).matrix[i][j] != '.' || i >= (*out).size || j >= (*out).size)
				&& tetra.matrix[p][q] == '#')
			return (0);
		if (tetra.matrix[p][q] == '#')
		{
			(*out).matrix[i][j] = tetra.matrix[p][q];
			//ft_putnbr(i);
			//ft_putnbr(j);
			//ft_putchar(' ');
			count++;
		}
		if (q == 3)
		{
			i++;
			p++;
			q = 0;
			j = j - 3;
		}
		else
		{
			q++;
			j++;
		}
	}
	if (count == 4)
	{
		//ft_putchar('A');
		return (1);
	}
	return (0);
}

static int	solve(t_tetramino *tetra, t_fout *out, int k, int tetra_size)
{
	int		i;
	int		j;
	
	ft_putnbr(k);
	if (k == tetra_size)
		return (1);
	i = 0;
	j = 0;
	while (i < (*out).size)
	{
		while (j < (*out).size)
		{
			if (place_tetra(tetra[k], out, i, j))
			{
				char_change(out, '#', 'A' + k);
				ft_putchar('\n');
				//print_fillit(*out);
				return (solve(tetra, out, k + 1, tetra_size));
			}
			char_change(out, '#', 'A' + k);
			j++;
		}
		i++;
		//ft_putnbr(i);
	}
	char_change(out, 'A' + k, '.');
	return (0);
}

void		solve_tetra(t_tetramino *tetra, int tetra_size, t_fout *out)	//crestem iterativ sizeurile
{
	(*out).size = start_size(tetra_size);
	while (!solve(tetra, out, 0, tetra_size))
	{
		(*out).size++;
		init_output(out);
		//print_fillit(*out);
	}
	//(*out).size = 4;
	//place_tetra(tetra[0], out, 2, 0);
}

//poti sa te folosesti de out ca si copie si nu trebuie sa deletezi ce ai pus
//k trebuie sa fie in toate permutarile posibile, nu numai cresacator
