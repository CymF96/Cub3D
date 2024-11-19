/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:58:11 by cofische          #+#    #+#             */
/*   Updated: 2024/05/06 09:19:20 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_format(int c, va_list *ap)
{
	int		count;

	count = 0;
	if (c == 'c')
		count += printf_char(va_arg(*ap, int));
	else if (c == 's')
		count += printf_string(va_arg(*ap, char *));
	else if (c == 'i' || c == 'd')
		count += printf_digit(va_arg(*ap, int), 10);
	else if (c == 'x')
		count += printf_hex(va_arg(*ap, int), 16);
	else if (c == 'X')
		count += printf_hex(va_arg(*ap, int), 17);
	else if (c == 'u')
		count += printf_digit(va_arg(*ap, unsigned int), 18);
	else if (c == 'p')
		count += printf_pointer(va_arg(*ap, void *));
	else if (c == '%')
		count += write (1, "%", 1);
	else
		write (1, "Unknown specifier", 18);
	return (count);
}

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	if (!string)
		return (0);
	va_start(ap, string);
	while (*string != '\0')
	{
		if (*string == '%')
			count += printf_format(*(++string), (va_list *)ap);
		else
			count += write (1, string, 1);
		string++;
	}
	va_end(ap);
	return (count);
}
