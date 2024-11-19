/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_strjoin.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cofische <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/04/18 16:14:42 by cofische		   #+#	  #+#			  */
/*	 Updated: 2024/04/18 16:16:57 by cofische		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = (ft_strlen(s1) + ft_strlen(s2));
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		ptr[i++] = *s1++;
	}
	while (i < len && *s2 != '\0')
	{
		ptr[i++] = *s2++;
	}
	ptr[i] = '\0';
	return (ptr);
}
