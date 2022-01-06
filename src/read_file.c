/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:06:24 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/06 12:51:59 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_line_in_file(char *file)
{
	int		count;
	int		fd;
	int		b;
	char	buf;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (check_error("The file does not open"));
	count = 1;
	b = 1;
	while (b > 0)
	{
		b = read(fd, &buf, 1);
		if (buf == '\n')
			count++;
		if (b == -1)
			print_error("The file is not read");
	}
	close(fd);
	return (count);
}
