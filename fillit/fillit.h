/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:50:42 by bavram            #+#    #+#             */
/*   Updated: 2017/12/20 16:35:16 by mtudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# define TETRA_MAX 26
# define FILLIT_MAX 10
# define BUFF_SIZE 600

typedef struct	s_t{
	char		matrix[4][4];
	int			used;
}				t_tetramino;

typedef struct	s_o{
	char		matrix[FILLIT_MAX][FILLIT_MAX];
	int			size;
}				t_fout;

void			show_usage(void);
int				read_tetra(char *file, t_tetramino *tetra, int *tetra_size);
int				valid_tetra(t_tetramino *tetra, int tetra_size);
void			solve_tetra(t_tetramino *tetra, int tetra_size, t_fout *out);
void			print_fillit(t_fout out);
void			init_output(t_fout *out);

#endif
