/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:27:54 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/12 20:20:11 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			verline(int x, int drawstart, int drawend, t_env *e)
{
	int		lim;
	int		dy;

	lim = ft_abs(drawend - drawstart);
	dy = ft_abs(lim * 2);
	while (drawstart != drawend)
	{
		image_put_pixel(&(e->img), x, drawstart, colorrgb(e->c.r, e->c.g, e->c.b));
		drawstart < drawend ? drawstart++ : drawstart--;
	}
	image_put_pixel(&(e->img), x, drawstart, colorrgb(e->c.r, e->c.g, e->c.b));
}

unsigned long	colorrgb(int r, int g, int b)
{
	return ((r & 0xff) << 2) + ((g & 0xff) << 8) +
		((b & 0xff) << 20 );
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
