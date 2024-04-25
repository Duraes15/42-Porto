/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:12:07 by joao-oli          #+#    #+#             */
/*   Updated: 2024/03/23 17:09:27 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_j = 8;

void	print_finish(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("String recebida pelo server\n");
	}
}

void	send_bits(int c, int pid)
{
	int	bits[8];

	signal(SIGUSR1, print_finish);
	signal(SIGUSR2, print_finish);
	while (g_j > 0)
	{
		if (c % 2 == 0)
			bits[g_j - 1] = 0;
		else
			bits[g_j - 1] = 1;
		c /= 2;
		g_j--;
	}
	while (g_j < 8)
	{
		if (bits[g_j] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		g_j++;
		usleep(20);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3 || ft_atoi(argv[1]) == 0)
	{
		ft_printf("Invalid parameters!");
		exit(0);
	}
	signal(SIGUSR2, print_finish);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_bits((int)argv[2][i], pid);
		i++;
	}
	send_bits('\0', pid);
}
