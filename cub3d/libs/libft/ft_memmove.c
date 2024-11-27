/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:09:16 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/10/30 20:09:17 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t numBytes)
{
	const unsigned char			*src_char;
	char unsigned				*dest_char;

	src_char = (const unsigned char *)from;
	dest_char = (unsigned char *)to;
	if (dest_char < src_char)
	{
		while (numBytes--)
			*dest_char++ = *src_char++;
	}
	else if (dest_char > src_char)
	{
		src_char += numBytes;
		dest_char += numBytes;
		while (numBytes--)
			*(--dest_char) = *(--src_char);
	}
	return (to);
}
