/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:20:26 by cofische          #+#    #+#             */
/*   Updated: 2024/05/24 14:44:07 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	create_group_line(int fd, t_line **group_line)
{
	int		char_read;
	t_line	*last_node;
	t_line	*new_node;

	if (group_line == NULL)
		return ;
	while (return_line_found(group_line[fd]) == 0)
	{
		new_node = malloc(sizeof(t_line));
		if (new_node == NULL)
			return ;
		char_read = read(fd, new_node->buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(new_node);
			return ;
		}
		new_node->buf[char_read] = '\0';
		last_node = lst_node(group_line[fd]);
		if (last_node == NULL)
			group_line[fd] = new_node;
		else
			last_node->next = new_node;
		new_node->next = NULL;
	}
}

void	clean_nodes(t_line **group_line)
{
	t_line	*temp_node;
	int		i;

	if (group_line == NULL || (*group_line) == NULL)
		return ;
	while ((*group_line)->next != NULL)
	{
		temp_node = (*group_line)->next;
		free((*group_line));
		(*group_line) = temp_node;
	}
	i = 0;
	while ((*group_line)->buf[i] != '\0' && (*group_line)->buf[i] != '\n')
		i++;
	if ((*group_line)->buf[i] == '\n')
		ft_memmove((*group_line)->buf,
			(*group_line)->buf + (i + 1), BUFFER_SIZE - i + 1);
	else
	{
		free(*group_line);
		*group_line = NULL;
	}
}

void	next_group_line(t_line **group_line)
{
	if (group_line == NULL || *group_line == NULL)
		return ;
	clean_nodes(group_line);
}

char	*copy_line(t_line *node_line)
{
	int		line_len;
	char	*str;

	if (node_line == NULL)
		return (NULL);
	line_len = line_strlen(node_line);
	str = malloc(line_len + 1);
	if (str == NULL)
		return (NULL);
	combined_lines(node_line, str);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line_to_read;
	static t_line	*group_line[4096];

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	create_group_line(fd, group_line);
	if (group_line[fd] == NULL)
		return (NULL);
	line_to_read = copy_line(group_line[fd]);
	next_group_line(&group_line[fd]);
	return (line_to_read);
}
