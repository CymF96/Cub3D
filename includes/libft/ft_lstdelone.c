/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_lstdelone.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cofische <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/04/29 08:26:59 by cofische		   #+#	  #+#			  */
/*	 Updated: 2024/04/29 08:26:59 by cofische		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
