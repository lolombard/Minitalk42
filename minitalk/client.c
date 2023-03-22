/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:36:17 by llombard          #+#    #+#             */
/*   Updated: 2023/02/24 14:36:25 by llombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	process_bits(int sign, unsigned char str, int bits)
{
	if (bits < 7)
		process_bits(sign, str / 2, bits + 1);
	if (str % 2 == 1)
		kill(sign, SIGUSR1);
	else if (str % 2 == 0)
		kill(sign, SIGUSR2);
	usleep(25);
	return (0);
}

void	send_signal(int sign, unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		process_bits(sign, str[i], 0);
		i++;
	}
	process_bits(sign, 0, 0);
}

void	client_handler(int sign)
{
	if (sign == SIGUSR2)
		ft_printf("Messaggio ricevuto o mio oscuro signore\n");
	exit (0);
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, client_handler);
	signal(SIGUSR2, client_handler);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_signal(pid, (unsigned char *)av[2]);
	}
	else
	{
		ft_printf("please insert the following 3 arguments: \
				\n1) ./client\n2) PID server\n3) text\n_grazie e arrivederci_\n");
	}
	return (0);
}
