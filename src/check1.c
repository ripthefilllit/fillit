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

int 	another_check(char *s, int deb, int fin)
{
	int h;
	int eloi;

	eloi = 0;
	h = 0;
	while (deb <= fin)
	{
		if (s[deb] == '#')
			h++;
		if (h == 2 && s[deb] == '#')
		{
			while (s[deb + 1 + eloi] != '#' && s[deb + eloi] != '\0')
				eloi++;
			if (eloi > 5)// Si le deuxieme # est délié du 3eme
				return (0);
		}
		deb++;
	}
	return (1);
}

int		get_h(char *s, int deb) // Get_h et w pas protégés, dépendants de detective_alone
{
	int height;
	int follow;

	height = 0;
	follow = 19 + deb;
	while (deb <= follow)
	{
		if (s[deb] == '#' || s[deb + 1] == '#' || s[deb + 2] == '#' ||\
				s[deb + 3] == '#')
			height++;
		deb += 5;
	}
	return (height);
}

int 	get_w(char *s, int deb)
{
	int width;
	int follow;

	follow = 4 + deb;
	width = 0;
	while (deb <= follow)
	{
		if (s[deb] == '#' || s[deb + 5] == '#' || s[deb + 10] == '#' ||\
				s[deb + 15] == '#')
			width++;
		deb++;
	}
	return (width);
}

int 	verif_body(char *s, int deb, int fin)
{
	int h;
	int w;

	h = get_h(s, deb);
	w = get_w(s, deb);
	if (detective_alone(s, deb, fin) == 0)
		return (0);
	if (another_check(s, deb, fin) == 0 || w == 0 || h == 0)
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

int		check_file(char *str)
{
	int deb;
	int fin;

	deb = 0;
	fin = 19;
	if (str == NULL)
		return (0);
	while (str)
	{
		if (collect_char(str, deb, fin) == 0 || verif_line(str, deb, fin) == 0 ||\
			verif_body(str, deb, fin) == 0 || detective_love(str, deb, fin) == 0)
			return (0);
		if (str[fin + 1] == '\n' && (str[fin + 2] == '.' || str[fin + 2] == '#'))
		{
			fin +=21;
			deb +=21;
		}
		else if (str[fin + 1] == '\0')
			return (1);
		else
			return (0);
	}
	return (1);
}
