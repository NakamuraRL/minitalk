/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:21:11 by grocha-l          #+#    #+#             */
/*   Updated: 2023/02/01 17:50:41 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_return(int nb)
{
	static int	cont;

	if (nb == 0)
		cont++;
	if (nb == 1)
		cont = 0;
	if (nb == -1)
		cont -= 1;
	if (nb != 0 && nb != 1 && nb != -1)
		cont += nb;
	return (cont);
}
