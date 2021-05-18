/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:56:24 by isaadi            #+#    #+#             */
/*   Updated: 2021/05/10 01:01:48 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**g_cor;

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

void	recursive_inst_fill(int *inst_lst, int last_inst, int inst_pos, int set_len, int members, t_cell cell)
{
	t_bf	valid;
	t_cell	bk;
	int		inst;
	unsigned int		shift;
	int		i;

	valid = get_pool(last_inst, inst_pos, set_len, members, cell.pa, cell.pb, cell.ro.cra, cell.ro.crb, cell.ro.crra, cell.ro.crrb);
	i = -1;
	shift = 0;
	// PV(valid.ones, "%d, ");
	// PV(set_len, "%d\n");
	while (++i < valid.ones)
	{
		while (!(1 << shift & valid.bf))
			shift++;
		// if (shift == 32)
		// {
		// 	PV(valid.bf, "%d\n");
		// 	PV(valid.ones, "%d\n");
		// 	PV(i, "%d\n");
		// }
		inst = shift;
		shift++;
		inst_lst[inst_pos] = inst;
		// PV(inst_pos, "%d\n");
		// if (inst_pos + 1 == set_len)
		// {
			// PV(set_len, "%d\n");
			// for (int itr = 0; itr < inst_pos; itr++) {
			// 	// if (inst_lst[itr] < 0 || inst_lst[itr] > RRR)
			// 	// {
			// 	// 	printf("\n");
			// 	// 	PV(inst_lst[itr], "%d\n");
			// 	// 	exit(1);
			// 	// }
			// 	printf("%s->", g_cor[inst_lst[itr]]);
			// }
			// printf("%s\n", g_cor[inst_lst[inst_pos]]);
		// }
		// else
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
			recursive_inst_fill(inst_lst, inst, inst_pos + 1, set_len, members, cell);
			cell = bk;
		}
	}
}

void	brute_force(t_stk *a_stack, t_stk *b_stack)
{
	int		i;
	int		*inst;
	int		members;
	t_cell	cell;

	i = 0;
	members = a_stack->length;
	(void)b_stack;
	#include <sys/time.h>
	struct timeval tvs, tve;
	gettimeofday(&tvs, NULL);
	while (++i < 100)
	{
		if (i == 11)
			break;
		MALLOC(inst, i);
		ft_memset((void*)&cell, 0, sizeof(cell));
		recursive_inst_fill(inst, -1, 0, i, members, cell);
		PV(i, "%d\n");
		free(inst);
	}
	gettimeofday(&tve, NULL);
	int s, u, m;
	s = tve.tv_sec - tvs.tv_sec;
	u = s * 1000000 + tve.tv_usec - tvs.tv_usec;
	m = u / 1000;
	printf("%ds %dms\n", u / 1000000, m);
}

void	to_indexes(t_stk *a)
{
	t_stki	itr;
	t_stki	sitr;
	long	index;

	init_stack_iterator(&itr, a);
	while (!stack_iterator_end(&itr))
	{
		index = 0;
		init_stack_iterator(&sitr, a);
		while (!stack_iterator_end(&sitr))
		{
			if (sitr.data < itr.data)
				index++;
			stack_iterator_advance(&sitr);
		}
		itr.ptr->data = index;
		stack_iterator_advance(&itr);
	}
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
	// t_stk *bk;
	// bk = stack_duplicate(a_stack);
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
	continue_main(&a_stack, &b_stack);
	return (0);
}