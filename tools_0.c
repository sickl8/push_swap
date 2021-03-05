/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:37:21 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/03 17:17:19 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_allowed.h"

size_t	ft_strlen(char *str)
{
	size_t	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

int		ft_putstr(int fd, char *str)
{
	return (write(fd, str, ft_strlen(str)));
}

int		o_puts(char *str)
{
	return (ft_putstr(STDOUT_FILENO, str));
}

int	e_puts(char *str)
{
	return (ft_putstr(STDERR_FILENO, str));
}

int	ft_atoi(const char *str)
{
	long i;
	long nbr;
	long sign;

	sign = 1;
	nbr = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\n' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = (str[i++] == '-' ? -1 : 1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((unsigned long)__LONG_MAX__ < (unsigned long)nbr * 10 + str[i] - 48
				&& sign == 1)
			return (-1);
		else if ((unsigned long)__LONG_MAX__ < (unsigned long)nbr * 10 + str[i]
				- 48 && sign == -1)
			return (0);
		nbr = nbr * 10 + str[i++] - 48;
	}
	return (nbr * sign);
}