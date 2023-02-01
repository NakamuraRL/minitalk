/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:58:36 by grocha-l          #+#    #+#             */
/*   Updated: 2023/02/01 17:51:57 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putnbr(-21474);
			ft_putnbr(83648);
			return ;
		}
		write(1, "-", 1);
		ft_count_return(0);
		nb = nb * (-1);
	}
	if (nb >= 0 && nb <= 9)
	{
		nb = nb + '0';
		write(1, &nb, 1);
		ft_count_return(0);
	}
	else
	{
		ft_putnbr(nb / 10);
		nb = nb % 10 + '0';
		write(1, &nb, 1);
		ft_count_return(0);
	}
}
