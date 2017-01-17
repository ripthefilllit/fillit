/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 09:40:52 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/17 11:47:44 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**  Detecting if the second '#' is next to the third '#'.
*/

int	another_check(char *s, int start, int end)
{
	int h;
	int dist;

	dist = 0;
	h = 0;
	while (start <= end)
	{
		if (s[start] == '#')
			h++;
		if (h == 2 && s[start] == '#')
		{
			while (s[start + 1 + dist] != '#' && s[start + dist] != '\0')
				dist++;
			if (dist > 5)
				return (0);
		}
		start++;
	}
	return (1);
}

/*
**  Returning the height of a tetrimino.
*/

int	get_h(char *s, int start)
{
	int height;
	int follow;

	height = 0;
	follow = 19 + start;
	while (start <= follow)
	{
		if (s[start] == '#' || s[start + 1] == '#' || s[start + 2] == '#' ||
				s[start + 3] == '#')
			height++;
		start += 5;
	}
	return (height);
}

/*
**  Returning the width of a tetrimino.
*/

int	get_w(char *s, int start)
{
	int width;
	int follow;

	follow = 4 + start;
	width = 0;
	while (start <= follow)
	{
		if (s[start] == '#' || s[start + 5] == '#' || s[start + 10] == '#' ||\
				s[start + 15] == '#')
			width++;
		start++;
	}
	return (width);
}

/*
**  Checks if the shape of each tetrimino is valid (5 right cases).
*/

int	verif_body(char *s, int start, int end)
{
	int h;
	int w;

	h = get_h(s, start);
	w = get_w(s, start);
	if (detective_alone(s, start, end) == 0)
		return (0);
	if (another_check(s, start, end) == 0 || w == 0 || h == 0)
		return (0);
	if (h == 4 && w == 1)
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

/*
**  Main fuction of the file checker.
*/

int	check_file(char *str)
{
	int start;
	int end;

	start = 0;
	end = 19;
	while (str)
	{
		if (collect_char(str, start, end) == 0 ||\
			verif_line(str, start, end) == 0 ||\
			verif_body(str, start, end) == 0 ||\
			detective_love(str, start, end) == 0)
			return (0);
		if (str[end + 1] == '\n' && (str[end + 2] == '.' ||\
			str[end + 2] == '#'))
		{
			end += 21;
			start += 21;
		}
		else if (str[end + 1] == '\0')
			return (1);
		else
			return (0);
	}
	return (1);
}
