/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:42:26 by cofische          #+#    #+#             */
/*   Updated: 2024/04/24 12:40:36 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*big;
	size_t		i;

	i = 0;
	big = (const char *)str;
	while (i < n && big != NULL)
	{
		if (big[i] == (const char)c)
			return ((void *)(big + i));
		i++;
	}
	return (NULL);
}
