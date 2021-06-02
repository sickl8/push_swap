/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:03:16 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/02 19:19:41 by isaadi           ###   ########.fr       */
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