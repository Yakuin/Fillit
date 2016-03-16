/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:46:54 by yboualla          #+#    #+#             */
/*   Updated: 2016/03/16 20:33:11 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			checktetr(t_tetr *tetr)
{
	int		liaison;
	int		i;
	int		cont;
	
	liaison = 0;
	i = -1;
	while (tetr->data[++i] != '\0')
		if (tetr->data[i] == '#')	
		{
			if (tetr->data[i + 1] == '#')
				cont = ++liaison;
			if ((i - 1) >= 0 && tetr->data[i - 1] == '#')
				cont = ++liaison;
			if ((i + 5) < 20 && tetr->data[i + 5] == '#')
				cont = ++liaison;
			if ((i - 5) >= 0 && tetr->data[i - 5] == '#')
				cont = ++liaison;
			if (cont == 0)
				return (0);
			cont = 0;
		}
	if (liaison != 8 && liaison != 6)
		return (0);
	return (1);
}

int			checkfile(char *file)
{
	int		i;
	int		nbtetr;
	int		line;
	int		c;

	i = 0;
	c = 0;
	line = 0;
	nbtetr = 0;
	while (file[i] != '\0')
	{
		if (c < 4)
		{
			if (file[i] == '.' || file[i] == '#')
				i++;
			else
				return (0);
			c++;
		}
		if (c == 4)
		{
			if (file[i] != '\n')
				return (0);
			c = 0;
			i++;
			line++;
		}
		if (line == 4)
		{
			nbtetr++;
			if (file[i] == '\0')
				return (nbtetr);
			else if (file[i] == '\n')
			{
				i++;
				line = 0;				
			}
			else
				return (0);
		}
	}
	return (0);
}

int			collision_check(t_tetr *tetr, char **map, int posx, int posy, int map_size)
{
	int		x;
	int		y;
	int		data;
	int		sharp;

	x = posx - 1;
	y = posy;
	sharp = 0;
	data = tetr->posx + (tetr->posy * 5);
	while (tetr->data[data] != '\0' && sharp < 4 && y < map_size)
	{
		++x;
		if (tetr->data[data] == '\n')
		{
			y++;
			x = posx;
			data += 1 + tetr->posx;
		}
		if (y == map_size || tetr->data[data] == '\0')
		{
			if (sharp == 4)
				return (0);
			else
				return (1);
		}
		if (tetr->data[data] == '#')
		{
			if (map[y][x] != '.')
				return (1);
			else
				++sharp;
		}
		++data;
	}
	if (sharp == 4)
		return (0);
	else
		return (1);
}
