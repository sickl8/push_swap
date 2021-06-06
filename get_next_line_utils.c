/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:11:02 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/06 19:55:29 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fs(const char *s, int c)
{
	char	a;
	char	*z;

	if (!s)
		return (NULL);
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

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!s1)
		return ((char *)s1);
	while (s1[i])
		i++;
	rtn = wrap_malloc(i + 1);
	if (rtn == NULL)
		return (NULL);
	while (i >= 0)
	{
		rtn[i] = s1[i];
		i--;
	}
	return (rtn);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i;

	if (!s)
		return (NULL);
	if (len > ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	if (start > ft_strlen((char *)s))
		start = ft_strlen((char *)s);
	i = 0;
	rtn = (char *)malloc(sizeof(char) * len + 1);
	if (rtn == NULL)
		return (NULL);
	while (i < len)
	{
		rtn[i] = s[start];
		start++;
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = -1;
	j = ft_strlen(s1);
	k = ft_strlen(s2);
	tmp = (char *)wrap_malloc(sizeof(char) * (j + k + 1));
	if (tmp == NULL || (char *)s2 == NULL)
		return (NULL);
	while (++i < j)
		tmp[i] = s1[i];
	i = -1;
	while (++i <= k)
		tmp[i + j] = s2[i];
	return (tmp);
}
