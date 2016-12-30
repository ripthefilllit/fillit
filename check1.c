/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 09:40:52 by bzmuda            #+#    #+#             */
/*   Updated: 2016/12/30 17:43:08 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	another_check(char *s)
{
	int i;
	int h;
	int eloi;

	eloi = 0;
	i = 0;
	h = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			h++;
		if (h == 2 && s[i] == '#')
		{
			while (s[i + 1 + eloi] != '#' && s[i + eloi] != '\0')
				eloi++;
			if (eloi > 5)// Si le deuxieme # est délié du 3eme
				return (0);
		}
		i++;
	}
	return (1);
}

int		get_h(char *s) // Get_h et w pas protégés, dépendants de detective_alone
{
	int i;
	int height;

	i = 0;
	height = 0;
	while (i < 19)
	{
		if (s[i] == '#' || s[i + 1] == '#' || s[i + 2] == '#' ||\
				s[i + 3] == '#')
			height++;
		i += 5;
	}
	return (height);
}

int 	get_w(char *s)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (i < 4)
	{
		if (s[i] == '#' || s[i + 5] == '#' || s[i + 10] == '#' ||\
				s[i + 15] == '#')
			width++;
		i++;
	}
	return (width);
}

int 	verif_body(char *s)
{
	int i;
	int h;
	int w;

	i = 0;
	h = get_h(s);
	w = get_w(s);
	if (detective_alone(s) == 0)
		return (0);
	if (another_check(s) == 0 || w == 0 || h == 0)
		return (0);
	if (h == 4 && w == 1)// Formes autorisées
		return (1);
	else if (h == 1 && w == 4)
		return (1);
	else if (h == 2 && w == 3)
		return (1);
	else if (h == 3 && w == 2)
		return (1);
	else if (h == 2 && w == 2)
		return (1);
	else
		return (0);
}

int		check_file(char **tab)
{
	int i;
	int nb_tetrimino;

	i = 0;
	nb_tetrimino = cpt_tetrimino(tab);
	if (tab[0] == NULL)
		return (0);
	while (i < nb_tetrimino)
	{
		if (collect_char(tab[i]) == 0 || verif_line(tab[i]) == 0 ||\
			verif_body(tab[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
