/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:54:51 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/20 18:54:52 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	concat_nodes_into_str(t_list *list, char *str, int max_len)
{
	int	i;
	int	j;

	if (!list || !str)
		return ;
	j = 0;
	while (list && j <= max_len - 1)
	{
		i = 0;
		while (list->str_buff[i] && j <= max_len - 1)
		{
			str[j] = list->str_buff[i];
			if (list->str_buff[i++] == '\n')
			{
				str[j] = '\n';
				str[j + 1] = '\0';
				return ;
			}
			j++;
		}
		list = list->next;
	}
	str[j] = '\0';
}

char	*ft_get_full_line(t_list *list)
{
	int		str_len;
	char	*line;

	str_len = ft_len_to_newline(list);
	line = malloc(str_len + 1);
	if (!line)
		return (NULL);
	concat_nodes_into_str(list, line, str_len);
	return (line);
}

void	ft_append_chunk(t_list **list, char *buffer, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(list[fd]);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		list[fd] = new_node;
	else
		last_node->next = new_node;
	new_node->str_buff = buffer;
	new_node->next = NULL;
}

void	ft_create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	while (!ft_list_has_newline(list[fd]))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		ft_append_chunk(list, buffer, fd);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[FOPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	ft_create_list(list, fd);
	if (!list[fd])
		return (NULL);
	line = ft_get_full_line(list[fd]);
	ft_reset_list(&list[fd]);
	return (line);
}
