/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:56:07 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/30 18:14:46 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_lint	reverse_rotate(t_op_lint nodo)
{
	t_op_lint	head;

	if (nodo == NULL || nodo->prox == NULL)
		return (nodo);
	head = nodo;
	while (nodo->prox != NULL)
		nodo = nodo->prox;
	nodo->prox = head;
	head->prev = nodo;
	nodo->prev->prox = NULL;
	nodo->prev = NULL;
	return (nodo);
}

t_op_lint	rra(t_op_lint nodo)
{
	nodo = reverse_rotate(nodo);
	ft_printf("rra\n");
	return (nodo);
}

t_op_lint	rrb(t_op_lint nodo)
{
	nodo = reverse_rotate(nodo);
	ft_printf("rrb\n");
	return (nodo);
}

void	rrr(t_op_lint *n1, t_op_lint *n2)
{
	*n1 = reverse_rotate(*n1);
	*n2 = reverse_rotate(*n2);
	ft_printf("rrr\n");
}
