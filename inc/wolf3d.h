/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:08:17 by smaddox           #+#    #+#             */
/*   Updated: 2020/01/04 13:25:33 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include "libft.h"

# define WINDOW_X 800
# define WINDOW_Y 600
# define MAX_MAP_SIZE 4096
# define WINDOW_NAME "wolf3d"

typedef struct	s_vector
{
	float		x;
	float		y;
}				t_vector;

typedef struct	s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	cam_plane;
}				t_player;

typedef struct	s_ray
{
	t_vector	dir;
	t_vector	sd;
	t_vector	delta_dist;
	int			mpx;
	int			mpy;
	float		cam_x;
	float		pwall;
	int			stepx;
	int			stepy;
	int			collision;
	int			side;
	int			lh;
	int			dstart;
	int			dend;
	float		wx;
	int			tx;
	int			tc;
}				t_ray;

typedef struct	s_map
{
	int			size;
	int			size_line;
	int			map[MAX_MAP_SIZE];
}				t_map;

typedef struct	s_image
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			h;
	int			l;
}				t_image;

typedef struct	s_game
{
	t_map		map;
	t_player	player;
	void		*mlx;
	void		*mlx_win;
	t_image		img;
	t_image		tex[4];
}				t_game;

void			get_map(char *file, t_game *g);
void			print_map(t_map map);
int				key_hook(int key_code, t_game *g);
int				render(t_game *g);
int				is_perfect_square(int num);
void			panic(int num);
void			get_player(t_game *g);
void			mlx_start(t_game *game);

#endif
