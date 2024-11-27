/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:03:00 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/12/17 21:03:01 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned int n)
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

static char	*handle_zero(void)
{
	char	*result;

	result = malloc(2);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

static void	handle_positive(char *result, unsigned int n, int n_digits)
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

char	*ft_uitoa(unsigned int n)
{
	char	*result;
	int		n_digits;

	n_digits = count_digits(n);
	if (n == 0)
	{
		return (handle_zero());
	}
	else
	{
		result = malloc(n_digits);
		if (result == NULL)
			return (NULL);
		handle_positive(result, n, n_digits);
	}
	return (result);
}
