/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_proto.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:40:52 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/05 17:23:21 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PROTO_H
# define HEADER_PROTO_H

# include "header_typedef.h"
# include <stddef.h>

void	ft_putnbr(int n);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
void	*wrap_malloc(size_t bytes);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		check_sanity(char *s);
int		o_puts(char *str);
int		e_puts(char *str);
int		init_stack(t_stk *stack);
int		init_stack_iterator(t_stki *itr, t_stk *stack);
int		stack_iterator_end(t_stki *itr);
int		stack_iterator_advance(t_stki *itr);
t_clt	*stack_member(int needle, t_stk *stack);
void	stack_push_back(int data, t_stk *stack);
void	stack_push_front(int data, t_stk *stack);
int		stack_size(t_stk *stack);
void	add_node(void *data, t_list **list);
void	error(void);
int		ft_isdigit(char c);
void	stack_erase(t_clt *member, t_stk *stack);
void	stack_swap(t_stk *stack);
void	rotate_stack(t_stk *stack);
void	reverse_rotate_stack(t_stk *stack);
void	stack_push_from_to(t_stk *a_stack, t_stk *b_stack);
int		stack_is_sorted(t_stk *stack);
void	stack_print(t_stk *stack);
void	double_stack_print(t_stk *a_stack, t_stk *b_stack);
void	stack_push_from_a_to_b(t_stk *a, t_stk *b);
void	stack_push_from_b_to_a(t_stk *a, t_stk *b);
int		stack_member_index_p(t_clt *member, t_stk *stack);
int		stack_member_index(int data, t_stk *stack);

#endif