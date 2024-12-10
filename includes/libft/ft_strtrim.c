/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_strtrim.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cofische <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/04/18 16:14:42 by cofische		   #+#	  #+#			  */
/*	 Updated: 2024/04/18 16:16:57 by cofische		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	char	*ptr;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = 0;
	end = s1_len - 1;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > start && ft_strchr(set, s1[end]) != NULL)
		end--;
	ptr = (char *)malloc((end - start + 2) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1 + start, (end - start + 2));
	return (ptr);
}
