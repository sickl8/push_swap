/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:56:24 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/05 19:00:36 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_instructions(t_list *instructions)
{
	char **cor;
	
	cor = (char*[]){"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	while (instructions)
	{
		o_puts(cor[(int)instructions->data]);
		o_puts("\n");
		instructions = instructions->next;
	}
}

void	continue_main(t_stk *a_stack, t_stk *b_stack)
{
	t_stki	itr;
	int		anchor;
	t_list	*instructions;

	(void)b_stack;
	anchor = INT_MAX;
	instructions = NULL;
	init_stack_iterator(&itr, a_stack);
	while (!stack_iterator_end(&itr))
	{
		if (itr.ptr->data < anchor)
			anchor = itr.ptr->data;
		stack_iterator_advance(&itr);
	}
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