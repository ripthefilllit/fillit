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

/*char	**split_array(char *array) // A refaire
{
	int i;
	char **tab;
	int calc_char;
	int j;
	int k;

	j = 0;
	k = 0;
	calc_char = ft_strlen(array)/20;
	printf("%d", calc_char);
	i = 0;
	if (!(tab = (char **)malloc(sizeof(char*) * calc_char)))
		return (NULL);
	while (array[i])
	{
		if (!(tab[j] = (char *)malloc(sizeof(char) * 20)))
			return (NULL);

		tab[j][k] = array[i];
		if (i == 20 || i == 40 || i == 60) // Nul a chier
		{
			ft_putstr(tab[j]);
			j++;
			i+=2;
		}
		k++;
		i++;
	}
	while (tab[j] != NULL)
	{
		ft_putchar(j);
		ft_putstr(tab[j]);
		j++;
	}
	return (tab);
	}
*/
char	**split_array(char *array)
{
	int		calc_char;
	char	**tab;
	int		i;
	int		j;
	/* int aff = 0; */
	int k;
	int cpt;

	// collect 20
	// +22
	cpt = 1;
	i = 0;
	j = 0;
	k = 0;
	calc_char = ft_strlen(array) / 20;
	ft_putstr("\n le nb de tetrimino : \n");
	ft_putnbr(calc_char);
	ft_putchar('\n');
	if (!(tab = (char **)malloc(calc_char * (sizeof(char *)))))
		return (NULL);
	while (array[i] != '\0')
	{
		if (!(tab[j] = (char *)malloc(21 * (sizeof(char)))))
			return (NULL);
		while (array[i] != '\0' && i < 20 * cpt)
		{
			tab[j][k] = array[i];
			k++;
			i++;
		}
		tab[j][k] = '\0';
		j++;
		cpt++;
		i+=2;
		k = 0;
	}
	return (tab);
}

char	*file_to_array(char *file)
{
	int		op;
	int		lec;
	char	buf[BUF_SIZE];
	char	*array;
	int		i;

	if (!(array = (char *)malloc(ft_strlen(file) * sizeof(char))))
		return (NULL);
	i = 0;
	lec = 0;
	op = open(file, O_RDONLY);
	if (op == -1)
	{
		close(op);
		return (NULL);
	}
	lec = read(op, buf, BUF_SIZE);
	array = buf;
	close(op);
	return (array);
}
