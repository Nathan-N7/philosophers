/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 05:52:11 by natrodri          #+#    #+#             */
/*   Updated: 2025/01/10 06:05:33 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "printf/ft_printf.h"
#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static int	g_c = 0;

void	stoc(int signum)
{
	static int	i = 0;

	g_c = g_c << 1;
	if (signum == SIGUSR1)
		g_c = g_c + 1;
	i++;
	if (i == 8)
	{
		write(1, &g_c, 1);
		if (g_c == '\0')
			write(1, "\n", 1);
		i = 0;
		g_c = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, stoc);
	signal(SIGUSR2, stoc);
	ft_printf("███████╗███████╗██████╗ ██╗   ██╗███████╗██████╗ \n");
	ft_printf("██╔════╝██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗\n");
	ft_printf("███████╗█████╗  ██████╔╝██║   ██║█████╗  ██████╔╝\n");
	ft_printf("╚════██║██╔══╝  ██╔══██╗╚██╗ ██╔╝██╔══╝  ██╔══██╗\n");
	ft_printf("███████║███████╗██║  ██║ ╚████╔╝ ███████╗██║  ██║\n");
	ft_printf("╚══════╝╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝\n\n");
	ft_printf("Server PID = %d\n", getpid());
	while (1)
		pause();
	return (0);
}
