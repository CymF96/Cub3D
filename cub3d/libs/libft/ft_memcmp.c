/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:21:11 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/10/31 14:21:13 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n_bytes)
{
	const unsigned char			*s1;
	const unsigned char			*s2;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (n_bytes > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		n_bytes--;
		s1++;
		s2++;
	}
	return (0);
}
