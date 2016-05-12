/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:51:37 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/12 13:55:49 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#include <stdio.h>
void		pos_in_map(t_env *e)
{
	e->p.posy = 0;
	while (e->p.posy < MAP_Y)
	{
		e->p.posx= 0;
		while (e->p.posx < MAP_X)
		{
			printf("yx [%0.0f][%0.0f] map: %d ",e->p.posy, e->p.posx, get_map(e->p.posx, e->p.posy));
			e->p.posx++;
		}
		printf("\n");
		e->p.posy++;
	}
}
