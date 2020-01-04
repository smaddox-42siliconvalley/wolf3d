/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 07:11:00 by smaddox           #+#    #+#             */
/*   Updated: 2020/01/04 13:18:53 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void	fuckthelines(char *ch_buf, t_map *map)
{
	int i;
	int j;

	i = -1;
	j = 0;
	map->size_line = ft_strclen(ch_buf, '\n');
	while (ch_buf[++i] && (i < MAX_MAP_SIZE))
	{
		if (ch_buf[i] != '0' && ch_buf[i] != '\n' && ch_buf[i] != '1')
			panic(898);
		if (ch_buf[i] != '\n')
		{
			map->map[j] = (ch_buf[i] - '0');
			j++;
		}
	}
	map->size = j;
}

void		get_map(char *file, t_game *game)
{
	int		fd;
	char	ch_buf[MAX_MAP_SIZE];

	ft_bzero(&ch_buf, MAX_MAP_SIZE);
	if ((fd = open(file, O_RDONLY)) == -1)
		panic(-1);
	if ((read(fd, &ch_buf, MAX_MAP_SIZE)) == -1)
		panic(-1);
	fuckthelines(ch_buf, &(game->map));
}
