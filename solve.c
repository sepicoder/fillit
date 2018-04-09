/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:12:17 by abchan            #+#    #+#             */
/*   Updated: 2018/04/05 15:03:05 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** placepiece places the piece
*/

char		*placepiece(int *piecepos, int piececount, char *map, int mappos)
{
	if (map[piecepos[0] + mappos] == '.' &&
		map[piecepos[1] + mappos] == '.' &&
		map[piecepos[2] + mappos] == '.' &&
		map[piecepos[3] + mappos] == '.')
	{
		map[piecepos[0] + mappos] = 'A' + piececount;
		map[piecepos[1] + mappos] = 'A' + piececount;
		map[piecepos[2] + mappos] = 'A' + piececount;
		map[piecepos[3] + mappos] = 'A' + piececount;
		return (map);
	}
	return (0);
}

/*
** deletes the piece and returns the position of its top left corner
** pos = pos - tetripos[lastpiece][0] gives that position
*/

size_t		clearlastpiece(int lastpiece, int **tetripos, char *map)
{
	size_t	pos;

	pos = 0;
	while (map[pos] != 'A' + lastpiece)
		pos++;
	pos = pos - tetripos[lastpiece][0];
	map[tetripos[lastpiece][0] + pos] = '.';
	map[tetripos[lastpiece][1] + pos] = '.';
	map[tetripos[lastpiece][2] + pos] = '.';
	map[tetripos[lastpiece][3] + pos] = '.';
	return (pos);
}

/*
** recursion to solve
*/

int			solveit(char *map, int **tetripos, int tetrinbr, int currentpiece)
{
	size_t	mappos;

	mappos = 0;
	if (currentpiece == tetrinbr)
		return (1);
	while (map[mappos] != '\0')
	{
		if (placepiece(tetripos[currentpiece], currentpiece, map, mappos))
		{
			if (solveit(map, tetripos, tetrinbr, currentpiece + 1))
				return (1);
			clearlastpiece(currentpiece, tetripos, map);
		}
		mappos++;
	}
	return (0);
}

/*
** central station for where the solve happens
** if solve fails, the size of the map increments here
*/

int			solvecentral(char **list, int tetrinbr)
{
	size_t	mapcounter;
	char	*map;
	int		**tetripos;

	mapcounter = board_init(tetrinbr);
	map = generate_map(mapcounter);
	tetripos = convertit(list, mapcounter, tetrinbr);
	while (solveit(map, tetripos, tetrinbr, 0) == 0)
	{
		free(map);
		mapcounter++;
		free(tetripos);
		tetripos = convertit(list, mapcounter, tetrinbr);
		map = generate_map(mapcounter);
	}
	printmap(map);
	return (0);
}
