/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eachpiece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:46:39 by abchan            #+#    #+#             */
/*   Updated: 2018/04/02 12:53:30 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

char	lengtheight(char *tetripiece)
{

}

char	lengthseven(char *tetripiece)
{

}
char	identifypiece(char *tetripiece)
{
	if (ft_strlen(tetripiece) == 5)
		return ('a');
	if (ft_strlen(tetripiece) == 6)
	{
		if (tetripiece[1] != '#')
			return ('b');
		if (tetripiece[2] == '#')
			return ('c');
		else 
			return ('d');
	}
	if (ft_strlen(tetripiece) == 7)
		return (lengthseven(tetripiece));
	if (ft_strlen(tetripiece) == 8)
		return (lengtheight(tetripiece));
	if (ft_strlen(tetripiece) == 9)
	{
		if (tetripiece[0] == '#')
			return ('q');
		if (tetripiece[3] == '#')
			return ('r');
		else
			return ('s');
	}
	return (0);
}

char	*each_piece(char **tetripieces, int piececount)
{
	int i;
	char *identified;

	identified = ft_strnew(piececount);
	i = -1;
	while (++i < piececount)
		identified[i] = identifypiece(tetripieces[i]);
	return (identified);
}
