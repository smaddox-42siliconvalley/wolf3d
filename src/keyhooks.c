/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 09:46:23 by smaddox           #+#    #+#             */
/*   Updated: 2020/01/04 12:33:10 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void	rot_player(t_player *p, int lr)
{
	float t;
	float rot;

	t = p->dir.x;
	rot = .2;
	rot = (lr == 0) ? -(rot) : rot;
	p->dir.x = p->dir.x * cos(rot) - p->dir.y * sin(rot);
	p->dir.y = t * sin(rot) + p->dir.y * cos(rot);
	t = p->cam_plane.x;
	p->cam_plane.x = p->cam_plane.x * cos(rot) - p->cam_plane.y * sin(rot);
	p->cam_plane.y = t * sin(rot) + p->cam_plane.y * cos(rot);
}

int			key_hook(int keycode, t_game *g)
{
	if ((g->player.pos.x + g->player.pos.y * g->map.size) < 0 ||
	(g->player.pos.x + g->player.pos.y * g->map.size) > WINDOW_X * WINDOW_Y)
		panic(420);
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
	{
		g->player.pos.x += g->player.dir.x;
		g->player.pos.y += g->player.dir.y;
	}
	else if (keycode == 1)
	{
		g->player.pos.x -= g->player.dir.x;
		g->player.pos.y -= g->player.dir.y;
	}
	else if (keycode == 2)
		rot_player(&(g->player), 0);
	else if (keycode == 0)
		rot_player(&(g->player), 1);
	return (0);
}
