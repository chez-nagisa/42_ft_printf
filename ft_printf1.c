/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhara <nhara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:31:29 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 16:24:00 by nhara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		len += ft_putchar(*str);
		str++;
	}
	return (len);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	address;
	char				buffer[16];
	char				*base;
	int					i;
	int					count;

	address = (unsigned long long)ptr;
	base = "0123456789abcdef";
	i = 0;
	count = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	if (address == 0)
		return (count + ft_putchar('0'));
	while (address > 0)
	{
		buffer[i++] = base[address % 16];
		address /= 16;
	}
	while (i > 0)
		count += ft_putchar(buffer[--i]);
	return (count);
}

int	ft_putnbr(int n)
{
	char			buffer[11];
	int				i;
	unsigned int	num;
	int				count;

	if (n == 0)
		return (ft_putchar('0'));
	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
		num = (unsigned int)(-n);
	else
		num = (unsigned int)(n);
	if (n < 0)
		count += ft_putchar('-');
	i = 0;
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i > 0)
		count += ft_putchar(buffer[--i]);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	buffer[11];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
		count += ft_putchar(buffer[--i]);
	return (count);
}
