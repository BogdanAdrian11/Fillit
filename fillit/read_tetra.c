/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:46:59 by bavram            #+#    #+#             */
/*   Updated: 2017/12/15 18:42:19 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	increment_pos(int *row, *col, *tetra_size)
{
	if (*col == 3)
	{
		if (*row == 3)
		{
			*tetra_size = *tetra_size + 1;
			*row = 0;
		}
		else
			*row = *row + 1;
		*col = 0;
	}
	else
		*col = *col + 1;
}

static int	check_new_line(char buff[BUFF_SIZE + 1], int *i, int col, int row)
{
	if (buff[*i] != '\n')
		return (0);
	if (col != 3)
		return (0);
	if (row == 3)
	{
		if (buff[*i + 1] != '\n' && buff[*i + 1] != '\0')
			return (0);
		if (buff[*i + 1] == '\n')
			*i = *i + 1;
	}
	return (1);
}

static int	check_input(char buff[BUFF_SIZE + 1], t_tetramino tetra[TETRA_MAX],
		int *tetra_size)
{
	int		i;
	int		row;
	int		col;

	i = 0;
	*tetra_size = 0;
	row = 0;
	col = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '.' || buff[i] == '#')
		   tetra[*tetra_size]->matrix[row][col] = buff[i];
		else
		{
			if (!check_new_line(buff, i, col, row)) 
				return (0);
		}
		i++;
		increment_pos(&row, &col, &tetra_size);
	}
	return (1);
}

int			read_tetra(char *file, t_tetramino tetra[TETRA_MAX], int *tetra_size)
{
	int		fd;
	int		ret;
	char	*buff[BUFF_SIZE + 1];

	fd = open(file, buff, BUFF_SIZE);
	if (fd == -1)
		return (1);
	else
	{
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		close(fd);
	}
	if (!check_input(buff, tetra, &tetra_size))
	{
		return (1);
	}
	return (0);
}
