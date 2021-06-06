/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_7.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:34:58 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/06 21:39:17 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_clt	*stack_member(int needle, t_stk *stack)
{
	t_itr	itr;

	init_stack_iterator(itr, stack);
	while (!stack_iterator_end(itr))
	{
		if (itr->ptr->data == needle)
			return (itr->ptr);
		stack_iterator_advance(itr);
	}
	return (NULL);
}

int	stack_distance(int a, int b, t_stk *stack)
{
	t_clt	*tmp;
	int		distance;

	tmp = stack->anchor;
	stack->anchor = stack_member(a, stack);
	distance = stack_member_index(b, stack);
	stack->anchor = tmp;
	return (distance);
}

void	apply_inst(t_stk *a_stack, t_stk *b_stack, int inst)
{
	a_stack->tab[inst]((t_stk *[]){a_stack, b_stack});
}

void	stack_move_x_steps(int index, int stk, t_stk **stacks, t_list **lst)
{
	long	inst;

	inst = RA + stk + (RRA - RA) * (index < 0);
	index = ft_abs(index);
	while (index--)
	{
		add_node((void *)inst, lst);
		apply_inst(stacks[A], stacks[B], inst);
	}
}

int	apply_and_push(long inst, t_list **lst, t_stk *a, t_stk *b)
{
	a->tab[inst]((t_stk *[]){a, b});
	add_node((void *)inst, lst);
	return (1);
}
