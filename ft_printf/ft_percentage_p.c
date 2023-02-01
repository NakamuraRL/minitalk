/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentage_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:02:32 by grocha-l          #+#    #+#             */
/*   Updated: 2023/02/01 17:51:28 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percentage_p(long unsigned nbr)
{
	ft_putstr("0x");
	if (nbr == 0)
		ft_putchar('0');
	if (nbr >= 1)
		ft_putnbr_base(nbr, "0123456789abcdef");
}
