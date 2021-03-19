/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:38:16 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/19 01:41:46 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		pivot_member(t_stk *stk)
{
	int		len;
	t_clt	*member;

	stk = stack_duplicate(stk);
	len = stk->length / 2;
	while (len)
	{
		member = smallest_member(stk);
		stack_erase(member, stk);
		len--;
	}
	return (smallest_member(stk)->data);
}

t_list	*algo_3(t_stk *a, t_stk *b)
{
	int		mid;
	t_list	*ret;

	ret = NULL;
	mid = pivot_member(a);
	stack_reach_member(mid, A, a, &ret);
	stack_push_from_a_to_b(a, b);
	add_node((void*)PB, &ret);
	while (a->length)
	{
		if (a->anchor->data > mid)
		{
			stack_push_from_a_to_b(a, b);
			add_node((void*)PB, &ret);
		}
		else
		{
			stack_push_from_a_to_b(a, b);
			add_node((void*)PB, &ret);
			stack_rotate(b);
			add_node((void*)RB, &ret);
		}
	}
	while (b->length)
	{
		stack_push_from_b_to_a(a, b);
		add_node((void*)PA, &ret);
	}
	// printf("dbg from algo2:\n");
	// ITERATE_ON_STACK(a, itr)
	// 	printf("%d ", itr.data);
	// printf("\n");
	// printf("end dbg from algo2:\n");
	return (ret);
}

void	helper_tool_0(t_stk *stk, t_list **list)
{
	t_stki	itr;

	init_stack_iterator(&itr, stk);
	while (!stack_iterator_end(&itr))
	{
		if (itr.data > itr.ptr->next->data)
		{
			stack_swap(stk);
			add_node((void*)SA, list);
		}
		stack_rotate(stk);
		add_node((void*)RA, list);
		stack_iterator_advance(&itr);
	}
}

t_list	*algo_4(t_stk *a_stk, t_stk *b_stk)
{
	t_list	*ret = NULL;
	t_list	*tmp;
	t_list	**tracer;

	helper_tool_0(a_stk, &ret);
	tmp = algo_0(a_stk, b_stk);
	tracer = &ret;
	while (*tracer)
		tracer = &(*tracer)->next;
	*tracer = tmp;
	return (ret);
}