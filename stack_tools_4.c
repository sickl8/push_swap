/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:43:48 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/06 17:09:52 by isaadi           ###   ########.fr       */
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
	int		i;
	t_stk	*ret;
	t_stki	itr;

	ret = wrap_malloc(sizeof(*ret));
	init_stack(ret);
	init_stack_iterator(&itr, stack);
	while (!stack_iterator_end(&itr))
	{
		stack_push_front(itr.ptr->data, ret);
		stack_iterator_advance(&itr);
	}
	return (ret);
}
