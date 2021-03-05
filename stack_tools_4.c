/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sickl8 <sickl8@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:43:48 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/05 23:22:21 by sickl8           ###   ########.fr       */
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
