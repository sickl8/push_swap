/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:18:30 by sickl8            #+#    #+#             */
/*   Updated: 2021/03/06 16:51:41 by isaadi           ###   ########.fr       */
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
			if (tab[i] > tab[j])
			{
				tab[i] = tab[i] ^ tab[j];
				tab[j] = tab[i] ^ tab[j];
				tab[i] = tab[i] ^ tab[j];
			}
	}
}

void	stack_reach_member(int member, t_stk *stack, t_list **instructions)
{
	if (stack->length / 2 < stack_member_index(member, stack))
	{
		while (stack->anchor->data != member)
		{
			reverse_rotate_stack(stack);
			add_node((void*)RRA, instructions);
		}
	}
	else
	{
		while (stack->anchor->data != member)
		{
			rotate_stack(stack);
			add_node((void*)RA, instructions);
		}
	}
}

int		smallest_member(t_stk *stack)
{
	t_stki	itr;
	int		ret;

	ret = INT_MAX;
	init_stack_iterator(&itr, stack);
	while (!stack_iterator_end(&itr))
	{
		if (itr.ptr->data < ret)
			ret = itr.ptr->data;
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