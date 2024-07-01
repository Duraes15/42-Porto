/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:40:28 by joao-oli          #+#    #+#             */
/*   Updated: 2024/07/01 14:40:29 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pushes the first elem of n2 to the top of n1
void	push(t_op_lint *n1, t_op_lint *n2)
{
	t_op_lint	head;

	if (*n2 == NULL)
		return ;
	head = *n2;
	*n2 = (*n2)->prox;
	if (*n2 != NULL)
		(*n2)->prev = NULL;
	head->prox = *n1;
	if (*n1 != NULL)
		(*n1)->prev = head;
	*n1 = head;
}

void	pa(t_op_lint *stack_a, t_op_lint *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_op_lint *stack_a, t_op_lint *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
