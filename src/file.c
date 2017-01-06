/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 09:41:18 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/06 13:12:35 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This function doesn't free anything!!!
*/

int		file_to_str(char *file_path, char **str)
{
	int		fd;
	int		byte_read;
	char	buf[BUF_SIZE + 1];

	byte_read = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (error());
	else
	{
		*str = ft_strnew(0);
		while ((byte_read = read(fd, buf, BUF_SIZE)) > 0)
		{
			buf[byte_read] = '\0';
			*str = ft_strjoin(*str, buf);
		}
		close(fd);
		if (byte_read == -1)
			return (error());
	}
	return (1);
}
