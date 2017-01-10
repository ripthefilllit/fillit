/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 09:41:05 by bzmuda            #+#    #+#             */
/*   Updated: 2016/12/30 17:43:45 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	verif_line(char *s, int deb, int fin)
{
	int y;

	y = 0;
	while (s[deb] != '\0' && deb <= fin)
	{
		if (s[deb] == '.' || s[deb] == '#')
			y++;
		if (y > 4)
			return (0);
		if (s[deb] == '\n' && y == 4)
			y = 0;
		deb++;
	}
	return (1);
}

int		collect_char(char *s, int deb, int fin) // Fait l'inventaire des . # et \n
{// Un tetrimino est bon si 4 # 12 . et 4 \n
	int hashtag;
	int point;
	int baqueslache;

	hashtag = 0;
	point = 0;
	baqueslache = 0;
	while (s[deb] != '\0' && deb <= fin)
	{
		if (s[deb] == '#')
			hashtag++;
		if (s[deb] == '.')
			point++;
		if (s[deb] == '\n')
			baqueslache++;
		if (s[deb] != '#' && s[deb] != '.' && s[deb] != '\n')
			return (0);
		deb++;
	}
	if (hashtag != 4 || point != 12 || baqueslache != 4)
		return (0);
	return (1);
}

int		detective_alone(char *s, int deb, int fin) // Détecte si tout les # sont liés
{
	int valid_hashtag;

	valid_hashtag = 0;
	while (s[deb] != '\0' && deb <= fin)
	{
		if (s[deb] == '#')
		{
			if (s[deb + 5] == '#' || s[deb - 5] == '#' ||\
					(s[deb + 1] == '#') || s[deb - 1] == '#')
				valid_hashtag++;
			if (valid_hashtag == 4)
				return (1);
		}
		deb++;
	}
	return (0);
}

int 	detective_love(char *s, int deb, int fin)
{
	int hash;
	int zen;
	int cpt;
	
	zen = 0;
	hash = 0;
	cpt = 0;
	while (s[deb] != '\0' && deb <= fin)
	{
		if (s[deb] == '#')
			hash++;
		while (hash > 0 || hash < 5)
		{
			if (s[deb + 5] == '#')
				zen++;
			if (s[deb - 5] == '#')
				zen++;
			if (s[deb + 1] == '#')
				zen++;
			if (s[deb - 1] == '#')
				zen++;
			if (zen >= 2)
				cpt++;
			while (s[deb] != '#')
				deb++;
			hash++;
			zen = 0;
			if (hash == 4 && cpt >= 2)
				return (1);
		}
		if (hash == 4 && cpt < 2)
			return (0);
		deb++;
	}
	return (0);
}