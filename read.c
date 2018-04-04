/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 23:30:45 by shomami           #+#    #+#             */
/*   Updated: 2018/04/02 21:05:46 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//read the connection to make sure the tetrimino is valid
/*
int valid_tetrimino(char *str)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if


		}
	}
}
*/

/*
int char_checker(char *input)
{
	while (*input)
	{
		if(*input != '#' || *input != '.' || *input != '\n')
			return(0);
	input++;
	}
	return (1);
}

int input_checker(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(i < 21)
			return(1);
		else
		ft_putstr("ERROR\n");
	}
	i++;
	return (0);
}

int connection_checker(char *str)
{
	int con;
	int i;

	i = 0;
	con = 0;
	while (str[i])
	{
		while (i < 20)
		{
			if (i != 0)
			{
			if(i + 1 < 21 && str[i + 1] == '#')
			con++;
			if(i - 1 >= 0 && str[i - 1] == '#')
			con++;
			if((i + 5 < 21) && (str[i + 5] == '#'))
			con++;
			if((i - 5 >= 0) && (str[i - 5] == '#'))
			con++;
		}
		i++;
	}
	return (1);
	}
	return (con == 6 || con == 8) ? (1) : (0);
}
*/

//counting the #of tetriminos

int                    isvalid(char *num)
{
    if (ft_strcmp(num, "##..\n##..\n....\n....\n") == 0 ||
        ft_strcmp(num, "####\n....\n....\n....\n") == 0 ||
        ft_strcmp(num, "#...\n#...\n#...\n#...\n") == 0)
        return (1);
    else if (ft_strcmp(num, ".#..\n##..\n#...\n....\n") == 0||
        ft_strcmp(num, ".##.\n##..\n....\n....\n") == 0||
        ft_strcmp(num, "#...\n##..\n.#..\n....\n") == 0||
        ft_strcmp(num, "##..\n.##.\n....\n....\n") == 0)
        return (1);
    else if (ft_strcmp(num, "#...\n##..\n#...\n....\n") == 0||
        ft_strcmp(num, "###.\n.#..\n....\n....\n") == 0||
        ft_strcmp(num, ".#..\n##..\n.#..\n....\n") == 0||
        ft_strcmp(num, ".#..\n###.\n....\n....\n") == 0)
        return (1);
    else if (ft_strcmp(num, "##..\n#...\n#...\n....\n") == 0||
        ft_strcmp(num, "###.\n#...\n....\n....\n") == 0||
        ft_strcmp(num, ".#..\n.#..\n##..\n....\n") == 0||
        ft_strcmp(num, "#...\n###.\n....\n....\n") == 0)
        return (1);
	else if (ft_strcmp(num, "##..\n.#..\n.#..\n....\n") == 0||
        ft_strcmp(num, "..#.\n###.\n....\n....\n") == 0||
        ft_strcmp(num, "#...\n#...\n##..\n....\n") == 0||
        ft_strcmp(num, "###.\n#...\n....\n....\n") == 0)
        return (1);
    return (0);
}

int countpieces(char **list)
{
	int i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

int count_tetriminos(char *filename)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		result;

	fd = open(filename, O_RDONLY);
	result = 0;
	while (read(fd, buf, 21))
		result++;
	return (result);
}
