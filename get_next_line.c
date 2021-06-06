/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:20:58 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/06 19:50:47 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "header_proto.h"

int	err(void *a, void *b, void *c)
{
	free(a);
	free(b);
	free(c);
	return (-1);
}

int	get_next_line(char **line)
{
	char	*ret;
	char	*join;
	long	rd_ret;
	char	*tmp;

	if (!line || BUFFER_SIZE < 1)
		return (-1);
	ret = wrap_malloc(BUFFER_SIZE + 1);
	if (as(&rd_ret, read(STDIN_FILENO, ret, BUFFER_SIZE), 8) < 0)
		return (err(ret, NULL, NULL));
	ret[rd_ret] = '\0';
	while (rd_ret == BUFFER_SIZE && !ft_strchr(ret, '\n'))
	{
		if (!as(&join, (long)wrap_malloc(BUFFER_SIZE + 1), 8))
			return (err(ret, NULL, NULL));
		if (as(&rd_ret, (long)read(STDIN_FILENO, join, BUFFER_SIZE), 8) < 0)
			return (err(ret, join, NULL));
		join[rd_ret] = '\0';
		tmp = ret;
		if (!as(&ret, (long)ft_strjoin(ret, join), 8))
			return (err(tmp, join, NULL));
		err(tmp, join, NULL);
	}
	*line = ret;
	return (ft_strlen(ret));
}
