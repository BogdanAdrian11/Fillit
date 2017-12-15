/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:02:44 by bavram            #+#    #+#             */
/*   Updated: 2017/12/15 17:24:00 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **args)
{
	t_tetramino	tetra[26];
	char		fillit_output[100][100];
	int			output_size;
	
	if (argc != 2)
	{
		show_usage();
		return (1);
	}
	if (read_tetra(args[1], tetra))
	{
		ft_putstr("error\n");
		return (1);
	}
	if (!valid_tetra(tetra))
	{
		ft_putstr("error\n");
		return (1);
	}
	output_size = solve_tetra(tetra, fillit_output);
	print_fillit(fillit_output, output_size);
	return (0);
}
