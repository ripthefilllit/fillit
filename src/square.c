/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:54:15 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/16 20:12:05 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Verify that the tetraminos we want to place is inside the square
*/

int		is_inside_square(t_tetra tetras[26], int tetra, int xy[2], int *side)
{
	int i;

	if (tetra < 0)
		return (0);
	i = -1;
	while (++i < 4)
		if (!(tetras[tetra].x[i] + xy[0] < *side &&
				tetras[tetra].x[i] + xy[0] >= 0 &&
				tetras[tetra].y[i] + xy[1] < *side &&
				tetras[tetra].y[i] + xy[1] >= 0))
			return (0);
	return (1);
}

int		tetras_count(t_tetra (*tetras)[26])
{
	int i;

	i = 0;
	while ((*tetras)[i].id)
		++i;
	return (i);
}
