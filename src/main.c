/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:55:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/11 20:03:15 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>
int			get_map(int x, int y)
{
	static int	map[MAP_X][MAP_Y] = {
		{1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1}
	};
	return (map[x][y]);
}

void		call_f(void)
{
	int		x;
	int		y;

	y = 0;
	while (y < MAP_Y)
	{
		x= 0;
		while (x < MAP_X)
		{
			printf("%d ",get_map(x, y));
			x++;
		}
		printf("\n");
		y++;
	}
}

int			main(void)
{
	call_f();
	return (0);
}
