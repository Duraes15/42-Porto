/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:47:12 by joao-oli          #+#    #+#             */
/*   Updated: 2024/07/01 14:47:13 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_lint	swap(t_op_lint nodo)
{
	t_op_lint	second;
	int			len;

	len = list_len(nodo);
	if (len < 2)
		return (nodo);
	second = nodo->prox;
	if (second->prox != NULL)
		second->prox->prev = nodo;
	nodo->prox = second->prox;
	second->prox = nodo;
	nodo->prev = second;
	second->prev = NULL;
	return (second);
}

t_op_lint	sa(t_op_lint stack_a)
{
	ft_printf("sa\n");
	return (swap(stack_a));
}

t_op_lint	sb(t_op_lint stack_b)
{
	ft_printf("sb\n");
	return (swap(stack_b));
}

void	double_swap(t_op_lint *stack_a, t_op_lint *stack_b)
{
	*stack_a = sa(*stack_a);
	*stack_b = sb(*stack_b);
	ft_printf("ss\n");
}
