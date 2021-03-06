/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:46:59 by bavram            #+#    #+#             */
/*   Updated: 2017/12/29 14:37:40 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	increment_pos(int *row, int *col, int *tetra_size,
		t_tetramino *tetra)
{
	if (*col == 4)
	{
		if (*row == 3)
		{
			tetra[*tetra_size].used = 0;
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
	if (col != 4)
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

static int	valid_input(char *buff, int i, int col, int row)
{
	if (i < 20)
		return (0);
	if (buff[i - 2] != '.' && buff[i - 2] != '#')
		return (0);
	if (col == 0 && row == 0)
		return (1);
	return (0);
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
			tetra[*tetra_size].matrix[row][col] = buff[i];
		else
		{
			if (!check_new_line(buff, &i, col, row))
				return (0);
		}
		i++;
		increment_pos(&row, &col, tetra_size, tetra);
	}
	return (valid_input(buff, i, col, row));
}

int			read_tetra(char *file, t_tetramino tetra[TETRA_MAX],
		int *tetra_size)
{
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	else
	{
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		close(fd);
	}
	if (check_input(buff, tetra, tetra_size))
	{
		i = -1;
		while (++i < *tetra_size)
		{
			tetra[i].index = i;
			tetra_pos(tetra[i], &tetra[i].p, &tetra[i].q);
		}
		return (1);
	}
	return (0);
}
