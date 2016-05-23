/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:27:54 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/23 18:05:24 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void			put_visor(t_env *e)
{
	mlx_string_put(e->mlx, e->win, (WIN_X / 2) - 9, (WIN_Y / 2), 0xffffff, ".");
	mlx_string_put(e->mlx, e->win, (WIN_X / 2) + 9, (WIN_Y / 2), 0xffffff, ".");
	mlx_string_put(e->mlx, e->win, (WIN_X / 2), (WIN_Y / 2) - 9, 0xffffff, ".");
	mlx_string_put(e->mlx, e->win, (WIN_X / 2), (WIN_Y / 2) + 9, 0xffffff, ".");
	if (e->p.step > 100 * 3)
		mlx_string_put(e->mlx, e->win, 10, 17, 0x0000ff, "Teleportation Actif");
	else
	{
		mlx_string_put(e->mlx, e->win, 150, 17, 0xff00ff,
				ft_itoa(e->p.step / 3));
		mlx_string_put(e->mlx, e->win, 10, 17, 0x0000ff, "steps score : ");
	}
	if (e->p.is_drunk == 1)
		mlx_string_put(e->mlx, e->win, 10, 37, 0xff0000, "Drunk mode actif!");
	if (e->p.mini == 1)
		mlx_string_put(e->mlx, e->win, 10, 57, 0x00ff00, "Cherie j'ai \
				retrecie un eleve de 42!");
}

void			draw_sky_and_floor(t_env *e, int x, int drawstart, int drawend)
{
		e->c.r = 0x87cefa;
		verline(x,0, drawstart, e);
		e->c.r = 0x006600;
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
