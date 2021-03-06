/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:57:08 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/25 13:05:54 by stmartin         ###   ########.fr       */
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
# define MAP_X 21
# define MAP_Y 23
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define DESTROYNOTIFY 17
# define STRUCT_NOT_MASK (1L<<17)

typedef struct	s_image
{
	void			*i;
	int				bpp;
	int				szline;
	int				endian;
	char			*data;
}				t_image;

typedef struct	s_col
{
	unsigned long	r;
}				t_col;

typedef struct	s_pos
{
	int				x;
	int				touch;
	double			camx;
	double			rayposx;
	double			rayposy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			raydirx;
	double			raydiry;
	double			posx;
	double			posy;
	int				mapx;
	int				mapy;
	double			distmurx;
	double			distmury;
	double			dist2murx;
	double			dist2mury;
	int				etapex;
	int				etapey;
	int				wallsens;
	int				wall_high;
	double			wall_len;
	int				texnum;
	int				drawstart;
	int				drawend;
	double			speed;
	double			drunk;
	int				is_drunk;
	int				mini;
	int				mini_len;
	int				sp;
}				t_pos;

typedef struct	s_env
{
	char			**file;
	void			*mlx;
	void			*win;
	t_image			*tex;
	t_image			img;
	t_pos			p;
	t_col			c;
	double			msd;
	double			rotsd;
}				t_env;

void			pos_in_map(t_env *e);
int				get_map(int x, int y);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
void			wall_dist(t_env *e);
int				image_put_pixel(t_env *e, int x, int y, unsigned long color);
void			verline(int x, int drawstart, int drawend, t_env *e);
void			wall_h(t_env *env);
void			wall_color(t_env *e, int x, int y, int ret);
void			move_init(t_env *e, int key);
void			draw_sky_and_floor(t_env *e, int x, int drawstart, int drawend);
void			put_visor(t_env *e);
int				key_hook2(int k, t_env *e);

#endif
