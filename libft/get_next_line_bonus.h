/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:53:04 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/20 18:53:06 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	char			*str_buff;
	struct s_list	*next;
}	t_list;
void	concat_nodes_into_str(t_list *list, char *str, int max_len);
char	*ft_get_full_line(t_list *list);
void	ft_append_chunk(t_list **list, char *buffer, int fd);
void	ft_create_list(t_list **list, int fd);
char	*get_next_line(int fd);
int		ft_list_has_newline(t_list *list);
t_list	*ft_lstlast(t_list *lst);
void	ft_clean_and_init(t_list **list, t_list *first_node, char *buffer);
void	ft_reset_list(t_list **list);
int		ft_len_to_newline(t_list *list);
#endif
