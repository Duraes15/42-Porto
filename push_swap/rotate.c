/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:58:30 by joao-oli          #+#    #+#             */
/*   Updated: 2024/07/01 12:29:39 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_lint	rotate(t_op_lint nodo)
{
	t_op_lint	head;
	t_op_lint	second;

	if (nodo == NULL || nodo->prox == NULL)
		return (nodo);
	head = nodo;
	nodo = nodo->prox;
	second = nodo;
	while (nodo->prox != NULL)
		nodo = nodo->prox;
	second->prev = NULL;
	head->prox = NULL;
	head->prev = nodo;
	nodo->prox = head;
	return (second);
}

t_op_lint	ra(t_op_lint nodo)
{
	nodo = rotate(nodo);
	ft_printf("ra\n");
	return (nodo);
}

t_op_lint	rb(t_op_lint nodo)
{
	nodo = rotate(nodo);
	ft_printf("rb\n");
	return (nodo);
}

void	rr(t_op_lint *n1, t_op_lint *n2)
{
	*n1 = rotate(*n1);
	*n2 = rotate(*n2);
	ft_printf("rr\n");
}
