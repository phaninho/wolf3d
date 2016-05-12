/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:55:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/12 18:56:07 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
int			get_map(int x, int y)
{
	static int	map[MAP_X][MAP_Y] = {
		{1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 2},
		{1, 0, 0, 0, 0, 2},
		{1, 0, 0, 0, 0, 2},
		{1, 0, 0, 0, 0, 2},
		{1, 1, 1, 1, 1, 2}
	};
	return (map[x][y]);
}

void		call_f(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "WOLF42");
	e->img.i = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 2, 1L << 0, key_hook, e);
	e->img.data = mlx_get_data_addr(e->img.i, &(e->img.bpp), &(e->img.szline),
			&(e->img.endian));
	mlx_loop(e->mlx);
}

int			main(void)
{
	static t_env	e;

	e.p.posx = 2;
	e.p.posy = 2;
	e.p.dirx = -1;
	e.p.dirx = 0;
	call_f(&e);
	return (0);
}
