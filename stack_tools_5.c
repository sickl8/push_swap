/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 02:47:37 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/16 03:25:33 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		stack_is_kinda_sorted(t_stk *stack)
{
	int		smallest;
	t_clt	*bk_anchor;
	int		ret;

	// stack_print(stack);
	// o_puts("---\n");
	// sleep(2);
	smallest = smallest_member(stack);
	bk_anchor = stack->anchor;
	stack->anchor = stack_member(smallest, stack);
	ret = stack_is_sorted(stack);
	stack->anchor = bk_anchor;
	return (ret);
}