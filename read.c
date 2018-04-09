/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 23:30:45 by shomami           #+#    #+#             */
/*   Updated: 2018/04/06 11:08:37 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** this function checks to make sure each piece is valid
*/

int		isvalid(char *num)
{
	if (ft_strcmp(num, "##..\n##..\n....\n....\n") == 0 ||
			ft_strcmp(num, "####\n....\n....\n....\n") == 0 ||
			ft_strcmp(num, "#...\n#...\n#...\n#...\n") == 0)
		return (1);
	else if (ft_strcmp(num, ".#..\n##..\n#...\n....\n") == 0 ||
			ft_strcmp(num, ".##.\n##..\n....\n....\n") == 0 ||
			ft_strcmp(num, "#...\n##..\n.#..\n....\n") == 0 ||
			ft_strcmp(num, "##..\n.##.\n....\n....\n") == 0)
		return (1);
	else if (ft_strcmp(num, "#...\n##..\n#...\n....\n") == 0 ||
			ft_strcmp(num, "###.\n.#..\n....\n....\n") == 0 ||
			ft_strcmp(num, ".#..\n##..\n.#..\n....\n") == 0 ||
			ft_strcmp(num, ".#..\n###.\n....\n....\n") == 0)
		return (1);
	else if (ft_strcmp(num, "##..\n#...\n#...\n....\n") == 0 ||
			ft_strcmp(num, "###.\n..#.\n....\n....\n") == 0 ||
			ft_strcmp(num, ".#..\n.#..\n##..\n....\n") == 0 ||
			ft_strcmp(num, "#...\n###.\n....\n....\n") == 0)
		return (1);
	else if (ft_strcmp(num, "##..\n.#..\n.#..\n....\n") == 0 ||
			ft_strcmp(num, "..#.\n###.\n....\n....\n") == 0 ||
			ft_strcmp(num, "#...\n#...\n##..\n....\n") == 0 ||
			ft_strcmp(num, "###.\n#...\n....\n....\n") == 0)
		return (1);
	return (0);
}

int		countpieces(char **list)
{
	int		i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

int		count_tetriminos(char *filename)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		result;
	int		nread;

	fd = open(filename, O_RDONLY);
	result = 0;
	while ((nread = read(fd, buf, 21)) > 0)
		result++;
	if (nread < 0)
		return (-1);
	if (result > 26)
		return (0);
	return (result);
}

int		checkfilecharcount(char *filename)
{
	int		fd;
	char	buf[546];
	int		readit;
	int		i;

	fd = open(filename, O_RDONLY);
	readit = 1 + read(fd, buf, 546);
	if (readit % 21 != 0 || readit == 0)
		return (0);
	buf[readit] = '\0';
	i = 0;
	while (--readit >= 0)
	{
		if (buf[readit] == '#')
			i++;
		if (readit % 21 == 0 && i != 4)
			return (0);
		if (readit % 21 == 0 && i == 4)
			i = 0;
	}
	return (1);
}

char	**readall(char *filename)
{
	int		file;
	char	**list;
	char	buf[BUFF_SIZE + 1];
	int		i;
	int		nread;

	if (!checkfilecharcount(filename))
		return (NULL);
	list = (char **)malloc(sizeof(char *) * (count_tetriminos(filename) + 1));
	file = open(filename, O_RDONLY);
	i = 0;
	while ((nread = read(file, buf, 21)) > 0)
	{
		if ((list[i++] = separate_tetriminos(buf)) == 0)
		{
			free(list);
			return (0);
		}
	}
	if (nread < 0)
		return (NULL);
	list[i] = 0;
	close(file);
	return (list);
}
