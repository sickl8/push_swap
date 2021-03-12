/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sickl8 <sickl8@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:56:24 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/12 02:16:02 by sickl8           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**g_cor;

// int		inc_tab(int *tab, int base, size_t len, size_t stack_len)
// {
// 	size_t	i;

// 	while (1)
// 	{
// 		i = len - 1;
// 		while (i < len && tab[i] == base - 1)
// 		{
// 			tab[i] = 0;
// 			i--;
// 		}
// 		if (i < len)
// 			tab[i]++;
// 		else
// 			return (1);
// 		if (evaluate_tab(tab, len, stack_len))
// 		{
// 			// printf("Illegal chain\n");
// 			continue ;
// 		}
// 		// printf("Legal chain\n");
// 		break ;
// 	}
// 	return (0);
// }

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

int		illegal_rotation(int alen, int blen, int inst)
{
	if ((inst != RB && inst != RRB && alen < 2) ||
		(inst != RA && inst != RRA && blen < 2))
		return (1);
	return (0);
}

int		illegal_swap(int alen, int blen, int inst)
{
	if ((inst != SB && alen < 2) ||
		(inst != SA && blen < 2))
		return (1);
	return (0);
}

// int		evaluate_tab(int *tab, size_t len, size_t stack_len)
// {
// 	size_t	i;
// 	int		pusha;
// 	int		pushb;

// 	// return 0;
// 	pusha = 0;
// 	pushb = 0;
// 	i = 0;
	
// 	// printf("evaluating:");
// 	// for (size_t asd = 0; asd < len; asd++)
// 	// 	printf("[%s]", g_cor[tab[asd]]);
// 	// printf(": ");
// 	while (i < len)
// 	{
// 		if (mo7aramat(tab[i], i != len - 1 ? tab[i + 1] : -1))
// 		{
// 			// for (size_t asd = 0; asd < len; asd++)
// 			// 	printf("[%s]", g_cor[tab[asd]]);
// 			// printf(":");
// 			// printf("mo7ramat\n");
// 			return (1);
// 		}
// 		if (tab[i] == PA)
// 			pusha++;
// 		else if (tab[i] == PB)
// 			pushb++;
// 		if (ft_abs(pushb - pusha) > (long)stack_len)
// 		{
// 			// for (size_t asd = 0; asd < len; asd++)
// 			// 	printf("[%s]", g_cor[tab[asd]]);
// 			// printf(":");
// 			// printf("mo7ramat 1\n");
// 			return 1;
// 		}
// 		else if (pusha > pushb)
// 		{
// 			// for (size_t asd = 0; asd < len; asd++)
// 			// 	printf("[%s]", g_cor[tab[asd]]);
// 			// printf(":");
// 			// printf("mo7ramat 2\n");
// 			return 1;
// 		}
// 		else if (tab[i] < PA && illegal_swap(pusha, pushb, tab[i]/*, stack_len*/))
// 		{
// 			// for (size_t asd = 0; asd < len; asd++)
// 			// 	printf("[%s]", g_cor[tab[asd]]);
// 			// printf(":");
// 			// printf("illegal_swap\n");
// 			return (1);
// 		}
// 		else if (tab[i] > PB && illegal_rotate(pusha, pushb, tab[i], stack_len))
// 		{
// 			// for (size_t asd = 0; asd < len; asd++)
// 			// 	printf("[%s]", g_cor[tab[asd]]);
// 			// printf(":");
// 			// printf("illegal_rotate\n");
// 			return (1);
// 		}
// 		i++;
// 	}
// 	if (pusha != pushb)
// 	{
// 		// printf("mo7ramat 3\n");
// 		return (1);
// 	}
// 	return (0);
// }

int		legal_move(int a, int move, int *slen, int mxlen)
{
	if (a != -1 && mo7aramat(a, move))
		return (0);
	if ((move == PA && slen[B] == 0) || (move == PB && slen[A] == 0))
		return (0);
	else if (move < PA && illegal_swap(slen[A], slen[B], move))
		return (0);
	else if (move > PB && illegal_rotation(slen[A], slen[B], move))
		return (0);
	else if ((move == PA && (slen[B] > 1 || slen[A] == mxlen)) ||
		(move == PB && (slen[A] < 1 || slen[B] == mxlen)))
		return (0);
	return (1);
}

int		inc_tab(int *tab, size_t len)
{
	int		i;
	int		chosen;

	i = len - 1;
	chosen = tab[i] + 1;
	while (i > -1 && i < len)
	{
		if (chosen > RRR)
		{
			i--;
			continue ;
		}
		if (legal_move())
		i++;
	}
	return (0);
}

void	generate_tab(int *tab, size_t len, int members)
{
	size_t	i;
	int		chosen;
	int		slen[2];

	i = -1;
	slen[A] = members;
	slen[B] = 0;
	while (++i < len)
	{
		chosen = tab[i];
		while (++chosen < RRR + 1)
		{
			tab[i] = chosen;
			if ((int)(len - i) <= members - slen[A])
			{
				tab[i] = PA;
				chosen = PA;
				break ;
			}
			else if (legal_move(i ? tab[i - 1] : -1, chosen, slen, members) &&
			!((i + 1 == len || i + 2 == len) && chosen == PB))
				break ;
		}
		if (chosen == PA)
			(void)(1 + 0 * (slen[A]++) && 1 + 0 * (slen[B]--));
		else if (chosen == PB)
			(void)(1 + 0 * (slen[A]--) && 1 + 0 * (slen[B]++));
	}
	int p = 0;
	i = 0;
	while (i < len)
	{
		if (tab[i] == PA)
	 		p++;
		else if (tab[i] == PB)
			p--;
		i++;
	}
	if (p == 0)
		printf("success!\n");
	// i = len - 1;
	// while (slen[A]-- != members)
	// 	tab[i--] = PA;
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
	len = 1;
	while (len < 50)
	{
		tab = wrap_malloc(sizeof(*tab) * len);
		// ft_memset(tab, 0, sizeof(*tab) * len);
		i = -1;
		while (++i < (int)len)
			tab[i] = -1;
		generate_tab(tab, len, a_stack->length);
		// for (size_t asd = 0; asd < len; asd++)
		// 	printf("[%d]", tab[asd]);
		// printf("\n");
		for (size_t asd = 0; asd < len; asd++)
			printf("[%s]", g_cor[tab[asd]]);
		printf("\n");
		size_t count = 0;
		while (!inc_tab(tab, len))
		{
			count++;
		}
		printf("count = %zu\n", count);
		len++;
	}
	// tab[len - 1] = -1;
	// while (!inc_tab(tab, 11, len, a_stack->length))
	// {
	// 	// apply_instructions(tab, len, a_stack, &b_stack);
	// 	// if (stack_is_sorted(a_stack) && stack_size(&b_stack) == 0)
	// 	// {
	// 	// 	*inst = export_instructions(tab, len);
	// 	// 	return (1);
	// 	// }
	// 	// printf("count = %zu\n", count);
	// 	count++;
	// }
	// printf("count = %zu\n", count);
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