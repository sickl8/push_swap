/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:56:24 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/16 01:59:20 by isaadi           ###   ########.fr       */
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

int		inc_tab(int *tab, size_t len, int members)
{
	int		slen[2];
	int		chosen;
	size_t	i;

	i = len - 1;
	slen[A] = members;
	slen[B] = 0;
	while (i < len)
	{
		chosen = tab[i] + 1;
		if (chosen > RRR)
		{
			i--;
			continue ;
		}
		if (chosen != PA && chosen != PB &&
			!((i + 1 == len || i + 2 == len) && (chosen == SB)) &&
			legal_move(!i ? -1 : tab[i - 1], chosen, slen, members))
			break ;
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

// void	brute_force(t_list *inst, t_stk *a_stack)
// {
// 	size_t	max_len;
// 	size_t	i;

// 	max_len = list_len(inst);
// 	i = 1;
// 	while (i < max_len)
// 	{
// 		if (brute_force_pool(i, stack_duplicate(a_stack), &inst))
// 			break ;
// 		i++;
// 	}
// 	print_instructions(inst);
// }

void	continue_main(t_stk *a_stack, t_stk *b_stack)
{
	t_list	**rez;
	
	rez = (t_list*[]){
	algo_0(stack_duplicate(a_stack), stack_duplicate(b_stack)),
	algo_1(stack_duplicate(a_stack)),
	NULL};
	print_instructions(rez[1]);
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
	continue_main(&a_stack, &b_stack);
	return (0);
}