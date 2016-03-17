/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:21:11 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/17 17:59:43 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				check_basic(int n)
{
	if (n == 1)
	{
		ft_putendl("Usage [./fdf file.fdf]");
		return (1);
	}
	if (n > 2)
	{
		ft_putendl("too many arguments");
		return (1);
	}
	return (0);
}

int				check_file(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Fdf");
		return (1);
	}
	close(fd);
	return (0);
}

static int		check_ext(int fd)
{
	ft_putstr("Map invalide : bad character \n");
	close(fd);
	return (1);
}

static int		diff_line(int fd)
{
	ft_putstr("Line len not equal\n");
	close(fd);
	return (1);
}

int				check_map(char *path)
{
	char	*line;
	int		fd;
	int		i;
	int		len;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i = 0;
		if (!line)
			return (check_ext(fd));
		ft_putendl(line);
		while (line[i])
		{
			if (!(line[i] >= '0' && line[i] <= '9') && line[i] != 32 &&
			line[i] != '-')
				return (check_ext(fd));
			i++;
		}
	}
	close(fd);
	return (0);
}
