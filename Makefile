NAME = cub3D
# NAME2 = cub3D_bonus
OBJDIR = OBJ
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# OS detection
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    MLXDIR = minilibx-linux/
    MLX = $(MLXDIR)libmlx.a
    MLXFLAGS = -lXext -lX11 -lm
else ifeq ($(UNAME_S),Darwin)
    MLXDIR = minilibx_mac/
    MLX = $(MLXDIR)libmlx.a
    MLXFLAGS = -framework OpenGL -framework AppKit
    CFLAGS += -DGL_SILENCE_DEPRECATION
endif

LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a
INC = -I ./includes/ -I $(MLXDIR) -I $(LIBFTDIR)
HEADER = src/cub3d.h
# HEADERB = bonus/cub3d.h

CFILES =	src/cub3d.c\
			src/init_structure.c\
			src/map_checker.c\
			src/map_parsing.c\
			src/map_reading.c\
			src/cleaning.c\
			src/game_ctrl.c\
			src/launch_game.c\
			src/textures.c\
			src/pixel_img.c\
			src/raycasting.c\
			src/utils.c

# CFILESB =
OFILES = $(patsubst src/%.c, $(OBJDIR)/%.o, $(CFILES))
# OFILESB = $(CFILESB:%.c=%.o)

all: $(NAME)
# bonus: $(NAME2)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(MLX):
	@$(MAKE) -C $(MLXDIR)

$(NAME): $(OFILES) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OFILES) $(MLX) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "Making cub3D"

# $(NAME2): $(OFILESB) $(LIBFT) $(MLX)
# @$(CC) $(CFLAGS) $(OFILESB) $(MLX) $(LIBFT) $(MLXFLAGS) -o $(NAME2)
# @echo "Making cub3D_bonus"

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# bonus/%.o: bonus/%.c
	# @$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFTDIR) clean
	@$(MAKE) -C $(MLXDIR) clean
	@rm -rf $(OFILES) $(OBJDIR)
	@echo "cleaning 'o' files"

fclean: clean
	@rm -rf $(LIBFT)
	@rm -rf $(MLX)
	@rm -rf $(NAME)
	@echo "cleaning exec files"

re: fclean all

.PHONY: all bonus clean fclean re
