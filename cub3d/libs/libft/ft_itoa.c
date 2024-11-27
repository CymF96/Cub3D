/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:49:19 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/10 18:49:21 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	i;

	i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	handle_negative(char *result, long n, int n_digits)
{
	n *= -1;
	result[0] = '-';
	result[n_digits] = '\0';
	n_digits--;
	while (n_digits > 0)
	{
		result[n_digits] = (n % 10) + '0';
		n /= 10;
		n_digits--;
	}
}

static void	handle_positive(char *result, int n, int n_digits)
{
	result[n_digits - 1] = '\0';
	n_digits -= 2;
	while (n_digits >= 0)
	{
		result[n_digits] = (n % 10) + '0';
		n /= 10;
		n_digits--;
	}
}

static char	*handle_zero(void)
{
	char	*result;

	result = malloc(2);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		n_digits;

	n_digits = count_digits(n);
	if (n < 0)
	{
		result = malloc(n_digits + 1);
		if (result == NULL)
			return (NULL);
		handle_negative(result, n, n_digits);
	}
	else if (n > 0)
	{
		result = malloc(n_digits);
		if (result == NULL)
			return (NULL);
		handle_positive(result, n, n_digits);
	}
	else
	{
		return (handle_zero());
	}
	return (result);
}
