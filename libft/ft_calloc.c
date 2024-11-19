/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_calloc.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cofische <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/04/18 16:14:42 by cofische		   #+#	  #+#			  */
/*	 Updated: 2024/04/18 16:16:57 by cofische		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nb_items, size_t n)
{
	char	*ptr;

	ptr = NULL;
	if ((int)nb_items < 0 && (int)n < 0)
		return (NULL);
	if (SIZE_MAX / nb_items < n)
		return (NULL);
	ptr = (char *)malloc((nb_items * n) * sizeof(char));
	if (ptr != NULL)
		ft_bzero(ptr, nb_items * n);
	return (ptr);
}
