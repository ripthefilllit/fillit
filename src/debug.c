/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:39:25 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/06 18:04:52 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void	debug_array(char **tblstr)
{
	int i;

	i = 0;
	while (tblstr[i])
	{
		ft_putstr(tblstr[i]);
		ft_putchar('\n');
		i++;
	}
}

void	debug_tetra(t_tetra tetras[26])
{
	int	i;

	i = 0;
	while (ft_isupper(tetras[i].id))
	{
		printf("tetra %d:\n", i);
		printf("\tx0: %d,\ty0: %d\n", tetras[i].x[0], tetras[i].y[0]);
		printf("\tx1: %d,\ty1: %d\n", tetras[i].x[1], tetras[i].y[1]);
		printf("\tx2: %d,\ty2: %d\n", tetras[i].x[2], tetras[i].y[2]);
		printf("\tx3: %d,\ty3: %d\n", tetras[i].x[3], tetras[i].y[3]);
		printf("\tid: %c\n", tetras[i].id);
		++i;
	}
}
