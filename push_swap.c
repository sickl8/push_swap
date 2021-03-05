/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:56:24 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/05 19:04:51 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		choose_correct_anchor(int anchor)
{
	
}

void	continue_main(t_stk *a_stack, t_stk *b_stack)
{
	t_stki	itr;
	int		anchor;
	t_list	*instructions;

	(void)b_stack;
	instructions = NULL;
	anchor = choose_correct_anchor(INT_MAX);
	if (a_stack->length / 2 < stack_member_index(anchor, a_stack))
		while (a_stack->anchor->data != anchor)
		{
			reverse_rotate_stack(a_stack);
			add_node((void*)RRA, &instructions);
		}
	else
		while (a_stack->anchor->data != anchor)
		{
			rotate_stack(a_stack);
			add_node((void*)RA, &instructions);
		}
	stack_print(a_stack);
	print_instructions(instructions);
}

int		main(int ac, char **av)
{
	t_stk	a_stack;
	t_stk	b_stack;
	int		i;

	init_stack(&a_stack) && init_stack(&b_stack);
	if (ac == 1)
		return (0);
	i = 0;
	while (av[++i])
	{
		if (check_sanity(av[i]) || stack_member(ft_atoi(av[i]), &a_stack))
			error();
		stack_push_back(ft_atoi(av[i]), &a_stack);
	}
	continue_main(&a_stack, &b_stack);
	return (0);
}