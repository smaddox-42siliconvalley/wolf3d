#include "wolf3d.h"



//keycodes 
//13 = 'w'
//1 = 's'
//2 = 'd'
//0 = 'a'






void	print_map(t_map map)
{
	int i = 0;
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
	t_game game;
	get_map(av[1], &game);
	get_player(&game);
	mlx_start(&game);
	//render(&game);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_key_hook(game.mlx_win, &key_hook, &game);
	mlx_loop(game.mlx);
	return(0);
}




