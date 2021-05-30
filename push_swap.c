/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:56:24 by isaadi            #+#    #+#             */
/*   Updated: 2021/05/30 17:01:07 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <sys/time.h>

char	**g_cor;
struct timeval i_time[11];
long	calls[11];
double	per_call[11];

void	taxi_driver(t_stk *a_stack, t_stk *b_stack)
{
	t_list	*inst;
	int		index_of_zero;
	int		steps_to_move;
	// int		index_of_current;

	inst = NULL;
	stack_print(a_stack);
	while (!stack_is_kinda_sorted(a_stack) || b_stack->length)
	{
		index_of_zero = stack_member_index(0, a_stack);
		steps_to_move = a_stack->anchor->data + index_of_zero - a_stack->length;
		// printf("%d\n", steps_to_move);
		PV(steps_to_move, "%d\n");
		break;
	}
}

void	apply_inst(t_stk *a_stack, t_stk *b_stack, int inst)
{
	// tv s, e;
	// suseconds_t dif;
	// gettimeofday(&s, NULL);
	a_stack->tab[inst]((t_stk*[]){a_stack, b_stack});
	// gettimeofday(&e, NULL);
	// dif = (e.tv_sec - s.tv_sec) * 1000000 + e.tv_usec - s.tv_usec;
	// i_time[inst].tv_usec += dif;
	// i_time[inst].tv_sec += i_time[inst].tv_usec / 1000000;
	// i_time[inst].tv_usec %= 1000000;
	// calls[inst]++;
}

int		apply_inst_lst(t_stk *a_stack, t_stk *b_stack, int *inst, int len)
{
	int		i;

	i = -1;
	a_stack = stack_duplicate(a_stack);
	b_stack = stack_duplicate(b_stack);
	while (++i < len)
		apply_inst(a_stack, b_stack, inst[i]);
	i = !b_stack->length && stack_is_sorted(a_stack);
	stack_destroy(a_stack);
	stack_destroy(b_stack);
	return (i);
}

t_bf	get_pool(int previous_instruction, int position_of_instruction, int instruction_set_length, int members, int push_a_count, int push_b_count, int consecutive_ra, int consecutive_rb, int consecutive_rra, int consecutive_rrb) {
	t_bf	ret;
	int		a_len;
	int		b_len;
	unsigned int bit_f;

	bit_f = 0;
	ret.ones = 0;
	b_len = push_b_count - push_a_count;
	a_len = members - b_len;
	// push from b to a
	if ((previous_instruction == -1 || previous_instruction != PB) && b_len)
	{
		bit_f |= B_PA + 0 * ret.ones++;
		// printf("a_len = %d, b_len = %d\n", a_len, b_len);
	}
	if (instruction_set_length - position_of_instruction > b_len)
	{
		// swap a
		if ((previous_instruction == -1 || previous_instruction > SS) && a_len > 1)
			bit_f |= B_SA + 0 * ret.ones++;
		// swap b
		if ((previous_instruction == -1 || previous_instruction > SS) && b_len > 1)
			bit_f |= B_SB + 0 * ret.ones++;
		// swap a & b
		if ((previous_instruction == -1 || previous_instruction > SS) && b_len > 1 && a_len > 1)
			bit_f |= B_SS + 0 * ret.ones++;
		// push from a to b
		if ((previous_instruction == -1 || previous_instruction != PB) && a_len && instruction_set_length - position_of_instruction - 1 > b_len + 1)
			bit_f |= B_PB + 0 * ret.ones++;
		// rotate a
		if ((previous_instruction == -1 || (previous_instruction != RRA && previous_instruction != RRR)) && a_len > 1 && consecutive_ra < a_len / 2)
			bit_f |= B_RA + 0 * ret.ones++;
		// rotate b
		if ((previous_instruction == -1 || (previous_instruction != RRB && previous_instruction != RRR)) && b_len > 1 && consecutive_rb < b_len / 2)
			bit_f |= B_RB + 0 * ret.ones++;
		// rotate a & b
		if ((previous_instruction == -1 || previous_instruction < RRA) && a_len > 1 && consecutive_ra < a_len / 2
																	   && b_len > 1 && consecutive_rb < b_len / 2)
			bit_f |= B_RR + 0 * ret.ones++;
		// reverse rotate a
		if ((previous_instruction == -1 || (previous_instruction != RA && previous_instruction != RR)) && a_len > 1 && consecutive_rra < a_len / 2)
			bit_f |= B_RRA + 0 * ret.ones++;
		// reverse rotate b
		if ((previous_instruction == -1 || (previous_instruction != RB && previous_instruction != RR)) && b_len > 1 && consecutive_rrb < b_len / 2)
			bit_f |= B_RRB + 0 * ret.ones++;
		// reverse rotate a & b
		if ((previous_instruction == -1 || (previous_instruction > RR && previous_instruction < RA)) && a_len > 1 && consecutive_rra < a_len / 2
																	   && b_len > 1 && consecutive_rrb < b_len / 2)
			bit_f |= B_RRR + 0 * ret.ones++;
	}
	ret.bf = bit_f;
	return (ret);
}

int		recursive_inst_fill(t_stk *a_stack, t_stk *b_stack, int *inst_lst, int last_inst, int inst_pos, int set_len, int members, t_cell cell)
{
	t_bf	valid;
	t_cell	bk;
	int		inst;
	unsigned int		shift;
	int		i;

	valid = get_pool(last_inst, inst_pos, set_len, members, cell.pa, cell.pb, cell.ro.cra, cell.ro.crb, cell.ro.crra, cell.ro.crrb);
	i = -1;
	shift = 0;
	while (++i < valid.ones)
	{
		while (!(1 << shift & valid.bf))
			shift++;
		inst = shift;
		shift++;
		inst_lst[inst_pos] = inst;
		if (inst_pos + 1 != set_len)
		{
			bk = cell;
			if (inst < RA)
				ft_memset((void*)&cell.ro, 0, sizeof(cell.ro));
			if (inst == PA)
				cell.pa++;
			else if (inst == PB)
				cell.pb++;
			if (inst == RA || inst == RR)
				cell.ro.cra++;
			if (inst == RB || inst == RR)
				cell.ro.crb++;
			if (inst == RRA || inst == RRR)
				cell.ro.crra++;
			if (inst == RRB || inst == RRR)
				cell.ro.crrb++;
			if (recursive_inst_fill(a_stack, b_stack, inst_lst, inst, inst_pos + 1, set_len, members, cell))
				return (1);
			cell = bk;
		}
		else
		{
			if (apply_inst_lst(a_stack, b_stack, inst_lst, set_len))
				return (1);
		}
	}
	return (0);
}

void	brute_force(t_stk *a_stack, t_stk *b_stack)
{
	int		i;
	int		j;
	int		*inst;
	int		members;
	t_cell	cell;

	i = 0;
	members = a_stack->length;
	(void)b_stack;
	while (i++ < 10)
	{
		PV(i, "%d\n");
		MALLOC(inst, i);
		ft_memset((void*)&cell, 0, sizeof(cell));
		ft_memset((void*)i_time, 0, sizeof(i_time));
		ft_memset((void*)calls, 0, sizeof(calls));
		if (recursive_inst_fill(a_stack, b_stack, inst, -1, 0, i, members, cell))
		{
			j = i;
			i = -1;
			while (++i < j)
				printf("%s\n", g_cor[inst[i]]);
			free(inst);
			return ;
		}
		free(inst);
		// for (int itr = 0; itr < RRR; itr++)
		// {
		// 	per_call[itr] = (double)(i_time[itr].tv_sec * 1000000 + i_time[itr].tv_usec) / (double)calls[itr];
		// 	printf("%s: %lds %dms, calls: %ld, percall: %lfus\n", g_cor[itr], i_time[itr].tv_sec, i_time[itr].tv_usec / 1000, calls[itr], per_call[itr]);
		// }
		// tv tmp;
		// tmp.tv_sec = 0;
		// tmp.tv_usec = 0;
		// for (int itr = 0; itr < RRR; itr++)
		// {
		// 	tmp.tv_usec += i_time[itr].tv_sec * 1000000 + i_time[itr].tv_usec;
		// 	tmp.tv_sec += tmp.tv_usec / 1000000;
		// 	tmp.tv_usec %= 1000000;
		// }
		// printf("total: %lds %dms\n", tmp.tv_sec, tmp.tv_usec / 1000);
	}
	taxi_driver(a_stack, b_stack);
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
	stack_destroy(bk);
}

void	continue_main(t_stk *a_stack, t_stk *b_stack)
{
	(void)b_stack;
	// t_clt	*mx;
	// t_list	*inst;
	// int	*tab;
	// int	*tab2;
	// t_stk	temp[1];
	// inst = NULL;
	to_indexes(a_stack);
	// stack_print(a_stack);
	// t_stk *bk;
	// bk = stack_duplicate(a_stack);
	if (!stack_is_sorted(a_stack))
		brute_force(a_stack, b_stack);
	stack_destroy(a_stack);
	// t_itr itr;
	// init_stack_iterator(itr, a_stack);
	// for (int i = 0; i < a_stack->length; i++)
	// {
	// 	printf("%d %d %ld\n", i, tab[i], itr->data);
	// 	stack_iterator_advance(itr);
	// }
	// mx = stack_member(a_stack->length - 1, a_stack);
	// stack_reach_member(mx->next->data, A, a_stack, &inst);
	// double_stack_print(a_stack, c);
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
	to_indexes(&a_stack);
		
	// if (a_stack.length < 10)
		// continue_main(&a_stack, &b_stack);
	// else
		taxi_driver(&a_stack, &b_stack);
	return (0);
}