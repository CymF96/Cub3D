/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:52:51 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/04 18:52:52 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	process(char const *s, char *result, int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		result[j] = s[i];
		j++;
		i++;
	}
	result[j] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	size_t			size;
	int				to_alloc;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		to_alloc = 0;
	else
	{
		if (size - start < len)
			to_alloc = size - start;
		else
			to_alloc = len;
	}
	result = malloc((to_alloc + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (start > size)
		result[to_alloc] = '\0';
	else
		process(s, result, start, to_alloc);
	return (result);
}
