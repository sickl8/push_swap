/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 02:47:37 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/14 18:56:38 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	stack_is_kinda_sorted(t_stk *stack)
{
	t_clt	*bk_anchor;
	int		ret;

	bk_anchor = stack->anchor;
	stack->anchor = stack_member(0, stack);
	ret = stack_is_sorted(stack);
	stack->anchor = bk_anchor;
	return (ret);
}

int	index_of(int member, int *tab, int len)
{
	int		ret;

	ret = 0;
	while (ret < len)
	{
		if (tab[ret] == member)
			return (ret);
		ret++;
	}
	exit(1);
	return (0);
}

int	stack_score(t_stk *stack)
{
	int		ret;
	t_stki	itr;
	int		*tab;
	int		dis;

	tab = wrap_malloc(sizeof(*tab) * stack->length);
	ret = 0;
	init_stack_iterator(&itr, stack);
	while (!stack_iterator_end(&itr))
	{
		tab[ret++] = itr.ptr->data;
		stack_iterator_advance(&itr);
	}
	sort_tab(tab, stack->length);
	stack = stack_duplicate(stack);
	stack->anchor = smallest_member(stack);
	init_stack_iterator(&itr, stack);
	ret = 0;
	while (!stack_iterator_end(&itr))
	{
		dis = ft_abs(index_of(itr.data, tab, stack->length) - itr.index);
		ret += ft_min(stack->length - dis, dis);
		stack_iterator_advance(&itr);
	}
	return (ret);
}

int	*to_tab(t_stk *stack)
{
	int		*ret;
	t_itr	itr;

	ret = wrap_malloc(sizeof(*ret) * stack->length);
	if (!ret)
		return (NULL);
	init_stack_iterator(itr, stack);
	while (!stack_iterator_end(itr))
	{
		ret[itr->index] = itr->data;
		stack_iterator_advance(itr);
	}
	return (ret);
}

int	stack_destroy(t_stk *stack, int free_p)
{
	while (stack->length)
		stack_erase(stack->anchor, stack);
	if (free_p)
		free(stack);
	return (1);
}
