/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsttetr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 09:23:25 by yboualla          #+#    #+#             */
/*   Updated: 2016/03/16 15:28:49 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	get_offset(t_tetr *tetr)
{
	int i;

	i = -1;
	while (tetr->data[++i] != '\0')
	{
		if (tetr->data[i] == '#')
		{
			if (i / 5 < tetr->posy)
				tetr->posy = i / 5;
			if (i % 5 < tetr->posx)
				tetr->posx = i % 5;
		}
	}
}

t_tetr		*create_lsttetr(char *tetr, int nb)
{
	t_tetr	*liste_tetr;

	liste_tetr = (t_tetr*)malloc(sizeof(t_tetr));
	if (!liste_tetr)
		return (NULL);
	liste_tetr->data = tetr;
	liste_tetr->letter = 'A' + nb;
	liste_tetr->posx = 5;
	liste_tetr->posy = 5;
	get_offset(liste_tetr);
	liste_tetr->next = NULL;
	if (!(checktetr(liste_tetr)))
		errmsg(0);
	return (liste_tetr);
}

void		add_lsttetr(t_tetr *liste_tetr, char *tetr)
{
	int		i;
	t_tetr	*cursor;

	i = 1;
	if (tetr && liste_tetr)
	{
		cursor = liste_tetr;
		while (cursor->next)
		{
			++i;
			cursor = cursor->next;
		}
		cursor->next = create_lsttetr(tetr, i);
	}
}
