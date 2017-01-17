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

int	verif_line(char *s, int start, int end)
{
	int y;

	y = 0;
	while (s[start] != '\0' && start <= end)
	{
		if (s[start] == '.' || s[start] == '#')
			y++;
		if (y > 4)
			return (0);
		if (s[start] == '\n' && y == 4)
			y = 0;
		start++;
	}
	return (1);
}

/*
**  Counting '#'' and '.' .
** A tetrimino is valid only if it contains 4#, 12. and 4\n.
*/

int	collect_char(char *s, int start, int end)
{
	int hashtag;
	int point;
	int jump;

	hashtag = 0;
	point = 0;
	jump = 0;
	while (s[start] != '\0' && start <= end)
	{
		if (s[start] == '#')
			hashtag++;
		if (s[start] == '.')
			point++;
		if (s[start] == '\n')
			jump++;
		if (s[start] != '#' && s[start] != '.' && s[start] != '\n')
			return (0);
		start++;
	}
	if (hashtag != 4 || point != 12 || jump != 4)
		return (0);
	return (1);
}

/*
**  Detecting if each '#' is as least next to 1 another '#'.
*/

int	detective_alone(char *s, int start, int end)
{
	int valid_hashtag;

	valid_hashtag = 0;
	while (s[start] != '\0' && start <= end)
	{
		if (s[start] == '#')
		{
			if (s[start + 5] == '#' || s[start - 5] == '#' ||\
					(s[start + 1] == '#') || s[start - 1] == '#')
				valid_hashtag++;
			if (valid_hashtag == 4)
				return (1);
		}
		start++;
	}
	return (0);
}

/*
**  Detecting if each '#' is as least next to 2 another '#'.
** 	Special case on the *** tetrimino ...
**  ... where only one tetrimino should touch 3 '#'
*/

int	detective_love(char *s, int start, int end)
{
	int hash;
	int english;
	int cpt;

	english = 0;
	hash = 0;
	cpt = 0;
	while (s[start] != '\0' || start <= end)
	{
		if (s[start] == '#')
		{
			s[start + 5] == '#' ? english++ : english;
			s[start - 5] == '#' ? english++ : english;
			s[start + 1] == '#' ? english++ : english;
			s[start - 1] == '#' ? english++ : english;
			if (english >= 2)
				cpt++;
			hash++;
			if ((hash == 4 && cpt >= 2) || (english == 3))
				return (1);
			english = 0;
		}
		start++;
	}
	return (0);
}
