/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:06:52 by cofische          #+#    #+#             */
/*   Updated: 2024/05/24 14:43:42 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	return_line_found(t_line *node_line)
{
	int		i;

	while (node_line != NULL)
	{
		i = 0;
		while (node_line->buf[i] != '\0' && i < BUFFER_SIZE)
		{
			if (node_line->buf[i] == '\n')
				return (1);
			i++;
		}
		node_line = node_line->next;
	}
	return (0);
}

t_line	*lst_node(t_line *node_line)
{
	if (node_line == NULL)
		return (NULL);
	while (node_line->next != NULL)
		node_line = node_line->next;
	return (node_line);
}

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
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

size_t	line_strlen(t_line *node_line)
{
	int	i;
	int	len;

	if (node_line == NULL)
		return (0);
	len = 0;
	while (node_line != NULL)
	{
		i = 0;
		while (node_line->buf[i] != '\0')
		{
			if (node_line->buf[i] == '\n')
				return (len + 1);
			i++;
			len++;
		}
		node_line = node_line->next;
	}
	return (len);
}

void	combined_lines(t_line *node_line, char *str)
{
	int		i;
	int		k;

	if (node_line == NULL)
		return ;
	k = 0;
	while (node_line != NULL)
	{
		i = 0;
		while (node_line->buf[i] != '\0')
		{
			str[k] = node_line->buf[i];
			if (node_line->buf[i] == '\n')
			{
				str[k + 1] = '\0';
				return ;
			}
			i++;
			k++;
		}
		node_line = node_line->next;
	}
	str[k] = '\0';
}
