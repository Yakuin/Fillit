/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <yboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:29:29 by yboualla          #+#    #+#             */
/*   Updated: 2016/03/16 20:28:28 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		errmsg(int err)
{
	if (err == 1)
	{
		ft_putstr("error");
		exit(EXIT_SUCCESS);
	}
	else if (err == 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr("error");
		exit(EXIT_FAILURE);
	}
}

static int	delete_tetr(t_tetr *tetr, char **map, int posx, int posy, int map_size)
{
	int 	i;
	int 	j;

	i = posx + (posy * map_size);
	j = tetr->posx + (tetr->posy * 5);
	while (tetr->data[j] != '\0' && i < map_size * map_size)
	{
		if (tetr->data[j] == '#')
			map[(i / map_size)]
				[(i % map_size)] = '.';
		if (tetr->data[j] == '\n')
			i += map_size - 5;
		i++;
		j++;
	}
	return (1);
}

int		recursive_solver(char **map, t_tetr *tetr, int map_size)
{
	int x;
	int y;

	if (tetr == NULL)
	{
		printmap(map, map_size);
		exit(1);
	}
	y = -1;
	while (++y < map_size)
	{
		x = -1;
		while (++x < map_size)
		{
			if (addtomap(tetr, map, x, y, map_size))
			{
				recursive_solver(map, tetr->next, map_size);
				delete_tetr(tetr, map, x, y, map_size);
			}
		}
	}
	return (0);
}

static int	square_root(int n_tetri)
{
	if (n_tetri == 1)
		return (2);
	if (n_tetri == 2)
		return (3);
	if (n_tetri >= 3 && n_tetri <= 4)
		return (4);
	if (n_tetri >= 5 && n_tetri <= 6)
		return (5);
	if (n_tetri >= 7 && n_tetri <= 9)
		return (6);
	if (n_tetri >= 10 && n_tetri <= 12)
		return (7);
	if (n_tetri >= 13 && n_tetri <= 16)
		return (8);
	if (n_tetri >= 17 && n_tetri <= 20)
		return (9);
	if (n_tetri >= 21 && n_tetri <= 25)
		return (10);
	if (n_tetri == 26)
		return (11);
	return (0);
}

int			main(int argc, char **argv)
{
	int		nbtetr;
	char	*file;
	t_tetr 	*liste_tetr;
	int		map_size;
	char	**tetr;
	int		i;

	if (argc != 2)
		errmsg(2);
	file = readfile(argv[1]);
	nbtetr = checkfile(file);
	if (nbtetr == 0 || nbtetr > 26)
		errmsg(0);
	square_root(nbtetr);
	map_size = 2;
	tetr = save_tetr(nbtetr, file);
	i = -1;
	while (++i < nbtetr)
		if (i == 0)
			liste_tetr = create_lsttetr(tetr[i], 0);
		else
			add_lsttetr(liste_tetr, tetr[i]);
	while (++map_size)
		recursive_solver(create_map(map_size), liste_tetr, map_size);
	return (0);
}
