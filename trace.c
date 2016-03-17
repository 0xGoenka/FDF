/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:36:13 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/17 18:02:24 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int n)
{
	return ((n < 0) ? -n : n);
}

void	line(t_env *env, int color)
{
	int x0;
	int y0;
	int dx;
	int dy;
	int err;

	x0 = env->x0;
	y0 = env->y0;s
	dx = ft_abs(env->x1 - x0), sx = x0 < env->x1 ? 1 : -1;
	dy = ft_abs(env->y1 - y0), sy = y0 < env->y1 ? 1 : -1;
	err = (dx>dy ? dx : -dy)/2, e2;

  	while (1)
	{
    	mlx_pixel_put(env->mlx, env->win, x0, y0, color);
    	if (x0 == env->x1 && y0 == env->y1) break;
    	e2 = err;
    	if (e2 >-dx) { err -= dy; x0 += sx; }
    	if (e2 < dy) { err += dx; y0 += sy; }
  	}
}

int		check_len(char *path)
{
	char	*line;
	int		fd;
	int		i;
	int		len;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		len = tab_len(ft_strsplit(line, ' '));
		i = 0;
		if (!line)
			return (check_ext(fd));
		if (len != tab_len(ft_strsplit(line, ' ')))
			return (diff_line(fd));
	}
	close(fd);
	return (0);
}
