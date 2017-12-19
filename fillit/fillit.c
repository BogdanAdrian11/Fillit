/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:02:44 by bavram            #+#    #+#             */
/*   Updated: 2017/12/19 19:24:47 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **args)
{
	t_tetramino	tetra[TETRA_MAX];
	t_fout		out;
	int			tetra_size;

	out.size = 0;
	if (argc != 2)
	{
		show_usage();
		return (1);
	}
	if (!read_tetra(args[1], tetra, &tetra_size))
	{
		ft_putstr("read error\n");
		return (1);
	}
	if (!valid_tetra(tetra, tetra_size))
	{
		ft_putstr("tetramino error\n");
		return (1);
	}
	init_output(&out);
	solve_tetra(tetra, tetra_size, &out);
	print_fillit(out);
	return (0);
}
