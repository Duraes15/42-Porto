/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:50:29 by joao-oli          #+#    #+#             */
/*   Updated: 2024/07/01 15:05:59 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maior(int a, int b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

t_op_lint	find_cheapest(t_op_lint node)
{
	t_op_lint	cheapest;

	if (node == NULL)
		return (NULL);
	cheapest = node;
	while (node != NULL)
	{
		if (node->moves < cheapest->moves)
			cheapest = node;
		node = node->prox;
	}
	return (cheapest);
}

// ele quando chegar aqui, significa que nenhum deles tem o above_median a 0
void	separated_moves(t_op_lint *stack_a, t_op_lint *stack_b,
		t_op_lint cheapest_b)
{
	if (*stack_b != cheapest_b)
	{
		if (cheapest_b->above_median == 1)
			*stack_b = rb(*stack_b);
		else
			*stack_b = rrb(*stack_b);
	}
	if (*stack_a != cheapest_b->target)
	{
		if (cheapest_b->target->above_median == 1)
			*stack_a = ra(*stack_a);
		else
			*stack_a = rra(*stack_a);
	}
}

void	rotate_while_able(t_op_lint *stack_a,
			t_op_lint *stack_b, t_op_lint cheap, int flag)
{
	if (!flag)
	{
		while (*stack_a != cheap->target && *stack_b != cheap)
		{
			rr(stack_a, stack_b);
		}
	}
	else
	{
		while (*stack_a != cheap->target && *stack_b != cheap)
		{
			rrr(stack_a, stack_b);
		}
	}
}
