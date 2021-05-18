/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 02:47:37 by isaadi            #+#    #+#             */
/*   Updated: 2021/05/10 00:06:25 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		stack_is_kinda_sorted(t_stk *stack)
{
	int		smallest;
	t_clt	*bk_anchor;
	int		ret;

	// stack_print(stack);
	// o_puts("---\n");
	// sleep(2);
	smallest = smallest_member(stack)->data;
	bk_anchor = stack->anchor;
	stack->anchor = stack_member(smallest, stack);
	ret = stack_is_sorted(stack);
	stack->anchor = bk_anchor;
	return (ret);
}

int		index_of(int member, int *tab, int len)
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

int		stack_score(t_stk *stack)
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
	// for (int x = 0; x < stack->length; x++)
	// 	printf("%d, ", tab[x]);
	// printf("\n");
	stack = stack_duplicate(stack);
	stack->anchor = smallest_member(stack);
	init_stack_iterator(&itr, stack);
	ret = 0;
	while (!stack_iterator_end(&itr))
	{
		dis = ft_abs(index_of(itr.data, tab, stack->length) - itr.index);
		// printf("-%d-", dis);
		ret += ft_min(stack->length - dis, dis);
		stack_iterator_advance(&itr);
	}
	// printf("\n");
	return (ret);
}

int		*to_tab(t_stk *stack)
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

void	stack_destroy(t_stk *stack)
{
	while (stack->length)
		stack_erase(stack->anchor, stack);
}