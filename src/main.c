#include "wolf3d.h"



//keycodes 
//13 = 'w'
//1 = 's'
//2 = 'd'
//0 = 'a'

void	set_tex(t_game *g)
{
	static char	*files[4] = { "tex/brick.xpm", "tex/metal.xpm",
	"tex/stone.xpm", "tex/wood.xpm" };
	int i;
	t_image *p;

	i = -1;
	while(++i < 4)
	{
		p = &(g->tex[i]);
		p->ptr = mlx_xpm_file_to_image(g->mlx, files[i], &(p->l),&(p->h));
		p->data = mlx_get_data_addr(p->ptr, &(p->bpp),
				&(p->size_line), &(p->endian));
	}
}


void	print_map(t_map map)
{
	for (int i = 0; i < map.size; i++)
	{
		if (i != 0 && (i % map.size_line == 0))
			write(1, "\n", 1);
		char temp = map.map[i] + '0';
		write(1, &temp, 1);
	}
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_game game;
	get_map(av[1], &game);
	get_player(&game);
	mlx_start(&game);
	set_tex(&game);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_key_hook(game.mlx_win, &key_hook, &game);
	mlx_loop(game.mlx);
	return(0);
}




