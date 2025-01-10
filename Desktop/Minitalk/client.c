/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 05:40:46 by natrodri          #+#    #+#             */
/*   Updated: 2025/01/10 06:49:40 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	send_signal(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (((c >> i) & 1))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("error send bit\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("error send bit\n");
				exit(1);
			}
		}
		usleep(1000);
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		if (ft_atoi(av[1]))
		{
			while (av[2][i])
				send_signal(ft_atoi(av[1]), av[2][i++]);
			send_signal(ft_atoi(av[1]), '\0');
		}
	}
	else
		ft_printf("necessary: [PID] and [MENSAGE]\n");
}
