/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:02:44 by bavram            #+#    #+#             */
/*   Updated: 2017/12/15 17:41:16 by mtudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **args)
{
	t_tetramino	tetra[TETRA_MAX];
	char		fillit_output[FILLIT_MAX][FILLIT_MAX];
	int			output_size;
	int			tetra_size;

	if (argc != 2)
	{
		show_usage();
		return (1);
	}
	if (read_tetra(args[1], tetra, &tetra_size))
	{
		ft_putstr("error\n");
		return (1);
	}
	if (!valid_tetra(tetra, tetra_size))
	{
		ft_putstr("error\n");
		return (1);
	}
	output_size = solve_tetra(tetra, fillit_output, tetra_size);
	print_fillit(fillit_output, output_size);
	return (0);
}
