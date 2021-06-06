/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:29:39 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/06 21:07:02 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*wrap_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
	{
		e_puts("Error\n");
		exit(1);
	}
	return (ret);
}

int	add_node(void *data, t_list **list)
{
	t_list	**tracer;

	tracer = list;
	while (*tracer)
		tracer = &(*tracer)->next;
	*tracer = wrap_malloc(sizeof(**tracer));
	(*tracer)->data = data;
	(*tracer)->next = NULL;
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	error(void)
{
	e_puts("Error\n");
	exit(1);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
