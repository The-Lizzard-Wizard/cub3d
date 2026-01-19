NAME=cub3D
# /////////////////////////

CC=cc
CC_FLAGS=-Wall -Wextra -Werror -g3 #-fsanitize=address,leak

# /////////////////////////

DIR_OBJS=.objs
DIR_DEPS=.deps

# /////////////////////////

SRCS = \
	src/main.c \
	\
	src/pars_init/init_data.c \
	src/pars_init/init_mlx.c \
	src/pars_init/pars.c \
	src/pars_init/pars_map.c \
	src/pars_init/pars_utils.c \
	src/pars_init/pars_texture.c \
	src/pars_init/pars_texture_utils.c \
	src/pars_init/get_map.c \
	src/pars_init/load_textures.c \
	src/pars_init/error.c \
	\
	src/graphics/graphics.c \
	src/graphics/graphics_alloc.c \
	src/graphics/graphics_display.c \
	src/graphics/graphics_shapes.c \
	src/graphics/graphics_anime.c \
	src/graphics/render.c \
	\
	src/raycaster/math.c \
	src/raycaster/raycaster.c \
	src/raycaster/raycast_draw.c \
	src/raycaster/raycast_utils.c \
	src/raycaster/raycast_sprites.c \
	src/raycaster/raycast_sprites_draw.c \
	src/raycaster/raycast_sprites_sort.c \
	\
	src/gameplay/thing.c \
	src/gameplay/thing_key.c \
	src/gameplay/thing_utils.c \
	src/gameplay/thing_banana.c \
	src/gameplay/thing_kiwi.c \
	src/gameplay/door.c \
	src/gameplay/magic_rod.c \
	\
	src/ui/init_ui.c \
	src/ui/mini_map.c \
	src/ui/update_minimap.c \
	src/ui/hud.c \
	\
	src/event/event.c \

LIB= libft/libft.a
MLX= minilibx-linux/libmlx.a
INCS=inc/cub3d.h inc/key.h inc/define.h inc/pars.h inc/cub_math.h
OBJS=$(SRCS:%.c=$(DIR_OBJS)/%.o)
DEPS=$(SRCS:%.c=$(DIR_DEPS)/%.d)

# /////////////////////////

all: compile_start libft libmlx $(NAME) compile_done

compile_start:
	echo "$(GREEN)Compile start... $(END)"

compile_done:
	echo "$(GREEN)Compiling done $(END)"

libft:
	$(MAKE) --silent -C ./libft

libmlx:
	$(MAKE) --silent -C ./minilibx-linux 2> /dev/null

$(NAME): $(OBJS) Makefile $(LIB)
	$(CC) $(CC_FLAGS) $(OBJS) -L minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz $(LIB) $(MLX) -o $@
	echo "$(BLUE)Your cub3D is ready $(END)"

$(DIR_OBJS)/%.o: %.c Makefile 
	mkdir -p $(dir $@) $(DIR_DEPS)/$(dir $*)
	$(CC) $(CC_FLAGS) -I/inc -Imlx_linux -O3 -MMD -MP -MF $(DIR_DEPS)/$*.d -c -o $@ $<

# /////////////////////////

clean:
	echo "$(RED)Removing files... $(END)"
	$(MAKE) --silent -C  ./libft fclean
	$(MAKE) --silent -C  ./minilibx-linux clean
	rm -rf $(DIR_OBJS)
	rm -rf $(DIR_DEPS)

fclean: clean
	echo "$(RED)Removing executable... $(END)"
	$(MAKE) --silent -C  ./libft fclean
	$(MAKE) --silent -C  ./minilibx-linux clean
	rm -rf $(NAME)

re: fclean all

# /////////////////////////

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

# /////////////////////////

-include $(DEPS)

.PHONY: all clean fclean re libft
.SILENT: