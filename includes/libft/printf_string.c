/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:52:18 by cofische          #+#    #+#             */
/*   Updated: 2024/05/02 11:46:58 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_string(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (count += write(1, "(null)", 6));
	while (*str)
	{
		printf_char((int)*str);
		count++;
		str++;
	}
	return (count);
}
