/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 09:41:05 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/10 14:36:27 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**  Verifying if each line of the block ends with \n and has 4 characters.
*/

int	verif_line(char *s, int deb, int fin)
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

/*
**  Counting '#'' and '.' .
** A tetrimino is valid only if it contains 4#, 12. and 4\n.
*/

int	collect_char(char *s, int deb, int fin)
{
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

/*
**  Detecting if each '#' is as least next to 1 another '#'.
*/

int	detective_alone(char *s, int deb, int fin)
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

/*
**  Detecting if each '#' is as least next to 2 another '#'.
** 	Special case on the *** tetrimino ...
**  ... where only one tetrimino should touch 3 '#'
*/

int	detective_love(char *s, int deb, int fin)
{
	int hash;
	int zen;
	int cpt;

	zen = 0;
	hash = 0;
	cpt = 0;
	while (s[deb] != '\0' || deb <= fin)
	{
		if (s[deb] == '#')
		{
			s[deb + 5] == '#' ? zen++ : zen;
			s[deb - 5] == '#' ? zen++ : zen;
			s[deb + 1] == '#' ? zen++ : zen;
			s[deb - 1] == '#' ? zen++ : zen;
			if (zen >= 2)
				cpt++;
			hash++;
			if ((hash == 4 && cpt >= 2) || (zen == 3))
				return (1);
			zen = 0;
		}
		deb++;
	}
	return (0);
}
