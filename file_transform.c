/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 09:41:18 by bzmuda            #+#    #+#             */
/*   Updated: 2016/12/30 10:17:04 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		k;

	i = 0;
	j = 0;
	k = 0;
	calc_char = ft_strlen(array) / 20;
	printf("%d : le nb de tetrimino", calc_char);
	//MALLOC PLS
	while (array[i])
	{
		tab[j][k] = array[i];
		if (i == 20 || i == 40 || i == 60)// Toujours nul a chier
		{
			j++;
			i++;
			k = 0;
		}
		k++;
		i++;
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
