/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:49:49 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/01 22:49:51 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*arr;

	if (size != 0 && nitems > (SIZE_MAX / size))
		return (NULL);
	arr = malloc(nitems * size);
	if (arr == 0)
		return (NULL);
	return (ft_memset(arr, 0, nitems * size));
}
