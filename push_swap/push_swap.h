/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:06:48 by joao-oli          #+#    #+#             */
/*   Updated: 2024/07/01 15:29:54 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft_printf/libft.h"

typedef struct double_nodo
{
	int						value;
	int						current_position;
	int						moves;
	int						above_median; // -1 its false, 1 is true
	struct double_nodo		*target;
	struct double_nodo		*prox;
	struct double_nodo		*prev;
}	*t_op_lint;

void		append_list(t_op_lint *nodo, char *str);
void		rotate_while_able(t_op_lint *stack_a, t_op_lint *stack_b, \
								t_op_lint cheap, int flag);
t_op_lint	convert_args_to_op_lint(char **sections);
t_op_lint	creates_stack(char **sections);
void		free_list(t_op_lint nodo);
t_op_lint	reverse_rotate(t_op_lint nodo);
t_op_lint	rra(t_op_lint nodo);
t_op_lint	rrb(t_op_lint nodo);
void		rrr(t_op_lint *n1, t_op_lint *n2);
void		free_separations(char **separations);
long		ft_atoi_check_l(const char *nptr);
int			just_numbers(char *str);
char		**join_args(char **argv);
void		error_function(void);
int			there_is_dup_numbers(char **sections);
t_op_lint	rotate(t_op_lint nodo);
t_op_lint	ra(t_op_lint nodo);
t_op_lint	rb(t_op_lint nodo);
void		rr(t_op_lint *n1, t_op_lint *n2);
void		push(t_op_lint *n1, t_op_lint *n2);
void		pa(t_op_lint *stack_a, t_op_lint *stack_b);
void		pb(t_op_lint *stack_a, t_op_lint *stack_b);
int			list_len(t_op_lint lista);
t_op_lint	swap(t_op_lint nodo);
t_op_lint	sa(t_op_lint stack_a);
t_op_lint	sb(t_op_lint stack_b);
void		double_swap(t_op_lint *stack_a, t_op_lint *stack_b);
t_op_lint	biggest_node(t_op_lint nodo);
t_op_lint	smallest_node(t_op_lint nodo);
t_op_lint	two_algorithm(t_op_lint stack_a);
t_op_lint	three_algorithm(t_op_lint stack_a);
void		put_positions(t_op_lint node);
void		put_targets(t_op_lint stack_a, t_op_lint stack_b);
void		put_moves(t_op_lint n1, t_op_lint n2);
void		push_swap(t_op_lint *stack_a, t_op_lint *stack_b);
int			maior(int a, int b);
t_op_lint	find_cheapest(t_op_lint node);
void		separated_moves(t_op_lint *stack_a, \
							t_op_lint *stack_b, t_op_lint cheapest_b);
void		make_moves(t_op_lint *stack_a, t_op_lint *stack_b, t_op_lint cheap);
int			is_sorted(t_op_lint nodo);
// void print_list(t_op_lint nodo);
