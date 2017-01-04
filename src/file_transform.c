/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 09:41:18 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/04 12:38:54 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Store the tetriminos in an array of string.
*/

int		nb_tetriminos(char *str)
{
	int i;
	int	len;
	int	nb_tetri;

	i = 18;
	len = ft_strlen(str);
	nb_tetri = 0;
	while (i < len && str[i])
	{
		if (str[i] == '.' || str[i] == '#')
			++nb_tetri;
		i += 21;
	}
	return (nb_tetri);
}

char	**str_to_tblstr(char *str)
{
	int		i;
	int		j;
	int		tetriminos;
	char	**tab;

	j = 0;
	i = 0;
	tetriminos = nb_tetriminos(str);
	tab = (char **)malloc((sizeof(*tab)) * tetriminos + 1);
	if (!tab)
		return (NULL);
	while (i < tetriminos)
	{
		tab[i] = ft_strsub(str, j, 20);
		if (str[j + 21])
			j += 21;
		else
			return (tab);
		++i;
	}
	tab[i] = "\0";
	return (tab);
}

/*
** This function doesn't free anything!!!
*/

char	*file_to_str(char *file_path)
{
	int		fd;
	int		byte_read;
	char	buf[BUF_SIZE + 1];
	char	*result;

	byte_read = 0;
	result = "";
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (result);
	else
	{
		while ((byte_read = read(fd, buf, BUF_SIZE)) > 0)
		{
			buf[byte_read] = '\0';
			result = ft_strjoin(result, buf);
		}
		close(fd);
	}
	return (result);
}
