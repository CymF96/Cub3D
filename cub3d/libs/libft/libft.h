/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:47:43 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/12 21:47:45 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <strings.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isalnum(int c);
int		ft_memcmp(const void *str1, const void *str2, size_t n_bytes);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_strchr(const char *str, int c);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memcpy(void *to, const void *from, size_t numBytes);
void	*ft_memmove(void *to, const void *from, size_t numBytes);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	*ft_calloc(size_t nitems, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnstr_fd(char *s, int fd, int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_free_ptr(char **ptr);
char	*ft_strrchr(const char *str, int c);
char	*ft_strdup(const char *str);
char	*ft_strnstr(const char *str, const char *to_find, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_strappend(char **s1, const char *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
#endif
