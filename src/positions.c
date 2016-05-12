/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:51:37 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/12 19:45:06 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		move_pos(t_env *e)
{
	while (e->p.touch == 0)
	{
		if (e->p.distmurx < e->p.distmury)
		{
			e->p.distmurx += e->p.dist2murx;
			e->p.mapx += e->p.etapex;
			e->p.wallsens = 0;
		}
		else
		{
			e->p.distmury += e->p.dist2mury;
			e->p.mapy += e->p.etapey;
			e->p.wallsens = 1;
		}
		if (get_map(e->p.mapx, e->p.mapy) > 0)
			e->p.touch = 1;
	}
	wall_h(e);
}

void		wall_dist(t_env *e)
{
	e->p.touch = 0;
	if (e->p.raydirx < 0)
	{
		e->p.etapex = -1;
		e->p.distmurx = (e->p.rayposx - e->p.mapx) * e->p.dist2murx;
	}
	else
	{
		e->p.etapex = 1;
		e->p.distmurx = (e->p.mapx + 1.0 - e->p.rayposx) * e->p.dist2murx;
	}
	if (e->p.raydiry < 0)
	{
		e->p.etapey = -1;
		e->p.distmury = (e->p.rayposy - e->p.mapy) * e->p.dist2mury;
	}
	else
	{
		e->p.etapey = 1;
		e->p.distmury = (e->p.mapy + 1.0 - e->p.rayposy) * e->p.dist2mury;
	}
	move_pos(e);
}

void		pos_in_map(t_env *e)
{
	e->p.x = 0;
	while (e->p.x < WIN_X)
	{
		e->p.camx = 2 * e->p.x / WIN_X;
		e->p.rayposx = e->p.posx;
		e->p.rayposy = e->p.posy;
		e->p.raydirx = e->p.dirx + e->p.planex * e->p.camx;
		e->p.raydiry = e->p.diry + e->p.planey * e->p.camy;
		e->p.mapx = (int)e->p.rayposx;
		e->p.mapy = (int)e->p.rayposy;
		e->p.dist2murx = sqrt(1 + ft_p2(e->p.raydiry) / ft_p2(e->p.raydirx));
		e->p.dist2mury = sqrt(1 + ft_p2(e->p.raydirx) / ft_p2(e->p.raydiry));
		wall_dist(e);
		e->p.x++;
	}
}
