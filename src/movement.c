/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 15:16:31 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/23 16:47:20 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>
void		teleport(t_env *e)
{
	if (e->p.posx >= 19 && e->p.posx < 19.45 && e->p.posy > 21.1 &&
			e->p.posy < 21.9 && e->p.step > 100 * 3)
	{
		e->p.posx = 5.5;
		e->p.posy = 1.5;
	}
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
	e->msd = 0.14 + e->p.speed;
	e->rotsd = 0.1;
	if (keycode == 13)
	{
		if (!(get_map((int)(e->p.posx + e->p.dirx * e->msd), (int)e->p.posy)) ||
			get_map((int)(e->p.posx + e->p.dirx * e->msd), (int)e->p.posy) > 8)
			e->p.posx += e->p.dirx * e->msd;
		if (!(get_map((int)e->p.posx, (int)(e->p.posy + e->p.diry * e->msd))))
			e->p.posy += e->p.diry * e->msd;
		e->p.step++;
	}
	else if (keycode == 1)
	{
		if (!(get_map((int)(e->p.posx - e->p.dirx * e->msd), (int)e->p.posy)))
			e->p.posx -= e->p.dirx * e->msd;
		if (!(get_map((int)e->p.posx, (int)(e->p.posy - e->p.diry * e->msd))))
			e->p.posy -= e->p.diry * e->msd;
		e->p.step++;
	}
	if (keycode == 0 || keycode == 2)
		rotation(e, keycode, e->rotsd);
		teleport(e);
}
