/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:02:25 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/06 20:12:30 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_b(t_stk **stacks)
{
	stack_push_from_a_to_b(stacks[A], stacks[B]);
}

void	rotate_a(t_stk **stacks)
{
	stack_rotate(stacks[A]);
}

void	rotate_b(t_stk **stacks)
{
	stack_rotate(stacks[B]);
}

void	rotate_r(t_stk **stacks)
{
	stack_rotate(stacks[A]);
	stack_rotate(stacks[B]);
}

void	rrotate_a(t_stk **stacks)
{
	stack_reverse_rotate(stacks[A]);
}
