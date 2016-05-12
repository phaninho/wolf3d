/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:57:08 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/12 15:11:34 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

# define WIN_X 1000
# define WIN_Y 1000 / 16 * 9
# define MAP_X 6
# define MAP_Y 6

typedef struct			s_image
{
	void		*i;
	int			bpp;
	int			szline;
	int			endian;
	char		*data;
}						t_image;

typedef struct			s_pos
{
	double		camx;
	double		camy;
	double		rayposx;
	double		rayposy;
	double		posx;
	double		posy;
}						t_pos;

typedef struct			s_env
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_pos		p;
}						t_env;

void		pos_in_map(t_env *e);
int			get_map(int x, int y);
int			expose_hook(t_env *e);
int			key_hook(int keycode, t_env *e);

#endif
