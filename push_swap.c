/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sickl8 <sickl8@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:56:24 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/08 03:09:32 by sickl8           ###   ########.fr       */
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
	
	while (i < len)
	{
		if (tab[i] != base - 1)
			return (0);
		i++;
	}
	printf("sa7i7?\n");
	char **cor;
	cor = (char*[])
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	PV(cor[tab[0]], "%s\n");
	return (1);
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

int		illegal_swap(int pa, int pb, int inst, int stack_len)
{
	if (((inst == SA || inst == SS) && stack_len - pb + pa < 2) ||
		((inst == SB || inst == SS) && pb - pa < 2))
	{
		printf("illegal_swap ");
		return (1);
	}
	return (0);
}

int		evaluate_tab(int *tab, size_t len, size_t stack_len)
{
	size_t	i;
	int		pusha;
	int		pushb;

	// return 0;
	pusha = 0;
	pushb = 0;
	i = 0;
	while (i < len)
	{
		if (mo7aramat(tab[i], i != len - 1 ? tab[i + 1] : -1))
		{
			printf("mo7ramat\n"); 
			return (1);
		}
		if (tab[i] == PA)
			pusha++;
		else if (tab[i] == PB)
			pushb++;
		if (ft_abs(pushb - pusha) > (long)stack_len)
		{
			printf("mo7ramat 1\n");
			return 1;
		}
		else if (pushb - pusha < 0)
		{
			printf("mo7ramat 2\n");
			return 1;
		}
		else if (tab[i] < PA && illegal_swap(pusha, pushb, tab[i], stack_len))
		{
			printf("\n");
			return (1);
		}
		i++;
	}
	if (pusha != pushb)
		return (1);
	return (0);
}

int		brute_force_pool(size_t len, t_stk *a_stack, t_list **inst)
{
	int		*tab;
	t_stk	b_stack;
	int		i;

	init_stack(&b_stack);
	tab = wrap_malloc(sizeof(*tab) * len);
	// ft_memset(tab, 0, sizeof(*tab) * len);
	i = -1;
	while (++i < (int)len)
		tab[i] = 0;
	size_t count = 0;
	char **cor;
	cor = (char*[])
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	while (!end_tab(tab, 11, len))
	{
		for (size_t asd = 0; asd < len; asd++)
			printf("uncensored [%s]", cor[tab[asd]]);
		printf("\n");
		while (evaluate_tab(tab, len, a_stack->length))
		{
			if (!end_tab(tab, 11, len))
				inc_tab(tab, 11, len);
			else
				break ;
		}
		// PV(!end_tab(tab, 11, len), "%d\n");
		for (size_t asd = 0; asd < len; asd++)
			printf("[%s]", cor[tab[asd]]);
		printf("\n");
		// apply_instructions(tab, len, a_stack, &b_stack);
		// if (stack_is_sorted(a_stack) && stack_size(&b_stack) == 0)
		// {
		// 	*inst = export_instructions(tab, len);
		// 	return (1);
		// }
		// printf("count = %zu\n", count);
		count++;
		if (!end_tab(tab, 11, len))
			inc_tab(tab, 11, len);
		else
			break ;
	}
	printf("count = %zu\n", count);
	(void)inst;
	exit(0);
	return (0);
}

void	brute_force(t_list *inst, t_stk *a_stack)
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
	brute_force(instructions, a_stack);
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