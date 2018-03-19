/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:06:02 by shomami           #+#    #+#             */
/*   Updated: 2018/03/18 21:46:44 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BUFF_SIZE 4096
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[BUFF_SIZE + 1];
	char *filename;

	if (argc != 2)
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
	ret = read(fd, buf, BUFF_SIZE);
		write(1, buf, strlen(buf));
	if (ret > 546)
	{
		write(1, "\n!\n", 3);
		return (0);
	}
}
