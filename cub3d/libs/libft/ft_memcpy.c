/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:50:09 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/10/30 19:50:10 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t numBytes)
{
	const unsigned char			*src_char;
	unsigned char				*dest_char;

	if (!to && !from)
		return (NULL);
	src_char = (const unsigned char *)from;
	dest_char = (unsigned char *)to;
	while (numBytes--)
	{
		*dest_char++ = *src_char++;
	}
	return (to);
}
