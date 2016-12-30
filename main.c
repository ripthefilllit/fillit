/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:06:18 by bzmuda            #+#    #+#             */
/*   Updated: 2016/12/30 13:39:12 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int argc, char **argv)
{
	char *lol;
	char **zen;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file");
		return (0);
	}
	lol = file_to_array(argv[1]);
	zen = split_array(lol);
	if (!check_file(zen))
	{
		ft_putstr_fd("error\n", 2);
		return (0);
	}
	// Stocker every tetriminos dans une linked list ?
	// Resolution
	return (0);
}
// Ajouter la lib putchar strlen putstr putstrfd needed