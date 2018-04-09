/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 21:40:02 by shomami           #+#    #+#             */
/*   Updated: 2018/04/05 16:44:52 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFF_SIZE 21

int		count_tetriminos(char *filename);
char	*separate_tetriminos(char *buf);
int		char_checker(char *input);
int		input_checker(char *str);
int		connection_checker(char *str);
char	**readall(char *filename);
char	*shiftup(char *tet);
char	*shiftleft(char *tet);
int		isvalid(char *num);
int		countpieces(char **list);
int		solvecentral(char **list, int tetrinbr);
char	*generate_map(size_t current);
void	printmap(char *map);
int		*intconversion(char *piece, int mapcounter);
int		board_init(int tetrinbr);
int		**convertit(char **list, int mapcounter, int tetrinbr);

#endif
