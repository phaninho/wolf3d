/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 15:16:31 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/23 13:05:48 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>
void		teleport(t_env *e)
{
	e->p.posx = 5.5;
	e->p.posy = 1.5;
}

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
	double		mspeed;
	double		rotspeed;

	mspeed = 0.14 + e->p.speed;
	rotspeed = 0.1;
	if (keycode == 13)
	{
		if (!(get_map((int)(e->p.posx + e->p.dirx * mspeed), (int)e->p.posy)))
			e->p.posx += e->p.dirx * mspeed;
		if (!(get_map((int)e->p.posx, (int)(e->p.posy + e->p.diry * mspeed))))
			e->p.posy += e->p.diry * mspeed;
		e->p.step++;
	}
	else if (keycode == 1)
	{
		if (!(get_map((int)(e->p.posx - e->p.dirx * mspeed), (int)e->p.posy)))
			e->p.posx -= e->p.dirx * mspeed;
		if (!(get_map((int)e->p.posx, (int)(e->p.posy - e->p.diry * mspeed))))
			e->p.posy -= e->p.diry * mspeed;
		e->p.step++;
	}
	if (keycode == 0 || keycode == 2)
		rotation(e, keycode, rotspeed);
	if (e->p.posx > 19 && e->p.posx < 20 && e->p.posy > 21.3 && e->p.posy < 22)
		teleport(e);
}
