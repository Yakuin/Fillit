/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_tetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:22:40 by aputman           #+#    #+#             */
/*   Updated: 2016/03/16 15:52:49 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char static	**split_tetr(char *cp, int nb_tetr, int read_tetr)
{
	char	**tetr_clear;
	int		split;
	int		i;
	int		j;

	i = 0;
	split = BUFF_SIZE;
	tetr_clear = (char **)malloc(sizeof(char *) * (nb_tetr));
	while (read_tetr < nb_tetr)
	{
		j = 0;
		tetr_clear[read_tetr] = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
		while (i < split)
			tetr_clear[read_tetr][j++] = cp[i++];
		tetr_clear[read_tetr++][j] = '\0';
		i += 1;
		split = i + BUFF_SIZE;
	}
	return (tetr_clear);
}

char		**save_tetr(int nb_tetr, char *file)
{
	char	**tetriminos;
	int		read_tetr;

	read_tetr = 0;
	tetriminos = split_tetr(file, nb_tetr, read_tetr);
	return (tetriminos);
}
