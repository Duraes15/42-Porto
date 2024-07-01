/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_equal_than_3_algorithm.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:40:16 by joao-oli          #+#    #+#             */
/*   Updated: 2024/07/01 14:40:16 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_lint	two_algorithm(t_op_lint stack_a)
{
	if (stack_a->value > stack_a->prox->value)
		stack_a = sa(stack_a);
	return (stack_a);
}

t_op_lint	three_algorithm(t_op_lint stack_a)
{
	if (biggest_node(stack_a) == stack_a)
		stack_a = ra(stack_a);
	if (biggest_node(stack_a) == stack_a->prox)
		stack_a = rra(stack_a);
	if (stack_a->value > stack_a->prox->value)
		stack_a = sa(stack_a);
	return (stack_a);
}
