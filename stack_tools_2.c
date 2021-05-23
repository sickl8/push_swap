/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:05:43 by isaadi            #+#    #+#             */
/*   Updated: 2021/05/23 17:48:54 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	stack_erase(t_clt *member, t_stk *stack)
{
	if (!stack->anchor)
		return ;
	if (stack->anchor->next == stack->anchor)
		init_stack(stack);
	else
	{
		if (member == stack->anchor)
			stack->anchor = stack->anchor->next;
		(member->next)->prev = member->prev;
		(member->prev)->next = member->next;
		stack->length--;
	}
	free(member);
}

int		stack_swap(t_stk *stack)
{
	if (!stack->anchor)
		return (1);
	stack->anchor->data = stack->anchor->data ^ stack->anchor->next->data;
	stack->anchor->next->data = stack->anchor->data ^ stack->anchor->next->data;
	stack->anchor->data = stack->anchor->data ^ stack->anchor->next->data;
	return (1);
}

void	stack_rotate(t_stk *stack)
{
	if (!stack->anchor)
		return ;
	stack->anchor = stack->anchor->next;
}

void	stack_reverse_rotate(t_stk *stack)
{
	if (!stack->anchor)
		return ;
	stack->anchor = stack->anchor->prev;
}

void	stack_push_from_to(t_stk *a_stack, t_stk *b_stack)
{
	t_clt	*node;
	if (!a_stack->anchor)
		return ;
	// stack_push_front(a_stack->anchor->data, b_stack);
	// stack_erase(a_stack->anchor, a_stack);
	node = a_stack->anchor;
	a_stack->length--;
	b_stack->length++;
	if (a_stack->length)
	{
		a_stack->anchor->next->prev = a_stack->anchor->prev;
		a_stack->anchor->prev->next = a_stack->anchor->next;
	}
	else
	{
		a_stack->anchor = NULL;
		a_stack->list = NULL;
	}
	if (b_stack->length == 1)
	{
		node->next = node;
		node->prev = node;
		b_stack->anchor = node;
		b_stack->list = node;
	}
	else
	{
		node->next = b_stack->anchor;
		node->prev = b_stack->anchor->prev;
		b_stack->anchor->prev->next = node;
		b_stack->anchor->prev = node;
		b_stack->anchor = node;
	}
}