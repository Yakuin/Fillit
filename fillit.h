/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <yboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:08:49 by yboualla          #+#    #+#             */
/*   Updated: 2016/03/16 20:03:39 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include	"libft/libft.h"
# include	"fcntl.h"
# define	BUFF_SIZE 20

typedef struct 		s_tetr
{
	char			*data;
	char			letter;	
	int				posx;
	int				posy;
	struct	s_tetr	*next;
}					t_tetr;

//readfile.c
char				*readfile(char *path);

//checks.c
int					checkfile(char *file); // TODO a normer/optimiser
int					checktetr(t_tetr *tetr); // TODO algo check tout nul, a optimiser/normer
int					collision_check(t_tetr *tetr, char **map, int posx, int posy, int map_size);

//save_tetr.c
char				**save_tetr(int nb_tetr, char *file);

//lsttetr.c
t_tetr				*create_lsttetr(char *tetr, int nb);
void				add_lsttetr(t_tetr *liste_tetr, char *tetr);
void				free_lsttetr(t_tetr *liste_tetr); // TODO (osef, on verra quand ca marchera)

//map.c
void				free_tmpmap(char **map); // TODO (osef pour le moment, pareil que plus haut)
void				init_map(char **map, int map_size);
char				**create_map(int map_size);
int					addtomap(t_tetr *tetr, char **map, int posx, int posy, int map_size);
void				printmap(char **map, int map_size);

//fillit.c
void				errmsg(int err);
int					recursive_solver(char **map, t_tetr *tetr, int map_size);

#endif
