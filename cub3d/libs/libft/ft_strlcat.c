/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:54:36 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/10/30 21:54:39 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	if (dest == NULL && size == 0)
		return (0);
	i = 0;
	dest_len = 0;
	src_len = ft_strlen(src);
	while (dest[dest_len] != '\0' && dest_len < size)
		dest_len++;
	if (size <= dest_len)
		return (dest_len + src_len);
	while (src[i] != '\0' && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len + i <= size)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
