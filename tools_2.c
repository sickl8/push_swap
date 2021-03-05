/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sickl8 <sickl8@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:26:32 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/06 00:51:12 by sickl8           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strchr(const char *s, int c)
{
	char a;
	char *z;

	z = (char*)s;
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

void	ft_putnbr(int n)
{
	long nb;
	long p;
	char c;

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
}

int		check_sanity(char *s)
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
	if (ft_strlen(s + (s[0] == '-')) == 10 &&
		((sign == 1 && ft_strcmp(s, "2147483647") > 0)
		|| (sign == -1 && ft_strcmp(s + 1, "2147483648") > 0)))
		return (1);
	s += (s[0] == '-');
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (1 + 0 * HERE);
	return (0);
}

void	print_instructions(t_list *instructions)
{
	char **cor;
	
	cor = (char*[])
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	while (instructions)
	{
		o_puts(cor[(long)instructions->data]);
		o_puts("\n");
		instructions = instructions->next;
	}
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