/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 14:02:45 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/20 19:48:31 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#include <stdio.h>


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

int			key_hook2(int kc, t_env *e)
{
	if (kc == 101 || kc == 65507)
		e->p.speed = 0;
	return (0);
}

int			key_hook(int kc, t_env *e)
{
	if (kc == 65362 || kc == 65364 || kc == 65363 || kc == 65361)
		move_init(e, kc);
	if (kc == 65507)
		e->p.speed = -0.15;
	if (kc == 101)
		e->p.speed = 0.8;
	if (kc == 65307)
		exit(1);
	expose_hook(e);
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
