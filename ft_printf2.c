/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhara <nhara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:46:07 by nhara             #+#    #+#             */
/*   Updated: 2025/01/22 15:36:21 by nhara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n, int uppercase)
{
	char	buffer[9];
	char	*base;
	int		i;
	int		count;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	while (i > 0)
		count += ft_putchar(buffer[--i]);
	return (count);
}

int	handle_specifier(char specifier, va_list args)
{
	if (specifier == '%')
		return (ft_putchar('%'));
	else if (specifier == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 1));
	return (ft_putchar(specifier));
}

int	handle_format(const char *format, va_list args)
{
	int	printed_chars;

	printed_chars = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed_chars += handle_specifier(*format, args);
		}
		else
			printed_chars += ft_putchar(*format);
		format++;
	}
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;

	va_start(args, format);
	printed_chars = handle_format(format, args);
	va_end(args);
	return (printed_chars);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int *ptr;

// 	int ret1, ret2;
// 	// string
// 	ret1 = printf("Hello, World!\n");
// 	ret2 = ft_printf("Hello, World!\n");
// 	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);
// 	// %c
// 	ret1 = printf("Character: %c\n", 'A');
// 	ret2 = ft_printf("Character: %c\n", 'A');
// 	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);
// 	// %s
// 	ret1 = printf("String: %s\n", "test");
// 	ret2 = ft_printf("String: %s\n", "test");
// 	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);
// 	// %p
// 	ptr = &ret1;
// 	ret1 = printf("Pointer: %p\n", (void *)ptr);
// 	ret2 = ft_printf("Pointer: %p\n", (void *)ptr);
// 	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);
// 	// %d, %i
// 	ret1 = printf("Number: %d\n", -42);
// 	ret2 = ft_printf("Number: %d\n", -42);
// 	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);
// 	ret1 = printf("Number: %i\n", 24);
// 	ret2 = ft_printf("Number: %i\n", 24);
// 	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);
// 	// %u
// 	ret1 = printf("Unsigned: %u\n", 42);
// 	ret2 = ft_printf("Unsigned: %u\n", 42);
// 	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);
// 	// %x, %X
// 	ret1 = printf("Hex: %x\n", 255);
// 	ret2 = ft_printf("Hex: %x\n", 255);
// 	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);
// 	ret1 = printf("Hex: %X\n", 255);
// 	ret2 = ft_printf("Hex: %X\n", 255);
// 	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);
// 	// %%
// 	ret1 = printf("Percent: %%\n");
// 	ret2 = ft_printf("Percent: %%\n");
// 	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);
// 	//%p(NULL)
// 	ptr = NULL;
// 	ret1 = printf("NULL pointer: %p\n", (void *)ptr);
// 	ret2 = ft_printf("NULL pointer: %p\n", (void *)ptr);
// 	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);
// 	//%p(0)
// 	ptr = (int *)0;
// 	ret1 = printf("Zero address pointer: %p\n", (void *)ptr);
// 	ret2 = ft_printf("Zero address pointer: %p\n", (void *)ptr);
// 	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);

// 	return (0);
// }