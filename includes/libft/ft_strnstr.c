/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:53:05 by cofische          #+#    #+#             */
/*   Updated: 2024/04/24 12:42:30 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < n)
	{
		while (str[i + j] == to_find[j] && to_find[j] != '\0'
			&& (i + j) < n)
			j++;
		if (to_find[j] == '\0')
			return ((char *)&str[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
