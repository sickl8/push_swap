/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:42:15 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/06 20:05:12 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	stack_size(t_stk *stack)
{
	return (stack->length);
}

void	stack_node(int data, t_clt **ret)
{
	*ret = wrap_malloc(sizeof(**ret));
	(*ret)->data = data;
	(*ret)->next = *ret;
	(*ret)->prev = *ret;
}

void	stack_push_back(int data, t_stk *stack)
{
	t_clt	*node;

	stack_node(data, &node);
	if (!stack->anchor)
	{
		stack->anchor = node;
		stack->list = node;
	}
	else
	{
		node->next = stack->anchor;
		node->prev = stack->anchor->prev;
		stack->anchor->prev->next = node;
		stack->anchor->prev = node;
	}
	stack->length++;
}

void	stack_push_front(int data, t_stk *stack)
{
	stack_push_back(data, stack);
	stack->anchor = stack->anchor->prev;
}

t_clt	*stack_member_at(int index, t_stk *stack)
{
	t_stki	itr;

	init_stack_iterator(&itr, stack);
	while (!stack_iterator_end(&itr) && itr.index != index)
		stack_iterator_advance(&itr);
	return (itr.ptr);
}
