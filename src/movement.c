/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 15:16:31 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/13 17:37:35 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>
void		rotation(t_env *e, int key, double rotspd)
{
	double		oldirx;
	double		oldplanex;

	oldirx = e->p.dirx;
	oldplanex = e->p.planex;
	if (key == 2)
	{
		e->p.dirx = e->p.dirx * cos(-rotspd) - e->p.diry * sin(-rotspd);
		e->p.diry = oldirx * sin(-rotspd) + e->p.diry * cos(-rotspd);
		e->p.planex = e->p.planex * cos(-rotspd) - e->p.planey * sin(-rotspd);
		e->p.planey = oldplanex * sin(-rotspd) + e->p.planey * cos(-rotspd);
	}
	else
	{
		e->p.dirx = e->p.dirx * cos(rotspd) - e->p.diry * sin(rotspd);
		e->p.diry = oldirx * sin(rotspd) + e->p.diry * cos(rotspd);
		e->p.planex = e->p.planex * cos(rotspd) - e->p.planey * sin(rotspd);
		e->p.planey = oldplanex * sin(rotspd) + e->p.planey * cos(rotspd);
	}
}

void		move_init(t_env *e, int keycode)
{
	double		movespeed;
	double		rotspeed;

	movespeed = 0.1;
	rotspeed = 0.05;
	if (keycode == 13)
	{
		if (!(get_map((int)(e->p.posx + e->p.dirx * movespeed), (int)e->p.posy)))
			e->p.posx += e->p.dirx * movespeed;
		if (!(get_map((int)e->p.posx, (int)(e->p.posy + e->p.diry * movespeed))))
			e->p.posy += e->p.diry * movespeed;
	}
	else if (keycode == 1)
	{
		if (!(get_map((int)(e->p.posx - e->p.dirx * movespeed), (int)e->p.posy)))
			e->p.posx -= e->p.dirx * movespeed;
		if (!(get_map((int)e->p.posx, (int)(e->p.posy - e->p.diry * movespeed))))
			e->p.posy -= e->p.diry * movespeed;
	}
	else if (keycode == 0 || keycode == 2)
		rotation(e, keycode, rotspeed);
	expose_hook(e);
}
