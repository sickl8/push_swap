/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 12:35:50 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/05 12:40:56 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	stack_print_from_anchor(t_stk *stack, char sep)
{
	t_itr	itr;
	t_clt	*tmp;

	tmp = stack->anchor;
	stack->anchor = stack_member(0, stack);
	init_stack_iterator(itr, stack);
	while (!stack_iterator_end(itr))
	{
		ft_putnbr(itr->ptr->data);
		o_puts((char[]){sep, '\0'});
		stack_iterator_advance(itr);	
	}
	stack->anchor = tmp;
}