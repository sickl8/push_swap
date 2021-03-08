/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:56:24 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/08 19:29:26 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**g_cor;

int		inc_tab(int *tab, int base, size_t len, size_t stack_len)
{
	size_t	i;

	while (1)
	{
		i = len - 1;
		while (i < len && tab[i] == base - 1)
		{
			tab[i] = 0;
			i--;
		}
		if (i < len)
			tab[i]++;
		else
			return (1);
		if (evaluate_tab(tab, len, stack_len))
		{
			// printf("Illegal chain\n");
			continue ;
		}
		// printf("Legal chain\n");
		break ;
	}
	return (0);
}

int		mo7aramat(int a, int b)
{
	if (b != -1 && (((a <= SA && a <= SS) && b == a) ||
	(a + b == PB + PA && (a == PB || a == PA)) ||
	((a == RA || a == RR) && (b == RRA || b == RRR)) ||
	((a == RRA || a == RRR) && (b == RA || b == RR)) ||
	((a == RB || a == RR) && (b == RRB || b == RRR)) ||
	((a == RRB || a == RRR) && (b == RB || b == RR))))
	{
		// printf("%s->%s:", g_cor[a], g_cor[b]);
		return (1);
	}
	return (0);
}

int		illegal_rotate(int pa, int pb, int inst, int stack_len)
{
	if ((inst != RB && inst != RRB && stack_len - pb + pa < 2) ||
		(inst != RA && inst != RRA && pb - pa < 2))
		return (1);
	return (0);
}

int		illegal_swap(int pa, int pb, int inst, int stack_len)
{
	if (((inst == SA || inst == SS) && stack_len - pb + pa < 2) ||
		((inst == SB || inst == SS) && pb - pa < 2))
		return (1);
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
	
	// printf("evaluating:");
	// for (size_t asd = 0; asd < len; asd++)
	// 	printf("[%s]", g_cor[tab[asd]]);
	// printf(": ");
	while (i < len)
	{
		if (mo7aramat(tab[i], i != len - 1 ? tab[i + 1] : -1))
		{
			// for (size_t asd = 0; asd < len; asd++)
			// 	printf("[%s]", g_cor[tab[asd]]);
			// printf(":");
			// printf("mo7ramat\n");
			return (1);
		}
		if (tab[i] == PA)
			pusha++;
		else if (tab[i] == PB)
			pushb++;
		if (ft_abs(pushb - pusha) > (long)stack_len)
		{
			// for (size_t asd = 0; asd < len; asd++)
			// 	printf("[%s]", g_cor[tab[asd]]);
			// printf(":");
			// printf("mo7ramat 1\n");
			return 1;
		}
		else if (pusha > pushb)
		{
			// for (size_t asd = 0; asd < len; asd++)
			// 	printf("[%s]", g_cor[tab[asd]]);
			// printf(":");
			// printf("mo7ramat 2\n");
			return 1;
		}
		else if (tab[i] < PA && illegal_swap(pusha, pushb, tab[i], stack_len))
		{
			// for (size_t asd = 0; asd < len; asd++)
			// 	printf("[%s]", g_cor[tab[asd]]);
			// printf(":");
			// printf("illegal_swap\n");
			return (1);
		}
		else if (tab[i] > PB && illegal_rotate(pusha, pushb, tab[i], stack_len))
		{
			// for (size_t asd = 0; asd < len; asd++)
			// 	printf("[%s]", g_cor[tab[asd]]);
			// printf(":");
			// printf("illegal_rotate\n");
			return (1);
		}
		i++;
	}
	if (pusha != pushb)
	{
		// printf("mo7ramat 3\n");
		return (1);
	}
	return (0);
}

void	generate_tab(int *tab, size_t len, int a_stklen)
{
	size_t	i;
	int		chosen;
	int		b_stklen;

	i = 0;
	b_stklen = 0;
	while (i < len)
	{
		chosen = tab[i] + 1;
		while (chosen < RRR + 1)
		{
			
			chosen++;
		}
		if (chosen == RRR + 1)
			i--;
		i++;
	}
}

int		brute_force_pool(size_t len, t_stk *a_stack, t_list **inst)
{
	int		*tab;
	t_stk	b_stack;
	int		i;

	// len = 1;
	// while (len < 500)
	// {
	init_stack(&b_stack);
	tab = wrap_malloc(sizeof(*tab) * len);
	// ft_memset(tab, 0, sizeof(*tab) * len);
	i = -1;
	while (++i < len)
		tab[i] = -1;
	generate_tab(tab, len, a_stack->length);
	tab[len - 1] = -1;
	size_t count = 0;
	while (!inc_tab(tab, 11, len, a_stack->length))
	{
		// apply_instructions(tab, len, a_stack, &b_stack);
		// if (stack_is_sorted(a_stack) && stack_size(&b_stack) == 0)
		// {
		// 	*inst = export_instructions(tab, len);
		// 	return (1);
		// }
		// printf("count = %zu\n", count);
		count++;
	}
	printf("count = %zu\n", count);
	// len++;
	// }
	(void)inst;
	(void)a_stack;
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

	g_cor = (char*[])
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
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