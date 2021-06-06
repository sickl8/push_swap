/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:51:10 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/06 20:09:23 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	stack_is_sorted(t_stk *stack)
{
	t_stki	itr;
	long	data;

	data = LONG_MIN;
	init_stack_iterator(&itr, stack);
	while (!stack_iterator_end(&itr))
	{
		if (itr.ptr->data <= data)
			return (0);
		data = itr.ptr->data;
		stack_iterator_advance(&itr);
	}
	return (1);
}

void	stack_print(t_stk *stack, char sep)
{
	t_stki	itr;

	init_stack_iterator(&itr, stack);
	while (!stack_iterator_end(&itr))
	{
		ft_putnbr(itr.ptr->data);
		o_puts((char []){sep, '\0'});
		stack_iterator_advance(&itr);
	}
	o_puts("\n");
}

void	double_stack_print(t_stk *a_stack, t_stk *b_stack)
{
	t_stki	a_itr;
	t_stki	b_itr;

	init_stack_iterator(&a_itr, a_stack);
	init_stack_iterator(&b_itr, b_stack);
	while (1)
	{
		if (!stack_iterator_end(&a_itr))
		{
			o_puts("      ");
			ft_putnbr(a_itr.ptr->data);
			stack_iterator_advance(&a_itr);
		}
		else if (stack_iterator_end(&b_itr))
			break ;
		if (!stack_iterator_end(&b_itr)
			&& a_itr.stk->length - a_itr.index < b_itr.stk->length)
		{
			o_puts("\t");
			ft_putnbr(b_itr.ptr->data);
			stack_iterator_advance(&b_itr);
		}
		o_puts("\n");
	}
}

void	stack_push_from_a_to_b(t_stk *a, t_stk *b)
{
	stack_push_from_to(a, b);
}

void	stack_push_from_b_to_a(t_stk *a, t_stk *b)
{
	stack_push_from_to(b, a);
}
