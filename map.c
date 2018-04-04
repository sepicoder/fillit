/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:39:33 by shomami           #+#    #+#             */
/*   Updated: 2018/04/03 14:51:21 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*generate_map(size_t current)
{
	char *map;
	size_t mapsize;
	size_t i;
	size_t j;

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

void printmap(char *map)
{
	if (map == 0)
	{
		ft_putendl("error");
		return;
	}
	else
		ft_putstr(map);
}
