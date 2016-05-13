/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:57:08 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/13 20:14:30 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

# define WIN_X 1000.0
# define WIN_Y 1000.0 / 16 * 9
# define MAP_X 8
# define MAP_Y 8
# define DESTROYNOTIFY 17
# define STRUCT_NOT_MASK (1L<<17)

typedef struct			s_image
{
	void		*i;
	int			bpp;
	int			szline;
	int			endian;
	char		*data;
}						t_image;

typedef struct			s_col
{
	unsigned long	r;
	unsigned long	g;
	unsigned long	b;
}						t_col;

typedef struct			s_pos
{
	int			x;
	int			touch;
	double		camx;
	double		rayposx;
	double		rayposy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		raydirx;
	double		raydiry;
	double		posx;
	double		posy;
	int			mapx;
	int			mapy;
	double		distmurx;
	double		distmury;
	double		dist2murx;
	double		dist2mury;
	int			etapex;
	int			etapey;
	int			wallsens;
	int			wall_high;
	double		wall_len;
}						t_pos;

typedef struct			s_env
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_pos		p;
	t_col		c;
}						t_env;

void			pos_in_map(t_env *e);
int				get_map(int x, int y);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
void			wall_dist(t_env *e);
int				image_put_pixel(t_image *i, int x, int y, unsigned long color);
unsigned long	colorrgb(t_env *e, int x, int y);
void			verline(int x, int drawstart, int drawend, t_env *e);
void			wall_h(t_env *e);
void			wall_color(t_env *e, int x, int y);
void			move_init(t_env *e, int key);
void			draw_sky_and_floor(t_env *e, int x, int drawstart, int drawend);
int				destroy_win(t_env *e);

#endif
