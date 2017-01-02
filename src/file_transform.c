/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 09:41:18 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/02 11:28:28 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char 	*make_array(char *array, int pos)
{
	int 	j;
	char 	*john;
	int foll;

	foll = pos;
	j = 0;
	pos = pos + 20;
	if (!(john = (char *)malloc(21 * (sizeof(char)))))
			return (NULL);
	while (foll < pos)
	{
		john[j] = array[foll];
		foll++;
		j++;
	}
	john[j] = '\0';
	return (john);
}

char	**split_array(char *array)
{
	int		calc_char;
	char	**tab;
	int		i;
	int		j;
	int pos;

	pos = 0;
	j = 0;
	calc_char = ft_strlen(array) / 20;
	if (!(tab = (char **)malloc(calc_char * (sizeof(char *)))))
		return (NULL);
	while (calc_char)
	{
		tab[j] = make_array(array, pos);
		j++;
		calc_char--;
		if (array[pos + 21])
			pos = pos + 21;
		else
			return (tab);
	}
	return (tab);
}

char	*file_to_array(char *file)
{
	int		op;
	int		lec;
	char	buf[BUF_SIZE];
	char	*array;

	array = "";
	lec = 0;
	op = open(file, O_RDONLY);
	lec = read(op, buf, BUF_SIZE);
	if (op == -1)
	{
		close(op);
		return (NULL);
	}
	array = ft_strjoin(array,buf);
	close(op);
	return (array);
}
