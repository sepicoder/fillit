/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:39:33 by shomami           #+#    #+#             */
/*   Updated: 2018/04/05 15:09:40 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This function gets the sqrt of the counted tetriminos * 4
*/

int		ft_sqrt(int size)
{
	int		num;

	num = 2;
	while (num * num < size)
		num++;
	return (num);
}

/*
** trying to the smallest possible size of the board and increase it
*/

int		board_init(int tetrinbr)
{
	int		size;

	size = ft_sqrt(tetrinbr * 4);
	return (size);
}

/*
** this generates and returns the map, null terminating it and filling
** it with '.' and '\n' where appropiate
*/

char	*generate_map(size_t current)
{
	char	*map;
	size_t	mapsize;
	size_t	i;
	size_t	j;

	mapsize = current * current + current + 1;
	if (!(map = (char *)malloc(sizeof(char) * (mapsize))))
		return (NULL);
	map[0] = '.';
	i = 1;
	j = 0;
	while (i < mapsize - 1)
	{
		if (i % ((j * (current + 1)) + current) != 0)
			map[i] = '.';
		if (i % ((j * (current + 1)) + current) == 0)
		{
			map[i] = '\n';
			j++;
		}
		i++;
	}
	map[mapsize] = '\0';
	return (map);
}

void	printmap(char *map)
{
	if (map == 0)
	{
		ft_putendl("error");
		return ;
	}
	else
		ft_putstr(map);
}
