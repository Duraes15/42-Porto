/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:55:06 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/30 17:31:22 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_positions(t_op_lint node)
{
	int	i;
	int	len;

	i = 0;
	len = list_len(node);
	while (node != NULL)
	{
		node->current_position = i;
		if (i <= len / 2)
			node->above_median = 1;
		else
			node->above_median = 0;
		node = node->prox;
		i++;
	}
}

t_op_lint	biggest_node(t_op_lint nodo)
{
	t_op_lint	biggest;

	if (nodo == NULL)
		return (nodo);
	biggest = nodo;
	nodo = nodo->prox;
	while (nodo != NULL)
	{
		if (biggest->value < nodo->value)
			biggest = nodo;
		nodo = nodo->prox;
	}
	return (biggest);
}

t_op_lint	smallest_node(t_op_lint nodo)
{
	t_op_lint	smallest;

	if (nodo == NULL)
		return (nodo);
	smallest = nodo;
	nodo = nodo->prox;
	while (nodo != NULL)
	{
		if (smallest->value > nodo->value)
			smallest = nodo;
		nodo = nodo->prox;
	}
	return (smallest);
}

// this function will be called when the input is wrong
void	error_function(void)
{
	ft_printf("Error\n");
	exit(0);
}

// returns the length of the given list
int	list_len(t_op_lint lista)
{
	int	len;

	len = 0;
	while (lista != NULL)
	{
		lista = lista->prox;
		len++;
	}
	return (len);
}
