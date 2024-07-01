/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:55:03 by joao-oli          #+#    #+#             */
/*   Updated: 2024/07/01 13:25:12 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_op_lint	stack_a;
	t_op_lint	stack_b;
	char		**arguments;
	int			total_len;

	(void)argc;
	stack_a = NULL;
	arguments = join_args(argv);
	if (arguments == NULL)
	{
		free(arguments);
		return (1);
	}
	stack_a = creates_stack(arguments);
	stack_b = NULL;
	total_len = list_len(stack_a);
	if (total_len == 2)
		stack_a = two_algorithm(stack_a);
	else if (total_len == 3)
		stack_a = three_algorithm(stack_a);
	else if (total_len > 1)
		push_swap(&stack_a, &stack_b);
	free_list(stack_a);
	free_list(stack_b);
	free_separations(arguments);
}
