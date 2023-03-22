/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:36:43 by llombard          #+#    #+#             */
/*   Updated: 2023/02/24 14:37:04 by llombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_sigaction(int sig, siginfo_t *info, void *x)
{
	static int	i = 0;
	static int	y = 8;

	(void)x;
	if (sig == SIGUSR1)
		i = i << 1 | 1;
	else if (sig == SIGUSR2)
		i = i << 1 | 0;
	y--;
	if (y % 8 == 0)
	{
		if (i == 0)
		{
			kill(info->si_pid, SIGUSR2);
			ft_printf("\n");
		}
		ft_printf("%c", i);
		y = 8;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	siga;

	ft_printf("server PID is %d \n", getpid());
	siga.sa_flags = SA_SIGINFO;
	siga.sa_sigaction = server_sigaction;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
	{
	}
	return (0);
}
