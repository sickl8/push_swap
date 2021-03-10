/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_typedef.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:43:00 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/10 14:51:06 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_TYPEDEF_H
# define HEADER_TYPEDEF_H

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

typedef struct	s_clt
{
	int				data;
	struct s_clt	*next;
	struct s_clt	*prev;
}				t_clt;

typedef struct	s_stk
{
	t_clt	*anchor;
	t_clt	*list;
	long	length;
}				t_stk;

typedef struct	s_stki
{
	t_clt	*ptr;
	t_stk	*stk;
	long	index;
}				t_stki;

typedef struct	s_tmp0
{
	int		a;
	int		b;
}				t_tmp0;

#endif