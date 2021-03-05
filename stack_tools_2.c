/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:05:43 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/05 14:40:18 by isaadi           ###   ########.fr       */
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

void	stack_swap(t_stk *stack)
{
	if (!stack->anchor)
		return ;
	stack->anchor->data = stack->anchor->data ^ stack->anchor->next->data;
	stack->anchor->next->data = stack->anchor->data ^ stack->anchor->next->data;
	stack->anchor->data = stack->anchor->data ^ stack->anchor->next->data;
}

void	rotate_stack(t_stk *stack)
{
	if (!stack->anchor)
		return ;
	stack->anchor = stack->anchor->next;
}

void	reverse_rotate_stack(t_stk *stack)
{
	if (!stack->anchor)
		return ;
	stack->anchor = stack->anchor->prev;
}

void	stack_push_from_to(t_stk *a_stack, t_stk *b_stack)
{
	if (!a_stack->anchor)
		return ;
	stack_push_front(a_stack->anchor->data, b_stack);
	stack_erase(a_stack->anchor, a_stack);
}