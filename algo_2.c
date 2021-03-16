/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:28:33 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/16 15:50:46 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		pivot_member(t_stk *stack)
{
	int		len;
	int		rm;

	stack = stack_duplicate(stack);
	len = stack_size(stack_size);
	len /= 2;
	while (len > 0)
	{
		rm = smallest_member(stack);
		stack_erase(stack_member(rm, stack), stack);
		len--;
	}
	return (smallest_member(stack));
}

t_list	*algo_2(t_stk *a_stack, t_stk *b_stack)
{
	t_list	*ret;
	int		mid;

	ret = NULL;
	mid = pivot_member(a_stack);
	stack_reach_member(mid, A, a_stack, &ret);
	stack_push_from_a_to_b(a_stack, b_stack);
	add_node((void*)PB, &ret);
	while (a_stack->length)
	{
		if (a_stack->anchor->data > mid)
		{
			
		}
	}
	return (ret);
}