/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:06:02 by shomami           #+#    #+#             */
/*   Updated: 2018/04/04 15:12:57 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

int	main(int argc, char **argv)
{
	char **list;
	/*if (argc != 2)
	{
		write(1, "usage\n", 6);
		return (0);
	}
	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{

		write(1, "ERROR\n", 6);
		//ft_putstr("error");
		return (0);
	}
	i = 0;
	ret = read(fd, buf, BUFF_SIZE);
	if ((ret + 1) % 21 != 0)
	{
		ft_putstr("ERRORj");
		return(0);
	}
	seperate_tetriminos(buf, ret + 1, (ret + 1) / 21);
	//ft_putnbr(ft_strlen(buf) + 1);
	if (ret > 546)
	{
		write(1, "\n!\n", 3);
		return (0);
	}
	else if (input_checker(buf) == 0)
	write (1, "ERROR1\n", 7);
	else if (char_checker(buf) == 0)
	write (1, "ERROR2\n", 7);*/
	if (argc == 2)
	{
		if ((list = readall(argv[1])) == 0)
		{
			ft_putendl("error");
			return (-1);
		}
		solvecentral(list, countpieces(list));
	}
	return (0);
}
