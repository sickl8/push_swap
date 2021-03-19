/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:52:12 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/18 23:40:47 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*algo_1(t_stk *a_stack)
{
	t_list	*ret;
	int		sm;
	int		bi;

	ret = NULL;
	sm = smallest_member(a_stack)->data;
	bi = biggest_member(a_stack)->data;
	(void)bi;
	while (!stack_is_kinda_sorted(a_stack))
	{
		if (a_stack->anchor->data == sm)
		{
			stack_reverse_rotate(a_stack);
			stack_reverse_rotate(a_stack);
			add_node((void*)RRA, &ret);
			add_node((void*)RRA, &ret);
		}
		else if (a_stack->anchor->next->data == sm)
		{
			stack_reverse_rotate(a_stack);
			add_node((void*)RRA, &ret);
		}
		if (a_stack->anchor->data > a_stack->anchor->next->data /*
		&& a_stack->anchor->data != sm && a_stack->anchor->next->data != sm*/)
		{
			stack_swap(a_stack);
			add_node((void*)SA, &ret);
		}
		if (stack_is_kinda_sorted(a_stack))
			break ;
		stack_reverse_rotate(a_stack);
		add_node((void*)RRA, &ret);
	}
	stack_reach_member(smallest_member(a_stack)->data, A, a_stack, &ret);
	return (ret);
}

t_list	*algo_2(t_stk *a_stack)
{
	t_list	*ret;
	int		sm;
	int		bi;

	ret = NULL;
	sm = smallest_member(a_stack)->data;
	bi = biggest_member(a_stack)->data;
	(void)bi;
	while (!stack_is_kinda_sorted(a_stack))
	{
		if (a_stack->anchor->data > a_stack->anchor->next->data &&
			a_stack->anchor->data != sm && a_stack->anchor->next->data != sm)
		{
			stack_swap(a_stack);
			add_node((void*)SA, &ret);
		}
		if (stack_is_kinda_sorted(a_stack))
			break ;
		stack_rotate(a_stack);
		add_node((void*)RA, &ret);
	}
	stack_reach_member(smallest_member(a_stack)->data, A, a_stack, &ret);
	return (ret);
}