/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:42:56 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/01 20:42:57 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	check_overflow(int result, int digit)
{
	int	limit;

	limit = INT_MAX / 10;
	if (result > limit || (result == limit && digit > INT_MAX % 10))
		return (1);
	return (0);
}

static int	check_underflow(int result, int digit)
{
	int	limit;

	limit = -(INT_MIN / 10);
	if (result > limit || (result == limit && digit > -(INT_MIN % 10)))
		return (1);
	return (0);
}

static int	check_overlap(char c, int sign, int *result)
{
	int	digit;

	digit = c - 48;
	if (sign == 1 && check_overflow(*result, digit))
		return (INT_MAX);
	if (sign == -1 && check_underflow(*result, digit))
		return (INT_MIN);
	*result = *result * 10 + digit;
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;
	int	overlap;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		overlap = check_overlap(str[i], sign, &result);
		if (overlap != 0)
			return (overlap);
		i++;
	}
	return (result * sign);
}
