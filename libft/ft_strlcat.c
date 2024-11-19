/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:48:14 by cofische          #+#    #+#             */
/*   Updated: 2024/04/29 17:10:26 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (!dst && size == 0)
		return (s_len);
	j = ft_strlen(dst);
	d_len = j;
	if (size <= d_len)
		return (size + s_len);
	i = 0;
	while (src[i] && j + 1 < size)
		dst[j++] = src[i++];
	dst[j] = 0;
	return (d_len + s_len);
}
