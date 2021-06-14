/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:26:32 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/08 19:14:48 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*z;

	z = (char *)s;
	a = (char)c;
	while (*z)
	{
		if (*z == a)
			return (z);
		z++;
	}
	if (a == '\0')
		return (z);
	return (0);
}

int	ft_putnbr(long n)
{
	long	nb;
	long	p;
	char	c;

	nb = (long)n;
	p = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while (p * 10 <= nb)
		p *= 10;
	while (p > 0)
	{
		c = (nb / p) % 10 + 48;
		write(1, &c, 1);
		p /= 10;
	}
	return (1);
}

int	check_sanity(char *s)
{
	int	i;
	int	sign;

	i = -1;
	sign = (s[0] != '-') * 1 + (s[0] == '-') * (-1);
	if (s[(s[0] == '-')] == '\0')
		return (1);
	if (s[(s[0] == '-')] == '0' && ft_strlen(s) > 1)
		return (1);
	if (ft_strlen(s) > 10 + (s[0] == '-'))
		return (1);
	if (ft_strlen(s + (s[0] == '-')) == 10
		&& ((sign == 1 && ft_strcmp(s, "2147483647") > 0)
			|| (sign == -1 && ft_strcmp(s + 1, "2147483648") > 0)))
		return (1);
	s += (s[0] == '-');
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (1);
	return (0);
}

int	print_instructions(t_list *instructions, char sep)
{
	char	**cor;

	cor = (char *[])
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	while (instructions)
	{
		o_puts(cor[(long)instructions->data]);
		o_puts((char []){sep, '\0'});
		instructions = instructions->next;
	}
	if (sep != '\n')
		o_puts("\n");
	return (1);
}

void	print_instructions_s(t_list *instructions)
{
	while (instructions)
	{
		o_puts(instructions->data);
		o_puts("\n");
		instructions = instructions->next;
	}
}
