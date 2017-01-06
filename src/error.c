/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:10:10 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/06 13:00:59 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		error(void)
{
	ft_putstr_fd("error\n", 2);
	return (0);
}

int		usage(void)
{
	ft_putstr_fd("usage: fillit file\n", 2);
	return (0);
}
