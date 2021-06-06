/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_11.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:42:47 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/06 21:07:58 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long	stack_closest_member_in_range(int a, int b, t_stk *stk)
{
	long	member;
	long	dis;
	t_tmp0	ms;

	if (!stk->anchor)
		return (-1);
	ms.member = -1;
	member = a;
	while (member < b)
	{
		dis = stack_shortest_distance(stk->anchor->data, member, stk);
		if (dis > -1 && (ms.member == -1 || dis < ms.steps))
		{
			ms.member = member;
			ms.steps = dis;
		}
		member++;
	}
	return (ms.member);
}

t_bf	get_pool(t_inf i, t_cell cell)
{
	t_bf			ret;
	int				a_len;
	int				b_len;

	ret.bf = 0;
	ret.ones = 0;
	b_len = cell.pb - cell.pa;
	a_len = i.mbr - b_len;
	if ((i.li == -1 || i.li != PB) && b_len)
		ret.bf |= B_PA + 0 * ret.ones++;
	if (i.sl - i.ip > b_len)
	{
		ret.bf |= B_SA * sa(i, (int []){a_len, b_len}, cell, &(ret.ones));
		ret.bf |= B_SB * sb(i, (int []){a_len, b_len}, cell, &(ret.ones));
		ret.bf |= B_SS * ss(i, (int []){a_len, b_len}, cell, &(ret.ones));
		ret.bf |= B_PB * pb(i, (int []){a_len, b_len}, cell, &(ret.ones));
		ret.bf |= B_RA * ra(i, (int []){a_len, b_len}, cell, &(ret.ones));
		ret.bf |= B_RB * rb(i, (int []){a_len, b_len}, cell, &(ret.ones));
		ret.bf |= B_RR * rr(i, (int []){a_len, b_len}, cell, &(ret.ones));
		ret.bf |= B_RRA * rra(i, (int []){a_len, b_len}, cell, &(ret.ones));
		ret.bf |= B_RRB * rrb(i, (int []){a_len, b_len}, cell, &(ret.ones));
		ret.bf |= B_RRR * rrr(i, (int []){a_len, b_len}, cell, &(ret.ones));
	}
	return (ret);
}

int	crif(int inst, t_cell *cell)
{
	if (inst < RA)
		ft_memset((void *)&cell->ro, 0, sizeof(cell->ro));
	cell->pa += (inst == PA);
	cell->pb += (inst == PB);
	cell->ro.cra += (inst == RA || inst == RR);
	cell->ro.crb += (inst == RB || inst == RR);
	cell->ro.crra += (inst == RRA || inst == RRR);
	cell->ro.crrb += (inst == RRB || inst == RRR);
	return (1);
}

int	rif(t_stk *a, t_stk *b, t_inf in, t_cell cell)
{
	t_bf			valid;
	t_cell			bk;
	int				inst;
	unsigned int	shift;
	int				i;

	valid = get_pool(in, cell);
	i = -1;
	shift = 0;
	while (++i < valid.ones)
	{
		while (!(1 << shift & valid.bf))
			shift++;
		inst = shift++;
		in.il[in.ip] = inst;
		bk = cell;
		in.ip++;
		if ((in.ip + 1 != in.sl && crif(inst, &cell) && rif(a, b, in, cell))
			|| (!(in.ip + 1 != in.sl) && apply_inst_lst(a, b, in.il, in.sl)))
			return (1);
		in.ip--;
		cell = bk;
	}
	return (0);
}

void	brute_force(t_stk *a_stack, t_stk *b_stack, char **g_cor)
{
	int		i;
	int		j;
	int		*inst;
	int		members;
	t_cell	cell;

	members = a_stack->length;
	i = 0;
	while (i++ < 10)
	{
		inst = wrap_malloc(sizeof(*(inst)) * i);
		ft_memset((void *)&cell, 0, sizeof(cell));
		ft_memset((void *)inst, 0, i * sizeof(*inst));
		if (rif(a_stack, b_stack, (t_inf){inst, -1, 0, i, members}, cell))
		{
			j = i;
			i = -1;
			while (++i < j)
				o_puts(g_cor[inst[i]]) && o_puts("\n");
			free(inst);
			return ;
		}
		free(inst);
	}
}
