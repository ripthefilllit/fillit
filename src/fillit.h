/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 09:44:17 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/12 13:38:36 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 1024
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
}					t_tetra;
int					check_file(char *str);
int					verif_body(char *s, int deb, int fin);
int					get_w(char *s, int deb);
int					get_h(char *s, int deb);
int					another_check(char *s, int deb, int fin);
int					detective_alone(char *s, int deb, int fin);
int					collect_char(char *s, int deb, int fin);
int					verif_line(char *s, int deb, int fin);
char				**str_to_tblstr(char *str);
int					nb_tetriminos(char *str);
void				mark_tetriminos(char **tetriminos);
int					detective_love(char *s, int deb, int fin);

int					error(void);
int					usage(void);

int					file_to_str(char *file_path, char **str);

t_tetra				str_to_tetra(char *str, char id);
t_tetra				tetra_movex(t_tetra tetra, int x);
t_tetra				tetra_movey(t_tetra tetra, int y);
t_tetra				tetra_move(t_tetra tetra, int x, int y);
void				tetras_normalize(t_tetra (*tetras)[26]);
void				tetras_store(char **str, t_tetra (*tetras)[26]);

int					sqrt_up(int nb);
int					initial_square(t_tetra tetra[26]);
int					resolve(t_tetra (*tetras)[26]);

char				id_at_position(t_tetra tetras[26], int x, int y);
void				display_result(t_tetra tetras[26], int side);

void				tetras_debug(t_tetra tetras[26]);
#endif
