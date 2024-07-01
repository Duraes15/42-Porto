/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:36:43 by joao-oli          #+#    #+#             */
/*   Updated: 2024/07/01 14:36:45 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function will do the necessary moves in order to put the numbers sorted
// in the stack A
void	make_moves(t_op_lint *stack_a, t_op_lint *stack_b, t_op_lint cheap)
{
	while (*stack_b != cheap || *stack_a != cheap->target)
	{
		if (*stack_a != cheap->target && *stack_b != cheap)
		{
			if (cheap->above_median && cheap->target->above_median)
				rotate_while_able(stack_a, stack_b, cheap, 0);
			else if (!cheap->above_median && !cheap->target->above_median)
				rotate_while_able(stack_a, stack_b, cheap, 1);
		}
		if (*stack_a != cheap->target)
		{
			if (cheap->target->above_median)
				*stack_a = ra(*stack_a);
			else
				*stack_a = rra(*stack_a);
		}
		if (*stack_b != cheap)
		{
			if (cheap->above_median)
				*stack_b = rb(*stack_b);
			else
				*stack_b = rrb(*stack_b);
		}
	}
	pa(stack_a, stack_b);
}

// here, we already have the values at B and the first 3 elems of A are sorted
void	put_targets(t_op_lint stack_a, t_op_lint stack_b)
{
	t_op_lint	node;
	long		smallest_bigger;

	while (stack_b != NULL)
	{
		smallest_bigger = 2247483647;
		node = stack_a;
		while (node != NULL)
		{
			if (node->value > stack_b->value && node->value < smallest_bigger)
			{
				smallest_bigger = node->value;
				stack_b->target = node;
			}
			node = node->prox;
		}
		if (smallest_bigger == 2247483647)
			stack_b->target = smallest_node(stack_a);
		stack_b = stack_b->prox;
	}
}

void	put_moves(t_op_lint n1, t_op_lint n2)
{
	int	len;

	len = list_len(n2);
	while (n2 != NULL)
	{
		if (n2->above_median)
			n2->moves = n2->current_position;
		else
			n2->moves = len - n2->current_position;
		if (n2->target->above_median)
			n2->moves += n2->target->current_position;
		else
			n2->moves += (list_len(n1) - n2->target->current_position);
		n2 = n2->prox;
	}
}

void	final_sorting(t_op_lint *stack_a)
{
	t_op_lint	smallest;

	put_positions(*stack_a);
	smallest = smallest_node(*stack_a);
	while (smallest != *stack_a)
	{
		if (smallest->above_median == -1)
			*stack_a = rra(*stack_a);
		else
			*stack_a = ra(*stack_a);
	}
}

// will be called only if there are more than 3 elems initially at stack_a 
void	push_swap(t_op_lint *stack_a, t_op_lint *stack_b)
{
	t_op_lint	cheapest_b;

	if (is_sorted(*stack_a))
		return ;
	while (list_len(*stack_a) > 3)
		pb(stack_a, stack_b);
	*stack_a = three_algorithm(*stack_a);
	while (*stack_b != NULL)
	{
		put_positions(*stack_a);
		put_positions(*stack_b);
		put_targets(*stack_a, *stack_b);
		put_moves(*stack_a, *stack_b);
		cheapest_b = find_cheapest(*stack_b);
		make_moves(stack_a, stack_b, cheapest_b);
	}
	put_positions(*stack_a);
	final_sorting(stack_a);
}
