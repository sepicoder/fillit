/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:06:02 by shomami           #+#    #+#             */
/*   Updated: 2018/04/06 10:37:55 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

int		main(int argc, char **argv)
{
	char **list;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if ((list = readall(argv[1])) == 0)
	{
		ft_putendl("error");
		return (-1);
	}
	solvecentral(list, countpieces(list));
	return (0);
}
