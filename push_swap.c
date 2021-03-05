/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sickl8 <sickl8@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:56:24 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/05 23:54:19 by sickl8           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	continue_main(t_stk *a_stack, t_stk *b_stack)
{
	int		smallest;
	t_list	*instructions;

	(void)b_stack;
	instructions = NULL;
	while (a_stack->length > 1)
	{
		smallest = smallest_member(a_stack);
		stack_reach_member(smallest, a_stack, &instructions);
		stack_push_from_a_to_b(a_stack, b_stack);
		add_node((void*)PB, &instructions);
	}
	while (b_stack->length)
	{
		stack_push_from_b_to_a(a_stack, b_stack);
		add_node((void*)PA, &instructions);
	}
	print_instructions(instructions);
}

int		main(int ac, char **av)
{
	t_stk	a_stack;
	t_stk	b_stack;
	int		i;

	(void)(init_stack(&a_stack) && init_stack(&b_stack));
	if (ac == 1)
		return (0);
	i = 0;
	while (av[++i])
	{
		if (check_sanity(av[i]) || stack_member(ft_atoi(av[i]), &a_stack))
			error();
		stack_push_back(ft_atoi(av[i]), &a_stack);
	}
	if (ac == 2)
		return (0);
	continue_main(&a_stack, &b_stack);
	return (0);
}