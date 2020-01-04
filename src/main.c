/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 09:36:55 by smaddox           #+#    #+#             */
/*   Updated: 2020/01/04 13:05:52 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		rip_window(void)
{
	exit(0);
}

void	set_tex(t_game *g)
{
	static char	*files[4] = { "tex/brick.xpm", "tex/metal.xpm",
	"tex/stone.xpm", "tex/wood.xpm" };
	int			i;
	t_image		*p;

	i = -1;
	while (++i < 4)
	{
		p = &(g->tex[i]);
		p->ptr = mlx_xpm_file_to_image(g->mlx, files[i], &(p->l), &(p->h));
		p->data = mlx_get_data_addr(p->ptr, &(p->bpp),
				&(p->size_line), &(p->endian));
	}
}

int		main(int ac, char **av)
{
	t_game game;

	panic(ac);
	get_map(av[1], &game);
	get_player(&game);
	mlx_start(&game);
	set_tex(&game);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_do_key_autorepeaton(game.mlx);
	mlx_hook(game.mlx_win, 2, 0, &key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, &rip_window, NULL);
	mlx_loop(game.mlx);
	return (0);
}
