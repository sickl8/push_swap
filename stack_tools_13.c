/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_13.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 20:12:46 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/14 19:04:03 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rrotate_b(t_stk **stacks)
{
	stack_reverse_rotate(stacks[B]);
}

void	rrotate_r(t_stk **stacks)
{
	stack_reverse_rotate(stacks[A]);
	stack_reverse_rotate(stacks[B]);
}

int	free_list(t_list *lst)
{
	t_list	*nxt;

	while (lst)
	{
		nxt = lst->next;
		free(lst);
		lst = nxt;
	}
	return (1);
}

void	sorted(t_stk *a_stack)
{
	t_list	*inst;

	inst = NULL;
	stack_reach_member(0, A, a_stack, &inst);
	print_instructions(inst, '\n');
	free_list(inst);
	stack_destroy(a_stack, TRUE);
}
