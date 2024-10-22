/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderingtwo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:01:24 by smaddox           #+#    #+#             */
/*   Updated: 2020/01/04 13:04:25 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void	setup_ray(t_game *g, t_ray *r, int x)
{
	r->cam_x = 2 * x / (float)WINDOW_X - 1;
	r->dir.x = g->player.dir.x + g->player.cam_plane.x * r->cam_x;
	r->dir.y = g->player.dir.y + g->player.cam_plane.y * r->cam_x;
	r->mpx = (int)g->player.pos.x;
	r->mpy = (int)g->player.pos.y;
	r->delta_dist.x = fabsf(1 / r->dir.x);
	r->delta_dist.y = fabsf(1 / r->dir.y);
	r->collision = 0;
	r->stepx = (r->dir.x < 0) ? -1 : 1;
	r->stepy = (r->dir.y < 0) ? -1 : 1;
	r->sd.x = ((r->dir.x < 0) ? (g->player.pos.x - r->mpx) :
			(r->mpx + 1.0 - g->player.pos.x)) * r->delta_dist.x;
	r->sd.y = ((r->dir.y < 0) ? (g->player.pos.y - r->mpy) :
			(r->mpy + 1.0 - g->player.pos.y)) * r->delta_dist.y;
}

static void	crunch_numbers(t_ray *r, float px, float py, float t)
{
	r->pwall = ((r->side == 0) ?
			((r->mpx - px + (1 - r->stepx) / 2) / r->dir.x) :
			((r->mpy - py + (1 - r->stepy) / 2) / r->dir.y));
	r->lh = (int)(WINDOW_Y / r->pwall);
	r->dstart = -(r->lh) / 2 + WINDOW_Y / 2;
	r->dstart = (r->dstart < 0) ? 0 : r->dstart;
	r->dend = r->lh / 2 + WINDOW_Y / 2;
	r->dend = ((r->dend >= WINDOW_Y) ? (WINDOW_Y - 1) : r->dend);
	r->wx = (r->side == 0) ? (py + r->pwall * r->dir.y) :
		(px + r->pwall * r->dir.x);
	r->wx -= floorf(r->wx);
	r->tx = (int)(r->wx * (float)t);
	if (((r->side == 0) && (r->dir.x > 0))
			|| ((r->side == 1) && (r->dir.y < 0)))
		r->tx = t - r->tx - 1;
}

void		cast_ray(t_map *map, t_ray *ray)
{
	int collision;

	collision = 0;
	while (!collision)
	{
		if (ray->sd.x < ray->sd.y)
		{
			ray->sd.x += ray->delta_dist.x;
			ray->mpx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sd.y += ray->delta_dist.y;
			ray->mpy += ray->stepy;
			ray->side = 1;
		}
		if (map->map[(ray->mpx + (ray->mpy * map->size_line))])
			collision = 1;
	}
}

void		draw_tex(t_image *tex, t_image *img, t_ray *r, int x)
{
	int			ty;
	int			index;
	uint32_t	color;
	uint32_t	*ptr;
	uint32_t	*pc;

	ptr = (uint32_t*)(img->data);
	pc = (uint32_t*)(tex->data);
	while (r->dstart < r->dend)
	{
		ty = ((r->dstart - WINDOW_Y / 2 + r->lh / 2) * tex->h) / r->lh;
		color = *(pc + (r->tx + (int)ty * (tex->size_line / 4)));
		index = x + (r->dstart * (img->size_line / 4));
		ptr[index] = color;
		r->dstart += 1;
	}
}

int			render(t_game *g)
{
	int		x;
	t_ray	ray;

	x = -1;
	srand((unsigned)time(NULL));
	while (++x < (WINDOW_X * WINDOW_Y) / 2)
		*((uint32_t*)(g->img.data) + x) = (rand() % 100 == 1) ? 0xfffff : 0x64;
	while (++x < (WINDOW_X * WINDOW_Y))
		*((uint32_t*)(g->img.data) + x) = 0x3000;
	x = -1;
	while (++x < WINDOW_X)
	{
		setup_ray(g, &ray, x);
		cast_ray(&(g->map), &ray);
		crunch_numbers(&ray, g->player.pos.x, g->player.pos.y, (g->tex[0]).h);
		if (ray.side == 0)
			draw_tex(&(g->tex[(ray.dir.x < 0) ? 0 : 1]), &(g->img), &ray, x);
		else
			draw_tex(&(g->tex[(ray.dir.y < 0) ? 2 : 3]), &(g->img), &ray, x);
	}
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.ptr, 0, 0);
	return (0);
}
