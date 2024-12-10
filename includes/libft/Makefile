# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cofische <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 09:14:28 by cofische          #+#    #+#              #
#    Updated: 2024/05/09 16:22:56 by cofische         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I/home/cofische/42_Common_Core/Libft
LDFLAGS = -lbsd
OBJDIR = OBJ

HEADER = libft.h
CFILES =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
 			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			ft_printf.c printf_char.c printf_string.c printf_digit.c\
			get_next_line.c get_next_line_utils.c printf_hex.c\
			printf_pointer.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c\
			ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c\
			ft_lstsize.c ft_atol.c
OFILES = $(patsubst %.c, $(OBJDIR)/%.o, $(CFILES))

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OFILES)
	@ar rcs $@ $(OFILES) $(LDFLAGS)
	@echo "Making Library libft.a"

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "Cleaning object files and OBJ directory"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaning all files, including $(NAME)"

re: fclean all
	@echo "Rebuilding from scratch"

.PHONY: all clean fclean re
