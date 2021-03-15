/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:43:48 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/15 19:24:12 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		stack_member_index_p(t_clt *member, t_stk *stack)
{
	return (stack_member_index(member->data, stack));
}

int		stack_member_index(int data, t_stk *stack)
{
	t_stki	itr;

	init_stack_iterator(&itr, stack);
	while (!stack_iterator_end(&itr))
	{
		if (itr.ptr->data == data)
			return (itr.index);
		stack_iterator_advance(&itr);
	}
	return (-1);
}

t_stk	*stack_duplicate(t_stk *stack)
{
	t_stk	*ret;
	t_stki	itr;

	ret = wrap_malloc(sizeof(*ret));
	init_stack(ret);
	init_stack_iterator(&itr, stack);
	while (!stack_iterator_end(&itr))
	{
		stack_push_back(itr.ptr->data, ret);
		stack_iterator_advance(&itr);
	}
	return (ret);
}

int		biggest_member(t_stk *stack)
{
	t_stki	itr;
	int		ret;

	ret = INT_MIN;
	init_stack_iterator(&itr, stack);
	while (!stack_iterator_end(&itr))
	{
		if (itr.ptr->data > ret)
			ret = itr.ptr->data;
		stack_iterator_advance(&itr);
	}
	return (ret);
}

int		stack_reach_closest_member(int m1, int m2, t_stk *stack, t_list **inst)
{
	int		len1;
	int		len2;
	int		i1;
	int		i2;

	i1 = stack_member_index(m1, stack);
	i2 = stack_member_index(m2, stack);
	len1 = ft_min(i1 - stack->length / 2, i1);
	len2 = ft_min(i2 - stack->length / 2, i2);
	if (len1 < len2)
	{
		stack_reach_member(m1, A, stack, inst);
		return (m1);
	}
	stack_reach_member(m2, A, stack, inst);
	return (m2);
}