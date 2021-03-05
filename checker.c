/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:24:14 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/05 17:26:36 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define PV(x, y) printf("%s = " y, #x, x)

void	exec(t_list *list, t_stk *a_stack, t_stk *b_stack)
{
	t_list *itr;

	itr = list;
	#ifdef DEBUG
	// o_puts("\033[2J;");
	o_puts("\n");
	double_stack_print(a_stack, b_stack);
	o_puts("- -\n");
	o_puts("a b\n");
	o_puts("-------------------------------\n");
	#endif
	while (itr)
	{
		if (!ft_strcmp(itr->data, "sa") || !ft_strcmp(itr->data, "ss"))
			stack_swap(a_stack);
		if (!ft_strcmp(itr->data, "sb") || !ft_strcmp(itr->data, "ss"))
			stack_swap(b_stack);
		if (!ft_strcmp(itr->data, "ra") || !ft_strcmp(itr->data, "rr"))
			rotate_stack(a_stack);
		if (!ft_strcmp(itr->data, "rb") || !ft_strcmp(itr->data, "rr"))
			rotate_stack(b_stack);
		if (!ft_strcmp(itr->data, "rra") || !ft_strcmp(itr->data, "rrr"))
			reverse_rotate_stack(a_stack);
		if (!ft_strcmp(itr->data, "rrb") || !ft_strcmp(itr->data, "rrr"))
			reverse_rotate_stack(b_stack);
		else if (!ft_strcmp(itr->data, "pa"))
			stack_push_from_b_to_a(a_stack, b_stack);
		else if (!ft_strcmp(itr->data, "pb"))
			stack_push_from_a_to_b(a_stack, b_stack);
		#ifdef DEBUG
		double_stack_print(a_stack, b_stack);
		o_puts("- -\n");
		o_puts("a b\n");
		o_puts("-------------------------------\n");
		#endif
		itr = itr->next;
	}
	o_puts(stack_is_sorted(a_stack) && stack_size(b_stack) == 0 ?
	"OK\n" : "KO\n");
	exit(0);
}

int		check_line_sanity(char *s)
{
	char	*tmp;

	tmp = ft_strchr(s, '\n');
	if (tmp && tmp[1] == '\0')
		*tmp = '\0';
	if (!ft_strcmp(s, "sa") || !ft_strcmp(s, "sb")
		|| !ft_strcmp(s, "ss") || !ft_strcmp(s, "pa") || !ft_strcmp(s, "pb")
		|| !ft_strcmp(s, "ra") || !ft_strcmp(s, "rb") || !ft_strcmp(s, "rr")
		|| !ft_strcmp(s, "rra") || !ft_strcmp(s, "rrb") || !ft_strcmp(s, "rrr"))
		return (0);
	return (1);
}

void	continue_main(t_stk *a_stack, t_stk *b_stack)
{
	int		gret;
	char	*line;
	t_list	*list;

	gret = 1;
	list = NULL;
	while (gret > 0)
	{
		gret = get_next_line(&line);
		if (!ft_strcmp(line, ""))
		{
			free(line);
			break ;
		}
		if (gret != -1 && !check_line_sanity(line))
			add_node(line, &list);
		else
			error();
	}
	exec(list, a_stack, b_stack);
}

int		main(int ac, char **av)
{
	t_stk	a_stack;
	t_stk	b_stack;
	int		i;

	init_stack(&a_stack) && init_stack(&b_stack);
	if (ac == 1)
		return (0);
	i = 0;
	while (av[++i])
	{
		if (check_sanity(av[i]) || stack_member(ft_atoi(av[i]), &a_stack))
			error();
		stack_push_back(ft_atoi(av[i]), &a_stack);
	}
	continue_main(&a_stack, &b_stack);
	return (0);
}
