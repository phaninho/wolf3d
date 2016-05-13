/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 14:02:45 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/13 14:22:11 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#include <stdio.h>
static void		clear_image(t_env *e)
{
	int		y;

	y = 0;
	while(y <= e->img.szline * WIN_Y)
	{
		e->img.data[y] = 0;
		y++;
	}
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == 13)
		e->p.my--;
	else if (keycode == 1)
		e->p.my++;
	else if (keycode == 0)
		e->p.mx--;
	else if (keycode == 2)
		e->p.mx++;
	printf("mx %f my %f\n", e->p.mx, e->p.my);
	if (keycode == 53)
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
	return (0);
}
