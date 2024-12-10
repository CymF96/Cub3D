/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:11:48 by cofische          #+#    #+#             */
/*   Updated: 2024/05/06 09:07:53 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(int nb)
{
	int				count;
	char			*hex;
	unsigned char	digit;
	unsigned int	n;

	count = 0;
	n = (unsigned int)nb;
	hex = "0123456789abcdef";
	if (n < 16)
	{
		digit = hex[n];
		count += write (1, &digit, 1);
	}
	else
	{
		count += ft_puthex(n / 16);
		digit = hex[n % 16];
		count += write (1, &digit, 1);
	}
	return (count);
}

int	ft_puthex_upper(int nb)
{
	int				count;
	char			*hex;
	unsigned char	digit;
	unsigned int	n;

	count = 0;
	n = (unsigned int)nb;
	hex = "0123456789ABCDEF";
	if (n < 16)
	{
		digit = hex[n];
		count += write (1, &digit, 1);
	}
	else
	{
		count += ft_puthex_upper(n / 16);
		digit = hex[n % 16];
		count += write (1, &digit, 1);
	}
	return (count);
}

int	printf_hex(int ap, int base)
{
	int		count;

	count = 0;
	if (ap == 0)
		count += write (1, "0", 1);
	else if (base == 16)
		count += ft_puthex(ap);
	else if (base == 17)
		count += ft_puthex_upper(ap);
	return (count);
}
