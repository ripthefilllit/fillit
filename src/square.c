/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:24:16 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/04 16:49:30 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*empty_square(unsigned int side)
{
	unsigned int	i;
	int				len;
	char			*square;

	len = (side * side) + side;
	square = (char*)malloc(sizeof(*square) * len + 1);
	if (!square)
		return (NULL);
	square[len] = '\0';
	i = -1;
	while (--len >= 0)
	{
		if (++i  == 0)
			square[len] = '\n';
		else if (i == side)
		{
			square[len] = '.';
			i = -1;
		}
		else
			square[len] = '.';
	}
	return (square);
}
