/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 14:02:45 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/20 15:50:55 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#include <stdio.h>

int			destroy_win(t_env *e)
{
	(void)e;
	exit(1);
	return (0);
}

static void		clear_image(t_env *e)
{
	int		y;

	y = 0;
	while (y <= e->img.szline * WIN_Y)
	{
		e->img.data[y] = 0;
		y++;
	}
}

void		drunk_view(t_env *e, int keycode)
{
	if (keycode == 24)
		e->p.diry += 0.1;
	else if (keycode == 27)
		e->p.diry -= 0.1;
	if (keycode == 30)
		e->p.dirx += 0.1;
	else if (keycode == 33)
		e->p.dirx -= 0.1;
	if (keycode == 15)
	{
		e->p.dirx = -1;
		e->p.diry = 0;
	}
	expose_hook(e);
}

int			key_hook(int kc, t_env *e)
{
	printf("kc%d\n", kc);
	if (kc == 24 || kc == 27 || kc == 30 || kc == 33 || kc == 15)
		drunk_view(e, kc);
	if (kc == 13 || kc == 1 || kc == 0 || kc == 2)
		move_init(e, kc);
	if (kc == 53)
		exit(1);
	return (0);
}

int			expose_hook(t_env *e)
{
	clear_image(e);
	pos_in_map(e);
	wall_dist(e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.i, 0, 0);
	put_visor(e);
	return (0);
}
