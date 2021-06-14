/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_proto.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:40:52 by isaadi            #+#    #+#             */
/*   Updated: 2021/06/14 19:01:08 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PROTO_H
# define HEADER_PROTO_H

# include "header_typedef.h"
# include <stddef.h>

int		ft_putnbr(long n);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
void	ft_memset(char *s, char c, size_t len);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
long	ft_abs(long x);
void	*wrap_malloc(size_t bytes);
int		check_sanity(char *s);
int		o_puts(char *str);
int		e_puts(char *str);
void	sort_tab(int *tab, int len);
int		init_stack(t_stk *stack);
t_stki	init_stack_iterator(t_stki *itr, t_stk *stack);
int		stack_iterator_end(t_stki *itr);
int		stack_iterator_advance(t_stki *itr);
int		stack_iterator_regress(t_stki *itr);
t_clt	*stack_member(int needle, t_stk *stack);
void	stack_push_back(int data, t_stk *stack);
void	stack_push_front(int data, t_stk *stack);
int		stack_size(t_stk *stack);
int		add_node(void *data, t_list **list);
void	error(void);
int		ft_isdigit(char c);
void	stack_erase(t_clt *member, t_stk *stack);
int		stack_swap(t_stk *stack);
void	stack_rotate(t_stk *stack);
void	stack_reverse_rotate(t_stk *stack);
void	stack_push_from_to(t_stk *a_stack, t_stk *b_stack);
int		stack_is_sorted(t_stk *stack);
void	stack_print(t_stk *stack, char sep);
void	stack_print_from_anchor(t_stk *stack, char sep);
void	double_stack_print(t_stk *a_stack, t_stk *b_stack);
void	stack_push_from_a_to_b(t_stk *a, t_stk *b);
void	stack_push_from_b_to_a(t_stk *a, t_stk *b);
int		stack_member_index_p(t_clt *member, t_stk *stack);
int		stack_member_index(int data, t_stk *stack);
int		stack_reach_member(int member, int stk, t_stk *stack, t_list **inst);
t_stk	*stack_duplicate(t_stk *stack);
int		print_instructions(t_list *instructions, char sep);
void	print_instructions_s(t_list *instructions);
t_clt	*smallest_member(t_stk *stack);
t_clt	*biggest_member(t_stk *stack);
size_t	list_len(t_list *list);
int		evaluate_tab(int *tab, size_t len, size_t stack_len);
long	ft_min(long x, long y);
long	ft_max(long x, long y);
int		stack_reach_closest_member(int m1, int m2, t_stk *stack, t_list **inst);
t_list	*algo_0(t_stk *a_stack, t_stk *b_stack);
t_list	*algo_1(t_stk *a_stack);
t_list	*algo_2(t_stk *a_stack);
t_list	*algo_3(t_stk *a, t_stk *b);
int		stack_is_kinda_sorted(t_stk *stack);
int		stack_score(t_stk *stack);
t_list	*algo_4(t_stk *a_stk, t_stk *b_stk);
int		*to_tab(t_stk *stack);
int		stack_destroy(t_stk *stack, int fp);
void	swap_a(t_stk **stacks);
void	swap_b(t_stk **stacks);
void	swap_s(t_stk **stacks);
void	push_a(t_stk **stacks);
void	push_b(t_stk **stacks);
void	rotate_a(t_stk **stacks);
void	rotate_b(t_stk **stacks);
void	rotate_r(t_stk **stacks);
void	rrotate_a(t_stk **stacks);
void	rrotate_b(t_stk **stacks);
void	rrotate_r(t_stk **stacks);
int		stack_distance(int a, int b, t_stk *stack);
int		stack_shortest_distance(long a, long b, t_stk *stk);
void	apply_inst(t_stk *a_stack, t_stk *b_stack, int inst);
void	stack_move_x_steps(int index, int stk, t_stk **stacks, t_list **lst);
int		apply_and_push(long inst, t_list **lst, t_stk *a, t_stk *b);
long	sign(long x);
int		sa(t_inf i, int *len, t_cell cell, int *inc);
int		sb(t_inf i, int *len, t_cell cell, int *inc);
int		ss(t_inf i, int *len, t_cell cell, int *inc);
int		pb(t_inf i, int *len, t_cell cell, int *inc);
int		ra(t_inf i, int *len, t_cell cell, int *inc);
int		rb(t_inf i, int *len, t_cell cell, int *inc);
int		rr(t_inf i, int *len, t_cell cell, int *inc);
int		rra(t_inf i, int *len, t_cell cell, int *inc);
int		rrb(t_inf i, int *len, t_cell cell, int *inc);
int		rrr(t_inf i, int *len, t_cell cell, int *inc);
long	stack_closest_member_in_range(int a, int b, t_stk *stk);
t_bf	get_pool(t_inf i, t_cell cell);
int		crif(int inst, t_cell *cell);
int		rif(t_stk *a, t_stk *b, t_inf in, t_cell cell);
void	brute_force(t_stk *a_stack, t_stk *b_stack, char **g_cor);
int		apply_inst_lst(t_stk *a_stack, t_stk *b_stack, int *inst, int len);
void	*as(void *a, long v, int size);
int		free_list(t_list *lst);
void	sorted(t_stk *a_stack);

#endif
