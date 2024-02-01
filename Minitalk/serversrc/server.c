/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:15:29 by joao-oli          #+#    #+#             */
/*   Updated: 2024/02/01 12:50:10 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_bits[8];

char	*ft_realloc(char *str, int c, int len)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[len] = c;
	free(str);
	return (new_str);
}

void	deal_str(int c, int client_pid)
{
	static char	*str;
	static int	nmbr_chars;

	if (!nmbr_chars)
		nmbr_chars = 0;
	if (!str)
	{
		str = malloc(sizeof(char));
		str[0] = c;
	}
	else
		str = ft_realloc(str, c, nmbr_chars);
	if (c == '\0')
	{
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
		nmbr_chars = 0;
		kill(client_pid, SIGUSR2);
	}
	else
		nmbr_chars++;
}

int	convert_to_char(void)
{
	int	c;

	c = (128 * g_bits[0]) + (64 * g_bits[1]) + (32 * g_bits[2]);
	c += (16 * g_bits[3]) + (8 * g_bits[4]) + (4 * g_bits[5]);
	c += (2 * g_bits[6]) + g_bits[7];
	return (c);
}

void	handle_signal(int sig, siginfo_t *info, void *storage)
{
	int			sinal_recebido;
	static int	i;
	static int	client_pid;

	(void)storage;
	client_pid = info->si_pid;
	if (!i)
		i = 0;
	if (i < 8)
	{
		if (sig == SIGUSR1)
			sinal_recebido = 0;
		else
			sinal_recebido = 1;
		g_bits[i] = sinal_recebido;
		i++;
		if (i == 8)
		{
			deal_str(convert_to_char(), client_pid);
			i = 0;
		}
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID = %d\n", getpid());
	while (1)
	{
		sa.sa_sigaction = handle_signal;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
}
