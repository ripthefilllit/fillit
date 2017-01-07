/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:03:52 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/07 15:02:04 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


/* int		is_outside(t_tetra tetra, int size); */

/*
** Compute the square root, rounded up, of a given number.
*/

int		sqrt_up(int nb)
{
	int i;

	i = 1;
	if (nb == 1)
		return (1);
	else if (nb <= 0)
		return (0);
	while (i * i <= nb && i < nb)
		i++;
	return (i);
}

/*
** Compute the side of the tiniest square able to contain all the parts of the
** tetraminos in the given array.
*/

int		initial_square(t_tetra tetra[26])
{
	int i;

	i = 0;
	while (tetra[i].id)
		++i;
	return (sqrt_up(i * 4));
}
