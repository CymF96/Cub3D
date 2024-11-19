/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_putnbr_fd.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cofische <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/04/18 16:14:42 by cofische		   #+#	  #+#			  */
/*	 Updated: 2024/04/18 16:16:57 by cofische		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

static int	ft_div(int nb)
{
	int	size;

	size = 1;
	while (nb >= 10)
	{
		nb /= 10;
		size *= 10;
	}
	return (size);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int		div;
	char	digit;

	if (nb == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	div = ft_div(nb);
	while (div > 0)
	{
		digit = (nb / div) + '0';
		write(fd, &digit, 1);
		nb %= div;
		div /= 10;
	}
}
