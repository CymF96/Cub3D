/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:41:20 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/04 18:41:21 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(sizeof (char) * (s1_len + s2_len) + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, s1_len +1);
	ft_strlcat(result, s2, (s1_len + s2_len) + 1);
	return (result);
}
