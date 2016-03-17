/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:19:23 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/17 18:13:06 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "fdf.h"

int					main(int argc, char **argv)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1080, 768, "Fdf");
	if (check_basic(argc) || check_file(argv[1]))
		return (0);
		ft_putstr("all ok\n");
	if (check_map(argv[1]) && check_len(argv[1]))
		return (0);
		ft_putstr("all ok\n");
	parse_map(argv[1], &env);
	env.posx = -(50 * env.lenx / 2 - 1980 / 2);
	printf("posx = %d\n", env.posx);
	env.posy = -(50 * env.leny / 2 - 1268 / 2);
	env.zoom = 30;
	env.z = 2;
	env.r = 3;
	env.t=  3;
	printf("posy = %d\n", env.posy);
	play(&env);
	return (0);
}

static int			key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);

	more_key(keycode, env);
	if (keycode == 5)
		env->t = env->t - 3;
	else
		printf("keycode = %d\n", keycode);
	mlx_clear_window(env->mlx, env->win);
	play(env);
	return (0);
}
int					play(t_env *env)
{
	int y;
	int x;

	y = 0;
	printf("play\n");
	while (y < env->leny)
	{
		x = 0;
		while (x < env->lenx)
		{
			if (x != env->lenx -1)
			{
				env->x0 = x * env->zoom - (y ) * env->r - env->tab[y][x] * env->z + env->posx;
				env->y0 = y * env->zoom + (x ) * env->t - env->tab[y][x] * env->z + env->posy;
				env->x1 = (x + 1) * env->zoom - (y ) * env->r - env->tab[y][x + 1] * env->z + env->posx;
				env->y1 = (y) * env->zoom + (x + 1) * env->t - env->tab[y][x + 1] * env->z + env->posy;
				line(env, 65000 +  env->tab[y][x + 1] * env->z);
			}
			if (y != env->leny - 1)
			{
				env->x0 = x * env->zoom  -  (y) * env->r - env->tab[y][x] * env->z + env->posx;
				env->y0 = y * env->zoom  +  (x) * env->t - env->tab[y][x] * env->z + env->posy;
				env->x1 = (x) * env->zoom - (y + 1) * env->r - env->tab[y + 1][x] * env->z + env->posx;
				env->y1 = (y + 1) * env->zoom + (x) * env->t - env->tab[y + 1][x] * env->z + env->posy;
				line(env, 65000 + env->tab[y + 1][x] * env->z);
			}
			x++;
		}
		y++;
	}
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
static int			more_key(int keycode, t_env *env)
{
	if (keycode == 124)
		env->posx = env->posx + env->zoom;
	if (keycode == 126)
		env->posy = env->posy - env->zoom;
	if (keycode == 125)
		env->posy = env->posy + env->zoom;
	if (keycode == 123)
		env->posx = env->posx - env->zoom;
	if (keycode == 69)
		env->zoom = env->zoom + 2;
	if (keycode == 78 && env->zoom > 2)
		env->zoom = env->zoom - 2;
	if (keycode == 7)
		env->z = env->z - 3;
	if (keycode == 8)
		env->z = env->z + 3;
	if (keycode == 15)
		env->r = env->r + 3;
	if (keycode == 17)
		env->t = env->t + 3;
	if (keycode == 3)
		env->r = env->r - 3;
		return (1);
}
