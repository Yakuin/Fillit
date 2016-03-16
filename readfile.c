/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:10:23 by yboualla          #+#    #+#             */
/*   Updated: 2016/03/16 19:51:12 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			openfile(char *path)
{
	int		file;

	file = open(path, O_RDONLY);
	if (file == -1)
		errmsg(0);
	return (file);
}

char		*readfile(char *path)
{
	char	buffer[BUFF_SIZE + 1];
	int		ret;
	char	*str;
	int		fd;

	fd = openfile(path);
	str = (char*)ft_memalloc(sizeof(char));
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (ret == -1)
			return (0);
		buffer[ret] = '\0';
		str = ft_strjoin(str, buffer);
	}
	close(fd);
	return (str);
}
