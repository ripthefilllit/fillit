/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_tetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:47:57 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/04 09:50:54 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Identify the tetriminos by assiging a unique upper letter to each one, on an
** alphabetical order.
*/

void	mark_tetriminos(char **tetriminos)
{
	int	i;
	int j;

	i = 0;
	while (tetriminos[i])
	{
		j = 0;
		while (tetriminos[i] && tetriminos[i][j])
		{
			if (tetriminos[i][j] == '#')
				tetriminos[i][j] = 'A' + i;
			++j;
		}
		i++;
	}
}
