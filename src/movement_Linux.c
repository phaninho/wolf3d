/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 15:16:31 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/20 18:27:26 by stmartin         ###   ########.fr       */
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
	if (key == 65363)
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

	mspeed = 0.2 + e->p.speed;
	rotspeed = 0.15;
	if (keycode == 65362)
	{
		if (!(get_map((int)(e->p.posx + e->p.dirx * mspeed), (int)e->p.posy)))
			e->p.posx += e->p.dirx * mspeed;
		if (!(get_map((int)e->p.posx, (int)(e->p.posy + e->p.diry * mspeed))))
			e->p.posy += e->p.diry * mspeed;
	}
	else if (keycode == 65364)
	{
		if (!(get_map((int)(e->p.posx - e->p.dirx * mspeed), (int)e->p.posy)))
			e->p.posx -= e->p.dirx * mspeed;
		if (!(get_map((int)e->p.posx, (int)(e->p.posy - e->p.diry * mspeed))))
			e->p.posy -= e->p.diry * mspeed;
	}
	if (e->p.posx > 19 && e->p.posx < 20 && e->p.posy > 21.3 && e->p.posy < 22)
		teleport(e);
	if (keycode == 65363 || keycode == 65361)
		rotation(e, keycode, rotspeed);
}
