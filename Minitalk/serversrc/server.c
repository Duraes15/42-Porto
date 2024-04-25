/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:19:09 by joao-oli          #+#    #+#             */
/*   Updated: 2024/03/23 17:08:58 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_i;

int	ft_pow(int base, int exp)
{
	int	i;
	int	value;

	i = 0;
	value = 1;
	while (i++ < exp)
		value *= base;
	return (value);
}

void	handle_signal(int sig, siginfo_t *info, void *storage)
{
	static int	client_pid;
	static char	char_value;

	(void)storage;
	client_pid = info->si_pid;
	(void)client_pid;
	if (g_i == 0)
		char_value = 0;
	if (sig == SIGUSR2)
		char_value += ft_pow(2, 7 - g_i);
	g_i++;
	if (g_i == 8)
	{
		g_i = 0;
		write(1, &char_value, 1);
	}
	if (char_value == 0 && g_i == 0)
	{
		write(1, "\n", 1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID = %d\n", getpid());
	g_i = 0;
	while (1)
	{
		sa.sa_sigaction = handle_signal;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
}
