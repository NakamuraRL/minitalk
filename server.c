/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:19:24 by grocha-l          #+#    #+#             */
/*   Updated: 2023/02/01 18:09:50 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signo, siginfo_t *inf, void *v)
{
	char		c;
	static int	letter;
	static int	pow;
	static int	i;

	(void) inf;
	(void) v;
	if (i == 0)
		pow = 1;
	if (signo == SIGUSR2)
		letter += pow;
	pow *= 2;
	i++;
	if (i == 8)
	{
		c = letter;
		write(1, &c, 1);
		i = 0;
		letter = 0;
	}
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putnbr(-21474);
			ft_putnbr(83648);
			return ;
		}
		write (1, "-", 1);
		n = n * -1;
	}
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write (1, &n, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		n = n % 10 + '0';
		write (1, &n, 1);
	}
}

int	main(void)
{
	static struct sigaction	action = {0};
	int						pid;

	pid = getpid();
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
	ft_printf("PID: %i\n", pid);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
