/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:16:55 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/06 20:07:26 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	rb(t_inf i, int *len, t_cell cell, int	*inc)
{
	int		qm;

	(void)cell;
	qm = (i.li == -1 || (i.li != RRB && i.li != RRR))
		&& len[B] > 1 && cell.ro.crb < len[B] / 2;
	(*inc) += qm;
	return (qm);
}

int	rr(t_inf i, int *len, t_cell cell, int	*inc)
{
	int		qm;

	(void)cell;
	qm = (i.li == -1 || i.li < RRA) && len[A] > 1
		&& cell.ro.cra < len[A] / 2 && len[B] > 1 && cell.ro.crb < len[B] / 2;
	(*inc) += qm;
	return (qm);
}

int	rra(t_inf i, int *len, t_cell cell, int	*inc)
{
	int		qm;

	(void)cell;
	qm = (i.li == -1 || (i.li != RA && i.li != RR))
		&& len[A] > 1 && cell.ro.crra < len[A] / 2;
	(*inc) += qm;
	return (qm);
}

int	rrb(t_inf i, int *len, t_cell cell, int	*inc)
{
	int		qm;

	(void)cell;
	qm = (i.li == -1 || (i.li != RB && i.li != RR))
		&& len[B] > 1 && cell.ro.crrb < len[B] / 2;
	(*inc) += qm;
	return (qm);
}

int	rrr(t_inf i, int *len, t_cell cell, int	*inc)
{
	int		qm;

	(void)cell;
	qm = (i.li == -1 || (i.li > RR && i.li < RA))
		&& len[A] > 1 && cell.ro.crra < len[A] / 2 && len[B] > 1
		&&cell.ro.crrb < len[B] / 2;
	(*inc) += qm;
	return (qm);
}
