/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:55:08 by joao-oli          #+#    #+#             */
/*   Updated: 2024/07/01 13:34:49 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_list(t_op_lint *nodo, char *str)
{
	t_op_lint	new_last;
	t_op_lint	head;

	if (*nodo == NULL)
	{
		*nodo = malloc(sizeof(struct double_nodo));
		(*nodo)->value = ft_atoi_check_l(str);
		(*nodo)->prev = NULL;
		(*nodo)->prox = NULL;
		return ;
	}
	head = *nodo;
	while ((*nodo)->prox != NULL)
		(*nodo) = (*nodo)->prox;
	new_last = malloc(sizeof(struct double_nodo));
	(*nodo)->prox = new_last;
	new_last->value = ft_atoi_check_l(str);
	new_last->prev = (*nodo);
	new_last->prox = NULL;
	(*nodo) = head;
}

// puts the args in a stack
t_op_lint	convert_args_to_op_lint(char **sections)
{
	int			i;
	t_op_lint	nodo;

	i = 0;
	nodo = NULL;
	while (sections[i])
	{
		append_list(&nodo, sections[i]);
		i++;
	}
	return (nodo);
}

// this function essentially creates the stack,...
// ...but, at the same time, verifies if the string is a...
// ...number or not. If not, it will free the sections and...
// ... call the error function
t_op_lint	creates_stack(char **sections)
{
	t_op_lint	stack_a;
	int			i;

	i = 0;
	stack_a = NULL;
	while (sections[i] != NULL)
	{
		if (!just_numbers(sections[i]))
		{
			free_separations(sections);
			error_function();
		}
		i++;
	}
	if (there_is_dup_numbers(sections))
	{
		free_separations(sections);
		error_function();
	}
	stack_a = convert_args_to_op_lint(sections);
	put_positions(stack_a);
	return (stack_a);
}

// frees the given list
void	free_list(t_op_lint nodo)
{
	t_op_lint	temp;

	while (nodo != NULL)
	{
		temp = nodo;
		nodo = nodo->prox;
		free(temp);
	}
}

int	is_sorted(t_op_lint nodo)
{
	while (nodo->prox != NULL)
	{
		if (nodo->value > nodo->prox->value)
			return (0);
		nodo = nodo->prox;
	}
	return (1);
}

/*
void print_list(t_op_lint nodo)
{
    while (nodo != NULL)
    {
        printf("%d\n", nodo->value);
        nodo = nodo->prox;
    }
}
*/
