/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 09:44:17 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/17 11:55:01 by bwaegene         ###   ########.fr       */
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
int					verif_body(char *s, int end, int start);
int					get_w(char *s, int start);
int					get_h(char *s, int start);
int					another_check(char *s, int start, int end);
int					detective_alone(char *s, int deb, int fin);
int					collect_char(char *s, int deb, int fin);
int					verif_line(char *s, int deb, int fin);
char				**str_to_tblstr(char *str);
int					nb_tetriminos(char *str);
void				mark_tetriminos(char **tetriminos);
int					detective_love(char *s, int start, int end);

int					error(void);
int					usage(void);

int					file_to_str(char *file_path, char **str);

t_tetra				str_to_tetra(char *str, char id);
t_tetra				tetra_movex(t_tetra tetra, int x);
t_tetra				tetra_movey(t_tetra tetra, int y);
t_tetra				tetra_move(t_tetra tetra, int x, int y);
void				tetras_normalize(t_tetra (*tetras)[26]);
void				tetra_normalize(t_tetra (*tetras)[26], int tetra);
void				tetras_store(char **str, t_tetra (*tetras)[26]);

int					initial_square(t_tetra (*tetra)[26]);
int					resolve(t_tetra (*tetras)[26]);

char				id_at_position(t_tetra tetras[26], int x, int y);
void				display_result(t_tetra tetras[26], int side);

int					tetras_count(t_tetra (*tetras)[26]);
int					is_inside_square(t_tetra tetras[26], int tetra,
										int xy[2], int *side);
#endif
