/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:50:42 by bavram            #+#    #+#             */
/*   Updated: 2017/12/15 19:00:43 by mtudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# define TETRA_MAX 26
# define FILLIT_MAX 100
# define BUFF_SIZE 600

typedef struct	s_t{
	char		matrix[4][4];
	int			used;
}				t_tetramino;

void			show_usage(void);
int				read_tetra(char *file, t_tetramino *tetra, int *tetra_size);
int				valid_tetra(t_tetramino *tetra, int tetra_size);
int				solve_tetra(t_tetramino *tetra, int tetra_size, \
		char **filiit_output);
void			print_fillit(char **fillit_output, int output_size);

#endif
