/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 09:44:17 by bzmuda            #+#    #+#             */
/*   Updated: 2016/12/30 10:24:54 by bzmuda           ###   ########.fr       */
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

int		check_file(char **tab);
int		verif_body(char *s);
int		get_w(char *s);
int		get_h(char *s);
int		another_check(char *s);
int		cpt_tetrimino(char **tab);
int		detective_alone(char *s);
int		collect_char(char *s);
int		verif_line(char *s);
char	*file_to_array(char *file);
char	**split_array(char *array);
#endif
