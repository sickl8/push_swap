/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_typedef.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:43:00 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/02 16:34:54 by isaadi           ###   ########.fr       */
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
	long			data;
	struct s_clt	*next;
	struct s_clt	*prev;
}				t_clt;

typedef struct	s_stk
{
	t_clt	*anchor;
	t_clt	*list;
	long	length;
	void	(*tab[11])(struct s_stk**);
}				t_stk;

typedef struct	s_stki
{
	t_clt	*ptr;
	t_stk	*stk;
	long	data;
	long	index;
}				t_stki;

typedef t_stki t_itr[1];

typedef struct	s_tmp0
{
	long	member;
	long	steps;
}				t_tmp0;

typedef struct	s_bf
{
	unsigned int		bf;
	int					ones;
}				t_bf;

typedef struct	s_ro
{
	int		cra;
	int		crb;
	int		crra;
	int		crrb;
}				t_ro;

typedef struct	s_cell
{
	int		pa;
	int		pb;
	t_ro	ro;
}				t_cell;

typedef struct timeval tv;

#endif