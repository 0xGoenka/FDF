/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:15:24 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/17 17:52:19 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINX 1024
# define WINY 768

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h>


typedef struct		s_env
{
	int **tab;
	int lenx;
	int leny;
	int	x0;
	int y0;
	int x1;
	int y1;
	int posx;
	int posy;
	int	zoom;
	int z;
	int r;
	int t;
	void *mlx;
	void *win;
}					t_env;

int				check_len(char *path);
static int	more_key(int keycode, t_env *env);
int		check_basic(int n);
int		check_file(char *path);
int		check_map(char *path);
int		play(t_env *env);
int		**parse_map(char *path, t_env *env);
int		**fill_it(int fd, int lenx, int leny);
void 	line(t_env *env, int color);
int		ft_abs(int n);

#endif
