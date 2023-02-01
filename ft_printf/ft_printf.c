/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:37:08 by grocha-l          #+#    #+#             */
/*   Updated: 2023/02/01 17:50:45 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_after_percentage(va_list ap, char c)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int));
	if (c == 's')
		ft_putstr(va_arg(ap, char *));
	if (c == 'p')
		ft_percentage_p(va_arg(ap, long unsigned));
	if (c == 'd')
		ft_putnbr(va_arg(ap, int));
	if (c == 'i')
		ft_putnbr(va_arg(ap, int));
	if (c == 'u')
		ft_uns_putnbr(va_arg(ap, unsigned int));
	if (c == 'x')
		ft_puthex(va_arg(ap, int), "0123456789abcdef");
	if (c == 'X')
		ft_puthex(va_arg(ap, int), "0123456789ABCDEF");
	if (c == '%')
		ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cont;
	int		ret;

	cont = 0;
	va_start(ap, str);
	while (str[cont] != '\0')
	{
		if (str[cont] == '%')
		{
			ft_after_percentage(ap, str[cont + 1]);
			cont += 2;
			continue ;
		}
		write(1, &str[cont], 1);
		ft_count_return(0);
		cont++;
	}
	va_end(ap);
	ret = ft_count_return(0) - 1;
	ft_count_return(1);
	return (ret);
}
