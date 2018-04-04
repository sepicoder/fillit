 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:12:17 by abchan            #+#    #+#             */
/*   Updated: 2018/04/03 14:49:32 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		positioncalc(char *tetri, int mappos, int hashnbr, int mapcounter)
{
	//this function is to calculate the position of the hash in its own array and convert
	// it to the index of the map array.
	//it should return the position of the hash in the map
	int piecepos;
	int i;
	
	piecepos = -1;
	i = 0;
	while (i < hashnbr + 1)
	{
		piecepos++;
		if (tetri[piecepos] == '#')
			i++;
	}
	if (piecepos / 5 == 0) //this checks if the hash is on the top line of where its saved. If so, it's position on the map should be simply additive 
		return (mappos + piecepos);
	if (piecepos / 5 > 0)
		return (mappos + ((mapcounter + 1) * (piecepos / 5)) + (piecepos % 5));
	return (0);

}

int		checkfit(char *tetri, char *map, int mappos, int mapcounter)
{
	// this function checks to see if the piece fits here. it will maybe use position calc to
	// see the piece's position on the map, and see if it's only '.'
	int nbrchecked;
	
	nbrchecked = 0;
	while (nbrchecked < 4)
	{
		if (map[positioncalc(tetri, mappos, nbrchecked, mapcounter)] != '.')
			return (0);
		nbrchecked++;
	}
	return (1);
}

char	*placepiece(char *tetri, int piececount, char *map, int mappos, int mapcounter)
{
	int	nbrplaced;
	
	nbrplaced = 0;
	if (checkfit(tetri, map, mappos, mapcounter))
	{
		while (nbrplaced < 4)
		{
			map[positioncalc(tetri, mappos, nbrplaced, mapcounter)] = piececount + 'A';
			nbrplaced++;
		}
		return (map);
	}
	return (0);
}

//This function gets the sqrt of the counted tetriminos * 4
//maybe put this in map.c?
int		ft_sqrt(int size)
{
	int num;

	num = 2;
	while (num * num < size)
		num++;
	return (num);
}

// trying to the smallest possible size of the board and increase it
//maybe put this in the map.c?
int board_init(int tetrinbr)
{
	int size;

	size = ft_sqrt(tetrinbr * 4);
	return (size);
}

size_t		clearlastpiece(int lastpiece, char *map)
{
	size_t i;
	size_t pos;

	i = 0;
	while (map[i] != 'A' + lastpiece)
		i++;
	pos = i;
	while (map[i] != '\0')
	{
		if (map[i] == 'A' + lastpiece)
			map[i] = '.';
		i++;
	}
	return (pos + 1);
}


char	*solveit(char *map, char **list, int mapcounter, int tetrinbr, int currentpiece, size_t mappos)
{
	//this is where we will be doing the recursive backtracking
	while (currentpiece < tetrinbr && mappos < ft_strlen(map)) //thebacktrack thing should be placed somewhere inside of this loop or something
	{
		if (!(placepiece(list[currentpiece], currentpiece, map, mappos, mapcounter)))
			mappos++;
		else
		{
			currentpiece++;
			mappos = 0;
		}
	}
	if (currentpiece == 0 && mappos > strlen(map) - 4)
		return (0);
	if (map[mappos] == '\0' && currentpiece < tetrinbr)
	{
		if (currentpiece == 0 && !(solveit(map, list, mapcounter, tetrinbr, currentpiece, clearlastpiece(currentpiece - 1, map))))
			return (0);
		if (currentpiece > 0 && !(solveit(map, list, mapcounter, tetrinbr, currentpiece - 1, clearlastpiece(currentpiece - 1, map))))
			return (0);
	}
	return (map);
}



int		solvecentral(char **list, int tetrinbr)
{
	size_t mapcounter;
	char *map;
	mapcounter = board_init(tetrinbr);
	//squareroot thing for min square goes here
	map = generate_map(mapcounter);
	while (solveit(map, list, mapcounter, tetrinbr, 0, 0) == 0)
	{
		free(map);
		mapcounter++;
		map = generate_map(mapcounter);
	}
	//ft_putstr(map);
	printmap(map);
	return (0);
}
