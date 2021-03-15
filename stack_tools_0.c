/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sickl8 <sickl8@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:59:24 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/14 23:17:49 by sickl8           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	init_stack(t_stk *stack)
{
	stack->anchor = NULL;
	stack->list = NULL;
	stack->length = 0;
	return (1);
}

t_stki	init_stack_iterator(t_stki *itr, t_stk *stack)
{
	itr->index = 0;
	itr->ptr = stack->anchor;
	itr->stk = stack;
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
