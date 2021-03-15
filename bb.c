#include <stdio.h>
#include <stdlib.h>

#include "header.h"

#define PV(x, y) printf("%s = " y, #x, x)
#define MALLOC(x, y) x = wrap_malloc(sizeof(*(x)) * (y))

void inc_tab(int *tab, int len)
{
	int i = len - 1;
	while (tab[i] == RRR && i > -1)
	{
		tab[i] = SA;
		i--;
	}
	if (i > -1)
		tab[i]++;
}

int	apply_inst(int *tab, t_stk *a_stack)
{
	t_stk *b_stack;
	MALLOC(b_stack, 1);
	init_stack(b_stack);
	int *itr;
	int	ret;

	itr = tab;
	while (*itr != -1)
	{
		if (*itr == SA || *itr == SS)
			stack_swap(a_stack);
		if (*itr == SB || *itr == SS)
			stack_swap(b_stack);
		if (*itr == RA || *itr == RR)
			rotate_stack(a_stack);
		if (*itr == RB || *itr == RR)
			rotate_stack(b_stack);
		if (*itr == RRA || *itr == RRR)
			reverse_rotate_stack(a_stack);
		if (*itr == RRB || *itr == RRR)
			reverse_rotate_stack(b_stack);
		else if (*itr == PA)
			stack_push_from_b_to_a(a_stack, b_stack);
		else if (*itr == PB)
			stack_push_from_a_to_b(a_stack, b_stack);
		itr++;
	}
	ret = stack_is_sorted(a_stack) && stack_size(b_stack) == 0 ? 1 : 0;
	for (t_stki itr = init_stack_iterator(&itr, a_stack); !stack_iterator_end(&itr); init_stack_iterator(&itr, a_stack))
		stack_erase(itr.ptr, a_stack);
	for (t_stki itr = init_stack_iterator(&itr, b_stack); !stack_iterator_end(&itr); init_stack_iterator(&itr, b_stack))
		stack_erase(itr.ptr, b_stack);
	free(a_stack);
	free(b_stack);
	return (ret);
}

size_t ppow(int base, int power)
{
	size_t ret = 1;

	while (power > 0)
	{
		ret *= base;
		power--;
	}
	return (ret);
}

int	main(int ac, char **av)
{
	t_stk	main_stack;
	int		*tab;

	init_stack(&main_stack);
	for (int asd = 1; av[asd]; asd++)
		stack_push_back(ft_atoi(av[asd]), &main_stack);
	// stack_print(&main_stack);
	int i = 0;
	while (1)
	{
		PV(i, "%d\n");
		MALLOC(tab, i + 1);
		tab[i] = -1;
		int j = 0;
		while (j < i)
			tab[j++] = 0;
		size_t lim = ppow(11, i);
		for (size_t itr = 0; itr < lim; itr++)
		{
			if (apply_inst(tab, stack_duplicate(&main_stack)))
			{
				t_list *list = NULL;
				for (int k = 0; tab[k] + 1; k++)
					add_node((void*)(long)tab[k], &list);
				print_instructions(list);
				exit(0);
			}
			inc_tab(tab, i);
		}
		i++;
	}
}