/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naser <Naser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 07:18:17 by Naser          #+#    #+#             */
/*   Updated: 2023/12/01 21:24:45 by Naser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_specifier(const char c, va_list ptr)
{
	int	len;

	len = 0;
	if (!c)
		return (0);
	if (c == 'c')
		len = ft_putchar_int(va_arg(ptr, int));
	else if (c == 's')
		len = ft_putstr_int(va_arg(ptr, char *));
	else if (c == 'i' || c == 'd')
		len = ft_put_itoa(va_arg(ptr, int));
	else if (c == '%')
		len = ft_putchar_int(c);
	else if (c == 'x')
		len = ft_put_utoa(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len = ft_put_utoa(va_arg(ptr, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		len = ft_putptr((size_t)(va_arg(ptr, size_t)), "0123456789abcdef");
	else if (c == 'u')
		len = ft_put_utoa(va_arg(ptr, unsigned int), "0123456789");
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		len;

	len = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!format)
				return (len);
			len += convert_specifier(*format, ptr);
			format++;
		}
		else
		{
			ft_putchar_int(*format);
			len++;
			format++;
		}
	}
	va_end(ptr);
	return (len);
}
