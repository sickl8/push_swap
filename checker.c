/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:24:14 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/06 21:37:00 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exec(t_list *list, t_stk *a_stack, t_stk *b_stack, t_list *itr)
{
	long	co;

	itr = list;
	while (itr)
	{
		if (!ft_strcmp(itr->data, "sa") || !ft_strcmp(itr->data, "ss"))
			stack_swap(a_stack);
		if (!ft_strcmp(itr->data, "sb") || !ft_strcmp(itr->data, "ss"))
			stack_swap(b_stack);
		if (!ft_strcmp(itr->data, "ra") || !ft_strcmp(itr->data, "rr"))
			stack_rotate(a_stack);
		if (!ft_strcmp(itr->data, "rb") || !ft_strcmp(itr->data, "rr"))
			stack_rotate(b_stack);
		if (!ft_strcmp(itr->data, "rra") || !ft_strcmp(itr->data, "rrr"))
			stack_reverse_rotate(a_stack);
		if (!ft_strcmp(itr->data, "rrb") || !ft_strcmp(itr->data, "rrr"))
			stack_reverse_rotate(b_stack);
		else if (!ft_strcmp(itr->data, "pa"))
			stack_push_from_b_to_a(a_stack, b_stack);
		else if (!ft_strcmp(itr->data, "pb"))
			stack_push_from_a_to_b(a_stack, b_stack);
		itr = itr->next;
	}
	co = (stack_is_sorted(a_stack) && stack_size(b_stack) == 0);
	exit(0 * o_puts((char *)(co * (long)"OK\n" + !co * (long)"KO\n")));
}

int	check_line_sanity(char *s)
{
	if (!ft_strcmp(s, "sa") || !ft_strcmp(s, "sb")
		|| !ft_strcmp(s, "ss") || !ft_strcmp(s, "pa") || !ft_strcmp(s, "pb")
		|| !ft_strcmp(s, "ra") || !ft_strcmp(s, "rb") || !ft_strcmp(s, "rr")
		|| !ft_strcmp(s, "rra") || !ft_strcmp(s, "rrb") || !ft_strcmp(s, "rrr"))
		return (0);
	return (1);
}

t_list	*make_list(char *s)
{
	char	*tmp;
	t_list	*list;
	char	*orig;

	orig = s;
	list = NULL;
	while (*s)
	{
		tmp = s;
		tmp = ft_strchr(tmp, '\n');
		if (!tmp)
			error();
		*tmp = '\0';
		if (check_line_sanity(s))
			error();
		add_node(ft_strdup(s), &list);
		s = tmp + 1;
	}
	free(orig);
	return (list);
}

void	continue_main(t_stk *a_stack, t_stk *b_stack)
{
	int		gret;
	char	*line;
	char	*buf;
	char	*tmp;

	gret = 1;
	buf = ft_strdup("");
	while (gret > 0)
	{
		gret = get_next_line(&line);
		tmp = buf;
		buf = ft_strjoin(buf, line);
		free(tmp);
		free(line);
	}
	if (gret == -1)
		error();
	exec(make_list(buf), a_stack, b_stack, NULL);
}

int	main(int ac, char **av)
{
	t_stk	a_stack;
	t_stk	b_stack;
	int		i;

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
	continue_main(&a_stack, &b_stack);
	return (0);
}
