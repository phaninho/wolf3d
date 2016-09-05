/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 14:02:45 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/25 13:05:46 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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

int				key_hook2(int kc, t_env *e)
{
	if (kc == 259 || kc == 256)
		e->p.speed = 0;
	return (0);
}

void			mode_mini(t_env *e, int kc)
{
	if (kc == 14)
	{
		e->p.mini_len = 3;
		e->p.mini = 1;
		e->p.speed = -0.1;
	}
	else
	{
		e->p.mini = 0;
		e->p.mini_len = 1;
		e->p.speed = 0;
	}
}

int				key_hook(int kc, t_env *e)
{
	if (kc == 14 || kc == 15)
		mode_mini(e, kc);
	if (kc == 3)
	{
		e->p.is_drunk = 1;
		e->p.drunk = 200;
	}
	else if (kc == 5)
	{
		e->p.is_drunk = 0;
		e->p.drunk = 0;
	}
	if (kc == 13 || kc == 1 || kc == 0 || kc == 2)
		move_init(e, kc);
	if (kc == 256)
		e->p.speed = -0.1;
	if (kc == 259)
		e->p.speed = 0.15;
	if (kc == 53)
		exit(1);
	expose_hook(e);
	return (0);
}

int				expose_hook(t_env *e)
{
	clear_image(e);
	pos_in_map(e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.i, 0, 0);
	put_visor(e);
	return (0);
}
