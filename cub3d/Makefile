NAME				=	cub3D
CC					=	cc
CFLAGS				=	-g -Wall -Wextra -Werror

MLXFLAGS			=	-lmlx -lXext -lX11
MATH_LIB			= 	-lm

LIBFT_DIR			=	./libs/libft
LIBFT				=	$(LIBFT_DIR)/libft.a
MLX_DIR				=	./libs/mlx
MLX					=	$(MLX_DIR)/libmlx_Linux.a
INCLUDES			=	-I ./includes

LIB_FLAGS = -L$(MLX_DIR) -L$(LIBFT_DIR) -lft

SRCS		=	src/main.c 						\
				src/arguments/validate_args.c	\
				src/colours/parse_colours.c		\
				src/errors/handler.c			\
				src/file/read_file.c			\
				src/file/validate_file.c		\
				src/memory/free_textures.c		\
				src/memory/free_colours.c		\
				src/memory/free_matrix.c		\
				src/state/init_state.c			\
				src/state/free_state.c			\
				src/textures/parse_textures.c	\

OBJS = $(SRCS:.c=.o)

GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_FLAGS) -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was generated$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

${LIBFT}:
	@make --no-print-directory -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)
	@make --no-print-directory clean -C $(LIBFT_DIR)

fclean:
	@rm -f $(OBJS)
	@rm -rf $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@make --no-print-directory fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
