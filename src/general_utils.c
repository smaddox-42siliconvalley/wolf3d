#include <wolf3d.h>

void	panic(int num)
{
	if (num == -1)
	{
		perror("The program commited seppuku for the following reason");
		exit(-1);
	}
	else if (num == 898)
	{
		ft_printf("Invalid map file: commiting seppuku....\n");
		exit(-1);
	}
}

int	is_perfect_square(int num)
{
	int		i;
	float	f;

	f = sqrt((float)num);
	i = f;
	return ((f == i));
}

void	get_player(t_game *g)
{
	g->player.pos.x = 22;
	g->player.pos.y = 12;
	g->player.dir.x = -1;
	g->player.dir.y = 0;
	g->player.cam_plane.x = 0;
	g->player.cam_plane.y = 0.66;
}

void		mlx_start(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, WINDOW_X, WINDOW_Y, WINDOW_NAME);
	game->img.ptr = mlx_new_image(game->mlx, WINDOW_X, WINDOW_Y);
	game->img.data = mlx_get_data_addr(game->img.ptr,
			&(game->img.bpp), &(game->img.size_line),
			&(game->img.endian));
}

int		key_hook(int keycode, t_game *g)
{
	if(keycode == 53)
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
	{
		float temp;
		float rotspeed;

		temp = g->player.dir.x;
		rotspeed = .1;
		g->player.dir.x = g->player.dir.x * cos(-(rotspeed)) - g->player.dir.y * sin(-(rotspeed));
		g->player.dir.y = temp * sin(-(rotspeed)) + g->player.dir.y * cos(-(rotspeed));
		temp = g->player.cam_plane.x;
		g->player.cam_plane.x = g->player.cam_plane.x  * cos(-rotspeed) - g->player.cam_plane.y * sin(-(rotspeed));
		g->player.cam_plane.y = temp * sin(-rotspeed) + g->player.cam_plane.y * cos(-(rotspeed));
	}
	else if (keycode == 0)
	{
		float temp;
		float rotspeed;

		temp = g->player.dir.x;
		rotspeed = .1;
		g->player.dir.x = g->player.dir.x * cos((rotspeed)) - g->player.dir.y * sin((rotspeed));
		g->player.dir.y = temp * sin((rotspeed)) + g->player.dir.y * cos((rotspeed));
		temp = g->player.cam_plane.x;
		g->player.cam_plane.x = g->player.cam_plane.x  * cos(rotspeed) - g->player.cam_plane.y * sin((rotspeed));
		g->player.cam_plane.y = temp * sin(rotspeed) + g->player.cam_plane.y * cos((rotspeed));
	}
	return(0);
}
