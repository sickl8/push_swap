/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:56:24 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/14 19:01:25 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	algoo(t_stk *a, t_stk *b, t_list *st, long max)
{
	int		range;
	long	head;
	long	tail;
	long	mbr;

	range = (int)(0.0625 * (float)max + 13.75);
	tail = 0;
	head = 0;
	while (a->length && head < max)
	{
		head = tail;
		tail = head + range;
		mbr = stack_closest_member_in_range(head, tail, a);
		while (mbr != -1)
		{
			stack_reach_member(mbr, A, a, &st) && apply_and_push(PB, &st, a, b);
			mbr = stack_closest_member_in_range(head, tail, a);
		}
	}
	while (--max > -1)
		stack_reach_member(max, B, b, &st) && apply_and_push(PA, &st, a, b);
	print_instructions(st, '\n') && free_list(st);
	stack_destroy(a, TRUE) && stack_destroy(b, TRUE);
}

void	to_indexes(t_stk *a)
{
	t_stki	itr;
	t_stki	sitr;
	long	index;
	t_stk	*bk;

	bk = stack_duplicate(a);
	init_stack_iterator(&itr, a);
	while (!stack_iterator_end(&itr))
	{
		index = 0;
		init_stack_iterator(&sitr, bk);
		while (!stack_iterator_end(&sitr))
		{
			if (sitr.data < itr.data)
				index++;
			stack_iterator_advance(&sitr);
		}
		itr.ptr->data = index;
		stack_iterator_advance(&itr);
	}
	stack_destroy(bk, TRUE);
}

void	continue_main(t_stk *a_stack, t_stk *b_stack)
{
	if (!stack_is_sorted(a_stack))
		brute_force(a_stack, b_stack,
			(char*[]){"sa", "sb", "ss", "pa", "pb", "ra",
			"rb", "rr", "rra", "rrb", "rrr"});
	stack_destroy(a_stack, TRUE);
	stack_destroy(b_stack, TRUE);
}

int	main(int ac, char **av)
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
	to_indexes(&a_stack);
	if (a_stack.length < 7)
		continue_main(stack_duplicate(&a_stack), stack_duplicate(&b_stack));
	else if (!stack_is_kinda_sorted(&a_stack))
		algoo(stack_duplicate(&a_stack),
			stack_duplicate(&b_stack), NULL, a_stack.length);
	else
		sorted(stack_duplicate(&a_stack));
	stack_destroy(&a_stack, FALSE) && stack_destroy(&b_stack, FALSE);
}
