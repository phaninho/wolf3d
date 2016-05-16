/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_for_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 22:19:27 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/16 19:34:20 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#include <stdio.h>
void		texture_coordy(t_env *e, int texx)
{
	int		y;
	int		d;
	int		texy;

	y = e->p.drawstart;
	while (y < e->p.drawend)
	{
		d = y * 256 - WIN_Y * 128 + e->p.wall_high * 128;
		texy = ((d * TEXHEIGHT) / e->p.wall_high) / 256;
		e->c.r = e->file[e->p.texnum][TEXHEIGHT * texy + texx];
	//	printf("co %lu\n", e->c.r);
	//	if (e->p.wallsens == 1)
	//		e->c.r = (e->c.r >> 1) & 8355711;
		image_put_pixel(e, e->p.x, y, e->c.r);
		y++;
	}
}
void		texture_coordxy(t_env *e, int x, int y)
{
	double	wallx;
	int		texx;

	e->p.texnum = get_map(x, y);
	if (e->p.wallsens == 0)
		wallx = e->p.rayposy + e->p.wall_len * e->p.rayposy;
	else
		wallx = e->p.rayposx + e->p.wall_len * e->p.rayposx;
	wallx -= floor((wallx));
	texx = (int)(wallx * (double)(TEXWIDTH));
	if (e->p.wallsens == 0 && e->p.raydirx > 0)
		texx = TEXWIDTH - texx - 1;
	if (e->p.wallsens == 1 && e->p.raydiry < 0)
		texx = TEXWIDTH - texx - 1;
	texture_coordy(e, texx);
}
