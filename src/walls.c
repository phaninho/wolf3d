/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 18:03:56 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/19 19:41:05 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:51:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/19 18:03:54 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void		change_wall_color(t_env *e)
{
	e->c.r /= 2;
	e->c.g /= 2;
	e->c.b /= 2;
}

void		wall_color(t_env *e, int x, int y, int ret)
{
	//texture_coordxy(e, x, y);
(void)x;
(void)y;
	if (ret == 1)
		e->c.r = 0xff0000;
	if (ret == 2)
		e->c.r = 0x00ff00;
	if (ret == 3)
		e->c.r = 0x0000ff;
	if (ret == 4)
		e->c.r = 0xf0f0f0;
	verline(e->p.x, e->p.drawstart, e->p.drawend, e);
//	texture_coordxy(e, x, y);
/*	if (get_map(x, y) == 1)
	{
		e->c.r = 0xFF;
		e->c.g = 0x00;
		e->c.b = 0x00;
	}
	else if (get_map(x, y) == 2)
	{
		e->c.r = 0x00;
		e->c.g = 0xFF;
		e->c.b = 0x00;
	}
	else if (get_map(x, y) == 3)
	{
		e->c.r = 0x00;
		e->c.g = 0x00;
		e->c.b = 0xFF;
	}
	else if (get_map(x, y) == 4)
	{
		e->c.r = 0x0f;
		e->c.g = 0x0f;
		e->c.b = 0x0f;
	}
	e->p.wallsens == 1 ? change_wall_color(e) : 1;*/
}
int			give_color(double rdirxy, int t)
{
	if (t == 1)
	{
		if (rdirxy > 0)
			return (1);
		return (2);
	}
	if (t == 2)
		if (rdirxy > 0)
			return (3);
	return (4);
}

void		wall_h(t_env *e)
{
	int ret;

	if (e->p.wallsens == 0)
	{
		e->p.wall_len = fabs((e->p.mapx - e->p.rayposx + (1 - e->p.etapex) / 2)
				/ e->p.raydirx);
		ret = give_color(e->p.raydirx, 1);
	}
	else
	{
		e->p.wall_len = fabs((e->p.mapy - e->p.rayposy + (1 - e->p.etapey) / 2)
				/ e->p.raydiry);
		ret = give_color(e->p.raydiry, 2);
	}
	if (e->p.wall_len <= 0.100000)
		e->p.wall_len += 0.1;
		e->p.wall_high = abs((int)(WIN_Y / e->p.wall_len));
	e->p.drawstart = -e->p.wall_high / 2 + WIN_Y / 2;
	if (e->p.drawstart < 0)
		e->p.drawstart = 0;
	e->p.drawend = e->p.wall_high / 2 + WIN_Y / 2;
	if (e->p.drawend >= WIN_Y)
		e->p.drawend = WIN_Y - 1;
	draw_sky_and_floor(e, e->p.x, e->p.drawstart, e->p.drawend);
	wall_color(e, e->p.mapx, e->p.mapy, ret);
}
