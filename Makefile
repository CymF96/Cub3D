NAME = cub3D
OBJDIR = OBJ
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXDIR = includes/minilibx-linux/
MLX = $(MLXDIR)libmlx.a
LIBFTDIR = includes/libft/
LIBFT = $(LIBFTDIR)libft.a
INC = -I ./includes/ -I $(MLXDIR) -I $(LIBFTDIR)
HEADER = src/cub3d.h

CFILES = 	src/cub3d.c\
			src/init_structure.c\
			src/map_checker.c\
			src/map_parsing.c\
			src/map_reading.c\
			src/map_utils.c\
			src/cleaning.c\
			src/cleaning_malloc.c\
			src/game_ctrl.c\
			src/key_event.c\
			src/launch_game.c\
			src/textures.c\
			src/pixel_img.c\
			src/draw_elements.c\
			src/raycasting.c\
			src/mouse.c\
			src/minimap.c\
			src/door.c\
			src/gun_sprite.c\
			src/utils.c\

OFILES = $(patsubst src/%.c, $(OBJDIR)/%.o, $(CFILES))

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(MLX):
	@$(MAKE) -C $(MLXDIR)

$(NAME): $(OFILES) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OFILES) $(MLX) $(LIBFT) -lXext -lX11 -lm -o $(NAME)
	@echo "Making cub3D"

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

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

.PHONY: all clean fclean re
