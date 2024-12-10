/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_memmove.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cofische <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/04/18 16:39:16 by cofische		   #+#	  #+#			  */
/*	 Updated: 2024/04/22 12:16:29 by cofische		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src == NULL || dest == NULL || n == 0)
		return (dest);
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			((unsigned char *)dest)[i - 1] = ((const char *)src)[i - 1];
			i--;
		}
	}
	else if (src > dest)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
	}
	return (dest);
}
