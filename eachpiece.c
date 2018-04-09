/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eachpiece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:46:39 by abchan            #+#    #+#             */
/*   Updated: 2018/04/05 15:17:54 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** this function calculates the positional [index] of each '#' relative to the
** size of the map
*/

int		positioncalc(int piecepos, int mapcounter)
{
	if (piecepos / 5 == 0)
		return (piecepos);
	if (piecepos / 5 > 0)
		return ((mapcounter + 1) * (piecepos / 5) + (piecepos % 5));
	return (0);
}

/*
** this function takes in the tetri pieces as a char string
** and puts into an int string their positional [index]
*/

int		*intconversion(char *piece, int mapcounter)
{
	int	i;
	int	counter;
	int	*positions;

	positions = (int *)malloc(sizeof(int) * 5);
	if (!positions)
		return (0);
	i = 0;
	counter = 0;
	while (piece[i] != '\0' && counter < 4)
	{
		if (piece[i] == '#')
		{
			positions[counter] = positioncalc(i, mapcounter);
			counter++;
		}
		i++;
	}
	positions[counter] = '\0';
	return (positions);
}

/*
** this function allocates memory for a 2D int array, which contains
** the positional [index]ies of each of the '#' in each of the tetri piece
*/

int		**convertit(char **list, int mapcounter, int tetrinbr)
{
	int	**tetripos;
	int	i;

	i = 0;
	if (!(tetripos = (int **)malloc(sizeof(int *) * tetrinbr + 1)))
		return (0);
	i = -1;
	while (i++ < tetrinbr - 1)
		if ((tetripos[i] = intconversion(list[i], mapcounter)) == 0)
		{
			free(tetripos);
			return (0);
		}
	tetripos[tetrinbr] = 0;
	return (tetripos);
}
