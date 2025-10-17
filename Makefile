NAME=cub3d
# /////////////////////////

CC=cc
CC_FLAGS=-Wall -Wextra -Werror -g3

# /////////////////////////

DIR_OBJS=.objs
DIR_DEPS=.deps

# /////////////////////////

SRCS=src/main.c

LIB= libft/libft.a
MLX= minilibx-linux/libmlx.a
INCS=inc/cub3d.h
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

$(NAME): $(OBJS) $(DEPS) $(INCS) Makefile $(LIB)
	$(CC) $(CC_FLAGS) $(OBJS) -L minilibx-linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIB) $(MLX) -o $@
	echo "$(BLUE)Your cub3d is ready $(END)"


$(DIR_OBJS)/%.o: %.c Makefile 
	mkdir -p $(dir $@) $(DIR_DEPS)/$(dir $*)
	$(CC) $(CC_FLAGS) -I/usr/include -Imlx_linux -O3 -MMD -MP -MF $(DIR_DEPS)/$*.d -c -o $@ $<

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

.PHONY: all clean fclean re libft
.SILENT: