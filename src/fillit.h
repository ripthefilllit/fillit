/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 09:44:17 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/06 10:55:18 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 546 // nb max de caracteres + \n pour 26 tetriminos
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

typedef struct		s_tetra
{
	int				x[4];
	int				y[4];
	char			id;
	struct t_tetra	*next;
}					t_tetra;
int			check_file(char **tab);
int			verif_body(char *s);
int			get_w(char *s);
int			get_h(char *s);
int			another_check(char *s);
int			cpt_tetrimino(char **tab);
int			detective_alone(char *s);
int			collect_char(char *s);
int			verif_line(char *s);
char		*file_to_str(char *file_path);
char		**str_to_tblstr(char *str);
int			nb_tetriminos(char *str);
void		mark_tetriminos(char **tetriminos);
char		*empty_square(unsigned int side);
int			str_error(char *str);
t_tetra		str_to_tetra(char *str, char id);
void		move_tetra(t_tetra *tetra, int x, int y);
void		normalize_tetra(t_tetra *tetra);
void		tblstr_to_tetras(char **tblstr, t_tetra *(tetras[26]));
#endif
