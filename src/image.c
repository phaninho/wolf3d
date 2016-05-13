/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:27:54 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/13 15:02:44 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>
void			verline(int x, int drawstart, int drawend, t_env *e)
{
	if (x == WIN_X)
		return ;
	while (drawstart != drawend)
	{
		image_put_pixel(&(e->img), x, drawstart, e->c.r);
		drawstart < drawend ? drawstart++ : drawstart--;
	}
	image_put_pixel(&(e->img), x, drawstart, e->c.r);
}

unsigned long	colorrgb(t_env *e, int x, int y)
{
	wall_color(e, x, y);
	return ((e->c.r + 65536) + (e->c.g + 256) + e->c.b);
}

void			image_put_pixel(t_image *i, int x, int y, unsigned long color)
{
	if (i->endian)
	{
		i->data[(x * i->bpp / 8) + (y * i->szline)] = color / 65536 % 256;
		i->data[(x * i->bpp / 8) + 1 + (y * i->szline)] = color / 256 % 256;
		i->data[(x * i->bpp / 8) + 2 + (y * i->szline)] = color % 256;
	}
	else
	{
		i->data[(x * i->bpp / 8) + 2 + (y * i->szline) ] = color / 65536 % 256;
		i->data[(x * i->bpp / 8) + 1 + (y * i->szline)] = color / 256 % 256;
		i->data[(x * i->bpp / 8) + (y * i->szline)] = color % 256;
	}
}
