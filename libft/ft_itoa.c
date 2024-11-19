/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_itoa.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cofische <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/04/22 12:09:40 by cofische		   #+#	  #+#			  */
/*	 Updated: 2024/04/25 11:55:59 by cofische		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

static size_t	ft_nbrlen(int nb)
{
	int	count;

	count = 1;
	while (nb >= 10)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static char	*ft_strnbr(char *s, int nb, int check, size_t len)
{
	char	digit;
	size_t	i;

	i = len;
	if (check == 1)
		s[0] = '-';
	s[i--] = '\0';
	while (nb)
	{
		digit = (nb % 10) + '0';
		s[i--] = digit;
		nb /= 10;
	}
	return (s);
}

char	*ft_itoa_special_case(int n, char *ptr)
{
	char	*temp;
	int		i;

	i = 12;
	temp = "-2147483648";
	if (n == 0)
	{
		ptr = (char *)malloc(2 * sizeof(char));
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	else if (n == INT_MIN)
	{
		ptr = (char *)malloc(12 * sizeof(char));
		while (i-- > 0)
			ptr[i] = temp[i];
		return (ptr);
	}
	else
		return (ptr);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	size_t			len;
	int				check;

	len = 0;
	check = 0;
	ptr = NULL;
	if (n == 0 || n == INT_MIN)
		return (ft_itoa_special_case(n, ptr));
	if (n < 0)
	{
		n = -n;
		check = 1;
		len++;
	}
	len += ft_nbrlen(n);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strnbr(ptr, n, check, len);
	return (ptr);
}
