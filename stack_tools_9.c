/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_9.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:15:27 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/06 20:15:49 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	sa(t_inf i, int *len, t_cell cell, int	*inc)
{
	int		qm;

	(void)cell;
	qm = (i.li == -1 || i.li > SS) && len[A] > 1;
	(*inc) += qm;
	return (qm);
}

int	sb(t_inf i, int *len, t_cell cell, int	*inc)
{
	int		qm;

	(void)cell;
	qm = (i.li == -1 || i.li > SS) && len[B] > 1;
	(*inc) += qm;
	return (qm);
}

int	ss(t_inf i, int *len, t_cell cell, int	*inc)
{
	int		qm;

	(void)cell;
	qm = (i.li == -1 || i.li > SS) && len[B] > 1 && len[A] > 1;
	(*inc) += qm;
	return (qm);
}

int	pb(t_inf i, int *len, t_cell cell, int	*inc)
{
	int		qm;

	(void)cell;
	qm = (i.li == -1 || i.li != PB) && len[A] && i.sl - i.ip - 1 > len[B] + 1;
	(*inc) += qm;
	return (qm);
}

int	ra(t_inf i, int *len, t_cell cell, int	*inc)
{
	int		qm;

	(void)cell;
	qm = (i.li == -1 || (i.li != RRA && i.li != RRR))
		&& len[A] > 1 && cell.ro.cra < len[A] / 2;
	(*inc) += qm;
	return (qm);
}
