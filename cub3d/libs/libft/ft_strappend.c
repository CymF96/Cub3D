#include "libft.h"

char	*ft_strappend(char **s1, const char *s2)
{
	char	*str;

	if (!s1[0] || !s2)
		return (NULL);
	str = \
	(char *)ft_calloc((ft_strlen(s1[0]) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1[0], ft_strlen(s1[0]) + 1);
	ft_strlcat(str, s2, ft_strlen(s1[0]) + ft_strlen(s2) + 1);
	free(s1[0]);
	return (str);
}