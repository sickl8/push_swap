/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_12.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:03:23 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/06 21:20:07 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	apply_inst_lst(t_stk *a_stack, t_stk *b_stack, int *inst, int len)
{
	int		i;

	a_stack = stack_duplicate(a_stack);
	b_stack = stack_duplicate(b_stack);
	i = -1;
	while (++i < len)
		apply_inst(a_stack, b_stack, inst[i]);
	i = !b_stack->length && stack_is_sorted(a_stack);
	stack_destroy(a_stack, TRUE);
	stack_destroy(b_stack, TRUE);
	return (i);
}

void	swap_a(t_stk **stacks)
{
	stack_swap(stacks[A]);
}

void	swap_b(t_stk **stacks)
{
	stack_swap(stacks[B]);
}

void	swap_s(t_stk **stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}

void	push_a(t_stk **stacks)
{
	stack_push_from_b_to_a(stacks[A], stacks[B]);
}
