/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:50:36 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/20 18:50:38 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_list_has_newline(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buff[i] != '\0' && i < BUFFER_SIZE)
		{
			if (list->str_buff[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	ft_len_to_newline(t_list *list)
{
	int	len;
	int	i;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buff[i])
		{
			len++;
			if (list->str_buff[i] == '\n')
				return (len);
			i++;
		}
		list = list->next;
	}
	return (len);
}

void	ft_clean_and_init(t_list **list, t_list *first_node, char *buffer)
{
	t_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buff);
		free(*list);
		*list = tmp;
	}
	if (first_node->str_buff[0])
		*list = first_node;
	else
	{
		free(buffer);
		free(first_node);
	}
}

void	ft_reset_list(t_list **list)
{
	t_list	*last_node;
	t_list	*first_node;
	char	*buffer;
	int		j;
	int		i;

	buffer = malloc(BUFFER_SIZE + 1);
	first_node = malloc(sizeof(t_list));
	if (!buffer || !first_node)
	{
		free(buffer);
		free(first_node);
		return ;
	}
	last_node = ft_lstlast(*list);
	j = 0;
	i = 0;
	while (last_node->str_buff[i] && last_node->str_buff[i] != '\n')
		++i;
	while (last_node->str_buff[i] && last_node->str_buff[++i])
		buffer[j++] = last_node->str_buff[i];
	buffer[j] = '\0';
	first_node->str_buff = buffer;
	first_node->next = NULL;
	ft_clean_and_init(list, first_node, buffer);
}
