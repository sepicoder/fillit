/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsefillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 12:05:12 by abchan            #+#    #+#             */
/*   Updated: 2018/04/04 15:36:15 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*turns a buffer to tetrimino*/
char	*separate_tetriminos(char *buf)
{
	int		i;
	char	*piece;

	piece = (char *)malloc(sizeof(char) * 21);
	i = 0;
	while (buf[i] && i < 20)
	{
		if (((i + 1) % 5 != 0 && buf[i] != '.' && buf[i] != '#')
				||	((i + 1) % 5 == 0 && buf[i] != '\n'))
		{
			free(piece);
			return (0);
		}
		piece[i] = buf[i];
		i++;
	}
	piece[i] = '\0';
	cleantet(piece);
	if (i == 20 && isvalid(piece))
		return (piece);
	free(piece);
	return (0);
}

char	*cleantet(char *tet)
{
	int		i;
	int		j;

	while (tet[0] == '.' && tet[5] == '.' &&
			tet[10] == '.' &&  tet[15] == '.')
	{
		j = 0;
		while (j < 3)
		{
			i = -1;
			while (++i < 4)
			{
				tet[j + (i * 5)] = tet[(j + 1) + (i * 5)];
				tet[(j + 1) + (i * 5)] = '.';
			}
			j++;
		}
		i = 0;
	}
	while (tet[0] == '.' && tet[1] == '.' &&
			tet[2] == '.' &&  tet[3] == '.')
	{
		i = 0;
		while (i < 3)
		{
			j = -1;
			while (++j < 4)
			{
				tet[(i * 5) + j] = tet[((i + 1) * 5) + j];
				tet[((i + 1) * 5) + j] = '.';
			}
			i++;
		}
		j = 0;
		while (j < 4)
			tet[15 + j++] = '.';
	}
	return (tet);
}
char	**readall(char *filename)
{
	int		file;
	char	**list;
	char	buf[BUFF_SIZE + 1];
	int		i;

	list = (char **)malloc(sizeof(char *) * (count_tetriminos(filename) + 1));
	file = open(filename, O_RDONLY);
	i = 0;
	while (read(file, buf, 21))
	{
		if ((list[i++] = separate_tetriminos(buf)) == 0)
		{
			free(list);
			return (0);
		}
	}
	list[i] = 0;
	close (file);
	return (list);
}
