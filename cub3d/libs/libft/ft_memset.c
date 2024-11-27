/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:12:54 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/10/30 19:12:56 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*destiny;

	destiny = (unsigned char *)str;
	while (n--)
	{
		*destiny++ = (unsigned char) c;
	}
	return (str);
}
