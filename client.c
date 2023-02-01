/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:28:01 by grocha-l          #+#    #+#             */
/*   Updated: 2023/02/01 17:56:53 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	long	cont;
	int		minus;
	long	ret;

	cont = 0;
	minus = 1;
	ret = 0;
	while (str[cont] == 32 || (str[cont] >= 9 && str[cont] <= 13))
		cont++;
	if (str[cont] == '+' || str[cont] == '-')
	{
		if (str[cont] == '-')
			minus *= -1;
		cont++;
	}
	while (str[cont] >= '0' && str[cont] <= '9')
	{
		ret = ret * 10 + (str[cont] - '0');
		cont++;
	}
	return (ret * minus);
}

void	ft_send_signal(int pid, char c)
{
	int	i;

	i = 8;
	while (i >= 1)
	{
		if (c % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		c /= 2;
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("You should pass as parameters the PID and a string!\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("The PID is not correct!\n");
		return (0);
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		ft_send_signal(pid, argv[2][i]);
		i++;
	}
}
