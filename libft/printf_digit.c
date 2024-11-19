/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:09:40 by cofische          #+#    #+#             */
/*   Updated: 2024/05/06 09:05:18 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	int				count;
	unsigned char	digit;
	long int		n;

	count = 0;
	n = (long int)nb;
	if (n < 0)
	{
		count += write (1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	digit = (n % 10) + '0';
	count += write(1, &digit, 1);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int				count;
	unsigned char	digit;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	digit = (nb % 10) + '0';
	count += write(1, &digit, 1);
	return (count);
}

int	printf_digit(int ap, int base)
{
	int		count;

	count = 0;
	if (ap == 0)
		count += write (1, "0", 1);
	else if (base == 10)
		count += ft_putnbr(ap);
	else if (base == 18)
		count += ft_putnbr_unsigned(ap);
	return (count);
}
