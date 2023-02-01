/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:52:37 by grocha-l          #+#    #+#             */
/*   Updated: 2023/02/01 17:52:01 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uns_putnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb < 10)
		i += ft_putchar(nb + '0');
	else
	{
		i += ft_uns_putnbr(nb / 10);
		i += ft_uns_putnbr(nb % 10);
	}
	return (i);
}
