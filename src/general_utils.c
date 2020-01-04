/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 12:33:47 by smaddox           #+#    #+#             */
/*   Updated: 2020/01/04 13:16:26 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		write(1, "Invalid map file: commiting seppuku....\n", 40);
		exit(-1);
	}
	else if (num == 420)
	{
		write(1, "You've gone too far this time\n", 30);
		exit(-1);
	}
	else if (num == 1)
	{
		write(1, "no mapfile provided\n", 20);
		exit(-1);
	}
}

int		is_perfect_square(int num)
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

void	mlx_start(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, WINDOW_X, WINDOW_Y, WINDOW_NAME);
	game->img.ptr = mlx_new_image(game->mlx, WINDOW_X, WINDOW_Y);
	game->img.data = mlx_get_data_addr(game->img.ptr,
			&(game->img.bpp), &(game->img.size_line),
			&(game->img.endian));
}
