NAME = cub3D
NAME2 = bonus_cub3D
OBJDIR = OBJ
BOBJDIR = BONUS_OBJ
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXDIR = minilibx-linux/
MLX = $(MLXDIR)libmlx.a
LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a
INC = -I ./includes/ -I $(MLXDIR) -I $(LIBFTDIR)
HEADER = src/cub3d.h
HEADERB = src_bonus/bonus_cub3d.h

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
			src/utils.c\
			
CFILESB = 	src_bonus/bonus_cub3d.c\
			src_bonus/bonus_init_structure.c\
			src_bonus/bonus_map_checker.c\
			src_bonus/bonus_map_parsing.c\
			src_bonus/bonus_map_reading.c\
			src_bonus/bonus_cleaning.c\
			src_bonus/bonus_game_ctrl.c\
			src_bonus/bonus_launch_game.c\
			src_bonus/bonus_textures.c\
			src_bonus/bonus_pixel_img.c\
			src_bonus/bonus_raycasting.c\
			src_bonus/bonus_mouse.c\
			src_bonus/bonus_minimap.c\
			src_bonus/bonus_utils.c\

OFILES = $(patsubst src/%.c, $(OBJDIR)/%.o, $(CFILES))
OFILESB = $(patsubst src_bonus/%.c, $(BOBJDIR)/%.o, $(CFILESB))

all: $(NAME)
bonus: $(NAME2)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BOBJDIR):
	@mkdir -p $(BOBJDIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(MLX):
	@$(MAKE) -C $(MLXDIR)

$(NAME): $(OFILES) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OFILES) $(MLX) $(LIBFT) -lXext -lX11 -lm -o $(NAME)
	@echo "Making cub3D"

$(NAME2): $(OFILESB) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OFILESB) $(MLX) $(LIBFT) -lXext -lX11 -lm -o $(NAME2)
	@echo "Making cub3D_bonus"

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BOBJDIR)/%.o: src_bonus/%.c | $(BOBJDIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFTDIR) clean
	@$(MAKE) -C $(MLXDIR) clean
	@rm -rf $(OFILES) $(OBJDIR)
	@rm -rf $(OFILESB) $(BOBJDIR)
	@echo "cleaning 'o' files"

fclean: clean
	@rm -rf $(LIBFT)
	@rm -rf $(MLX)
	@rm -rf $(NAME)
	@rm -rf $(NAME2)
	@echo "cleaning exec files"

re: fclean all

.PHONY: all bonus clean fclean re
