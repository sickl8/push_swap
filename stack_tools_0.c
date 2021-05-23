/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:59:24 by isaadi            #+#    #+#             */
/*   Updated: 2021/05/23 15:54:20 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	init_stack(t_stk *stack)
{
	stack->anchor = NULL;
	stack->list = NULL;
	stack->length = 0;
	stack->tab[SA] = swap_a;
	stack->tab[SB] = swap_b;
	stack->tab[SS] = swap_s;
	stack->tab[PA] = push_a;
	stack->tab[PB] = push_b;
	stack->tab[RA] = rotate_a;
	stack->tab[RB] = rotate_b;
	stack->tab[RR] = rotate_r;
	stack->tab[RRA] = rrotate_a;
	stack->tab[RRB] = rrotate_b;
	stack->tab[RRR] = rrotate_r;
	return (1);
}

t_stki	init_stack_iterator(t_stki *itr, t_stk *stack)
{
	itr->index = 0;
	itr->ptr = stack->anchor;
	itr->stk = stack;
	itr->data = 0;
	if (itr->ptr)
		itr->data = itr->ptr->data;
	return (*itr);
}

int	stack_iterator_end(t_stki *itr)
{
	if (itr->index < itr->stk->length)
		return (0);
	return (1);
}

int stack_iterator_advance(t_stki *itr)
{
	if (itr->ptr)
	{
		itr->ptr = itr->ptr->next;
		itr->data = itr->ptr->data;
		itr->index++;
	}
	return (0);
}

t_clt	*stack_member(int needle, t_stk *stack)
{
	t_stki	itr;

	init_stack_iterator(&itr, stack);
	while (!stack_iterator_end(&itr))
	{
		if (itr.ptr->data == needle)
			return (itr.ptr);
		stack_iterator_advance(&itr);
	}
	return (NULL);
}
