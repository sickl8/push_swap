/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:56:24 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/06 19:41:21 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	inc_tab(int *tab, int base, size_t len)
{
	size_t	i;

	i = len - 1;
	while (tab[i] == base - 1)
		i--;
	if (i < len)
		tab[i]++;
}

int		end_tab(int *tab, int base, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && tab[i] == base - 1)
		i++;
	return ((tab[i] == base - 1));
}

int		mo7aramat(int a, int b)
{
	if (b != -1 && (((a <= SA && a <= SS) && b == a) ||
	(a + b == PB + PA && (a == PB || a == PA)) ||
	((a == RA || a == RR) && (b == RRA || b == RRR)) ||
	((a == RRA || a == RRR) && (b == RA || b == RR)) ||
	((a == RB || a == RR) && (b == RRB || b == RRR)) ||
	((a == RRB || a == RRR) && (b == RB || b == RR))))
		return (1);
	return (0);
}

int		illegal_swap(int pa, int pb, int inst)
{
	if (inst == )
}

int		evaluate_tab(int *tab, size_t len, size_t stack_len)
{
	size_t	i;
	int		pusha;
	int		pushb;

	pusha = 0;
	pushb = 0;
	i = 0;
	while (i < len)
	{
		if (mo7aramat(tab[i], i == len - 1 ? tab[i + 1] : -1))
			return (1);
		if (tab[i] == PA)
			pusha++;
		else if (tab[i] == PB)
			pusha++;
		if (ft_abs(pushb - pusha) > stack_len ||
		(tab[i] < PA && illegal_swap(pusha, pushb, tab[i])))
			return (1);
		i++;
	}
	if (pusha != pushb)
		return (1);
	return (0);
}

int		brute_force_pool(size_t len, t_stk *a_stack, t_list **inst)
{
	int		*tab;
	int		*cmp_tab;
	t_stk	b_stack;
	int		i;

	init_stack(&b_stack);
	tab = wrap_malloc(sizeof(*tab) * len);
	ft_memset(tab, 0, sizeof(*tab) * len);
	i = -1;
	while (++i < len)
		cmp_tab[i] = RRR;
	while (!end_tab(tab, 11, len))
	{
		while (evaluate_tab(tab, len, a_stack->length) && !end_tab(tab, 11, len))
			inc_tab(tab, 11, len);
		apply_instructions(tab, len, a_stack, &b_stack);
		if (stack_is_sorted(a_stack) && stack_size(&b_stack) == 0)
		{
			*inst = export_instructions(tab, len);
			return (1);
		}
	}
	return (0);
}

void	brute_force(t_list *inst, t_stk *a_stack, t_stk *b_stack)
{
	size_t	max_len;
	size_t	i;

	max_len = list_len(inst);
	i = 1;
	while (i < max_len)
	{
		if (brute_force_pool(i, stack_duplicate(a_stack), &inst))
			break ;
		i++;
	}
	print_instructions(inst);
}

void	continue_main_0(t_stk *a_stack, t_stk *b_stack)
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
	brute_force(instructions, a_stack, b_stack);
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
	continue_main_0(&a_stack, &b_stack);
	return (0);
}