/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:03:16 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/06 20:21:49 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long	ft_abs(long x)
{
	if (x < 0)
		return (-x);
	return (x);
}

long	ft_min(long x, long y)
{
	if (x > y)
		return (y);
	return (x);
}

long	ft_max(long x, long y)
{
	if (x > y)
		return (x);
	return (y);
}

long	sign(long x)
{
	return (ft_abs(x) / (x + !x));
}

void	*as(void *a, long v, int size)
{
	if (size == 1)
		*((char *)a) = (char)v;
	else if (size == 2)
		*((short *)a) = (short)v;
	else if (size == 4)
		*((int *)a) = (int)v;
	else
		*((long *)a) = (long)v;
	return (a);
}
