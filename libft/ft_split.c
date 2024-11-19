/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:19:31 by cofische          #+#    #+#             */
/*   Updated: 2024/04/24 12:40:57 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_rows(const char *str, char del)
{
	int	rows;

	rows = 0;
	if (*str == '\0')
		return (0);
	if (*str != del)
	{
		rows++;
		str++;
	}
	while (*str)
	{
		if (*str != del && *(str - 1) == del)
			rows++;
		str++;
	}
	return (rows);
}

static size_t	row_len(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (*str != '\0' && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

static void	*safe_malloc(size_t size)
{
	char	*ptr;

	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	int		nb_rows;
	char	**strings;
	int		i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	nb_rows = count_rows(s, c);
	strings = (char **)malloc((nb_rows + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	strings[nb_rows] = NULL;
	i = 0;
	while (i < nb_rows)
	{
		while (*s == c && s != NULL)
			s++;
		len = row_len(s, c);
		strings[i] = safe_malloc(len);
		ft_strlcpy(strings[i], s, len + 1);
		s += len;
		i++;
	}
	return (strings);
}
