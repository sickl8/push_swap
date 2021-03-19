/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:13:47 by sickl8            #+#    #+#             */
/*   Updated: 2021/03/18 22:28:25 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** How this algorithm works is, it pushes either the smallest or the biggest
** member of the A stack to B, and rotates the B stack respectively, so that
** at the end of this process, you get a sorted B stack with an anchor that
** is off, which we can simply fix by rotating it until it the anchor is
** correct, and then we start pushing the members back to the A stack.
*/

void	continue_algo_0(t_stk *a_stack, t_stk *b_stack, t_list **ret)
{
	while (b_stack->length)
	{
		stack_push_from_b_to_a(a_stack, b_stack);
		add_node((void*)PA, ret);
	}
}

t_list	*algo_0(t_stk *a_stack, t_stk *b_stack)
{
	t_list	*ret;
	int		smallest;
	int		biggest;
	int		reached;

	ret = NULL;
	while (a_stack->length)
	{
		smallest = smallest_member(a_stack)->data;
		biggest = biggest_member(a_stack)->data;
		reached =
		stack_reach_closest_member(smallest, biggest, a_stack, &ret);	
		stack_push_from_a_to_b(a_stack, b_stack);
		add_node((void*)PB, &ret);
		if (reached == biggest && stack_size(b_stack) > 1)
		{
			stack_rotate(b_stack);
			add_node((void*)RB, &ret);
		}
	}
	biggest = biggest_member(b_stack)->data;
	stack_reach_member(biggest, B, b_stack, &ret);
	continue_algo_0(a_stack, b_stack, &ret);
	return (ret);
}