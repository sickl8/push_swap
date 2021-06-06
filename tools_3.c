/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:18:30 by sickl8            #+#    #+#             */
/*   Updated: 2021/06/06 21:40:59 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_tab(int *tab, int len)
{
	int		i;
	int		j;

	i = -1;
	while (++i < len - 1)
	{
		j = i;
		while (++j < len)
		{
			if (tab[i] > tab[j])
			{
				tab[i] = tab[i] ^ tab[j];
				tab[j] = tab[i] ^ tab[j];
				tab[i] = tab[i] ^ tab[j];
			}
		}
	}
}

int	stack_reach_member(int member, int stk, t_stk *stack, t_list **inst)
{
	if (!stack->anchor || !stack_member(member, stack))
		return (1);
	if (stack->length / 2 < stack_member_index(member, stack))
	{
		while (stack->anchor->data != member)
		{
			stack_reverse_rotate(stack);
			add_node((void *)(long)(RRA + stk), inst);
		}
	}
	else
	{
		while (stack->anchor->data != member)
		{
			stack_rotate(stack);
			add_node((void *)(long)(RA + stk), inst);
		}
	}
	return (1);
}

t_clt	*smallest_member(t_stk *stack)
{
	t_stki	itr;
	t_clt	*ret;

	ret = NULL;
	init_stack_iterator(&itr, stack);
	while (!stack_iterator_end(&itr))
	{
		if (!ret || itr.ptr->data < ret->data)
			ret = itr.ptr;
		stack_iterator_advance(&itr);
	}
	return (ret);
}

void	ft_memset(char *s, char c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		s[i++] = c;
}

size_t	list_len(t_list *list)
{
	int		ret;

	ret = 0;
	while (list)
	{
		ret++;
		list = list->next;
	}
	return (ret);
}
