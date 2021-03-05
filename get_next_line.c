/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:20:58 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/04 19:23:34 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		err(void *a, void *b, void *c)
{
	free(a);
	free(b);
	free(c);
	return (-1);
}

int		get_next_line(char **line)
{
	char	*ret;
	char	*join;
	long	rd_ret;
	char	*tmp;

	if (!line || BUFFER_SIZE < 1 || !(ret = wrap_malloc(BUFFER_SIZE + 1)))
		return (-1);
	if ((rd_ret = read(STDIN_FILENO, ret, BUFFER_SIZE)) < 0)
		return (err(ret, NULL, NULL));
	ret[rd_ret] = '\0';
	while (rd_ret == BUFFER_SIZE)
	{
		if (!(join = wrap_malloc(BUFFER_SIZE + 1)))
			return (err(ret, NULL, NULL));
		if ((rd_ret = read(STDIN_FILENO, join, BUFFER_SIZE)) < 0)
			return (err(ret, join, NULL));
		join[rd_ret] = '\0';
		tmp = ret;
		if (!(ret = ft_strjoin(ret, join)))
			return (err(tmp, join, NULL));
		err(tmp, join, NULL);
	}
	*line = ret;
	return (ft_strlen(ret));
}