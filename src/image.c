/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:27:54 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/17 17:38:43 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void			draw_sky_and_floor(t_env *e, int x, int drawstart, int drawend)
{
		e->c.r = 0x87cefa;
		verline(x,0, drawstart, e);
		e->c.r = 0x8fbc8f;
		verline(x,drawend, WIN_Y, e);
}

void			verline(int x, int drawstart, int drawend, t_env *e)
{
	if (x == WIN_X)
		return ;
	while (drawstart != drawend)
	{
		if (!(image_put_pixel(e, x, drawstart, e->c.r)))
			break ;
		drawstart < drawend ? drawstart++ : drawstart--;
	}
	image_put_pixel(e, x, drawstart, e->c.r);
}

//unsigned long	colorrgb(t_env *e, int x, int y)
//{
//	wall_color(e, x, y);
//	return ((e->c.r + 65536) + (e->c.g + 256) + e->c.b);
//}

int				image_put_pixel(t_env *e, int x, int y, unsigned long color)
{
	int		pos;

	pos = (x * e->img.bpp / 8) + (y * e->img.szline);
	if (pos < 0 || pos > e->img.szline * WIN_Y - 1)
		return (0);
	if (e->img.endian)
	{
		e->img.data[pos] = color / 65536 % 256;
		e->img.data[pos + 1] = color / 256 % 256;
		e->img.data[pos + 2] = color % 256;
	}
	else
	{
		e->img.data[pos + 2] = color / 65536 % 256;
		e->img.data[pos + 1] = color / 256 % 256;
		e->img.data[pos] = color % 256;
	}
	return (1);
}
