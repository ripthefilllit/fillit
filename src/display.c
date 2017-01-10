/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 10:48:29 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/10 18:09:54 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Return the first id of a tetraminos found at this position.
*/

char		id_at_position(t_tetra tetras[26], int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tetras[i].id)
	{
		j = 0;
		while (j < 4)
		{
			if (tetras[i].x[j] == x &&
				tetras[i].y[j] == y)
			{
				return (tetras[i].id);
			}
			++j;
		}
		++i;
	}
	return (0);
}

void		display_result(t_tetra tetras[26], int side)
{
	int		i;
	int		line;
	char	*result;

	result = ft_strnew((side * side) + side);
	if (result)
	{
		i = -1;
		line = 1;
		while (++i < (side * side) + side)
		{
			if (i == (side * line) + line - 1)
			{
				result[i] = '\n';
				++line;
			}
			else if (id_at_position(tetras, i % (side + 1), line - 1))
				result[i] = id_at_position(tetras, i % (side + 1), line - 1);
			else
				result[i] = '.';
		}
		ft_putstr(result);
		free(result);
	}
}
