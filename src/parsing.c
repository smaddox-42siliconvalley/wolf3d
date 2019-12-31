/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 07:11:00 by smaddox           #+#    #+#             */
/*   Updated: 2019/12/30 16:47:43 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
static void	fuckthelines(char *ch_buf, t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(ch_buf[i] && (i < MAX_MAP_SIZE))
	{
		if(ch_buf[i] != '0' && ch_buf[i] != '\n' && ch_buf[i] != '1')
			panic(898);
		if(ch_buf[i] != '\n')
		{
			map->map[j] = (ch_buf[i] - '0');
			j++;
		}
		i++;
	}
	ft_printf("%d\n", j);
	if(is_perfect_square(j))
	{
		map->size_line = sqrt(j);
		map->size = j;
	}
	else
	{
		ft_printf("not square");
		panic(898);
	}
}

void	get_map(char *file, t_game *game)
{
	int		fd;
	char	ch_buf[MAX_MAP_SIZE];
	t_map	map;

	ft_bzero(&ch_buf, MAX_MAP_SIZE);
	if((fd = open(file, O_RDONLY)) == -1)
		panic(-1);
	if((read(fd, &ch_buf, MAX_MAP_SIZE)) == -1)
		panic(-1);
	fuckthelines(ch_buf, &(game->map));	
}
