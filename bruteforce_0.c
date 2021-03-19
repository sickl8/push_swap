/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:02:25 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/19 18:50:36 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*bf_0(t_stk *a)
{
	t_list *ret;

	ret = NULL;
	int len = 0;
	while (1)
	{
		int *tab;
		
		tab = wrap_malloc(sizeof(*tab) * (len + 1));
		tab[len] = -1;
		int i = -1;
		while (i < len)
		while (!end_tab(tab))
		{
			if (apply_inst(tab, stack_duplicate(a)))
				return (export_tab(tab));
			inc_tab(tab);
		}
		len++;
	}
}