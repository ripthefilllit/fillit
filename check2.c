/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 09:41:05 by bzmuda            #+#    #+#             */
/*   Updated: 2016/12/30 10:29:31 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	verif_line(char *s)
{
	int x;
	int y;
	int followfive;

	x = 0;
	y = 0;
	followfive = 4;
	while (s[x] != '\0')
	{
		if (s[x] == '.' || s[x] == '#')
			y++;
		if (y > 4)
			return (0);
		if (s[x] == '\n' && x == followfive)
		{
			y = 0;
			followfive += 5;
		}
		x++;
	}
	return (1);
}

int		collect_char(char *s) // Fait l'inventaire des . # et \n
{							// Un tetrimino est bon si 4 # 12 . et 4 \n
	int i;
	int hashtag;
	int point;
	int baqueslache;

	i = 0;
	hashtag = 0;
	point = 0;
	baqueslache = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			hashtag++;
		if (s[i] == '.')
			point++;
		if (s[i] == '\n')
			baqueslache++;
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		i++;
	}
	if (hashtag != 4 || point != 12 || baqueslache != 4)
		return (0);
	return (1);
}

int		detective_alone(char *s) // Détecte si tout les # sont liés
{
	int i;
	int valid_hashtag;
	int ok;

	i = 0;
	ok = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (s[i + 5] == '#' || s[i - 5] == '#' ||\
					(s[i + 1] == '#') || s[i - 1] == '#')
				valid_hashtag++;
			if (valid_hashtag == 4)
				return (1);
		}
		i++;
	}
	return (0);
}

int 	cpt_tetrimino(char **tab)
{
	int i;
	int tablen;

	i = 0;
	tablen = 0;
	while (tab[i] != NULL)
	{
		tablen++;
		i++;
	}
	return (tablen);
}
