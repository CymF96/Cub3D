/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:26:26 by cofische          #+#    #+#             */
/*   Updated: 2024/05/06 09:04:54 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_hexaddress(unsigned long long bits)
{
	char			*hex;
	int				count;

	count = 0;
	hex = "0123456789abcdef";
	if (bits == 0)
	{
		count += write (1, "(nil)", 5);
		return (count);
	}
	if (bits >= 16)
		count += ft_printf_hexaddress((bits / 16));
	count += write (1, &hex[bits % 16], 1);
	return (count);
}

int	printf_pointer(void *ap)
{
	int					count;
	unsigned long long	bits;

	count = 0;
	if (ap == NULL)
	{
		count += write (1, "(nil)", 5);
		return (count);
	}
	bits = (unsigned long long)ap;
	count += write (1, "0x", 2);
	count += ft_printf_hexaddress(bits);
	return (count);
}
