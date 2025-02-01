NAME	:= fdf

LIBNAME = libft.a
LIBDIR = ./libft
LIBFT = ./libft/libft.a

MLX		= minilibx_opengl_20191021/ 
# ./minilibx-linux/libmlx_Linux.a
MLXDIR	= minilibx_opengl_20191021 
# ./minilibx-linux

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

HEADERS 	:= ./include
OBJDIR		:= ./obj
SRC     	:= 
OBJS     	:= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC      	:= cc
CFLAGS  	:= -Wall -Wextra -Werror -g -fPIC

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
.SILENT:

all: $(NAME)

$(OBJDIR)/%.o: %.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(HEADERS)

$(MLX) : runlibmlx

$(LIBFT): runlibft

# git clone https://github.com/42Paris/minilibx-linux.git; \

runlibmlx:
# @if [ ! -d "$(MLXDIR)" ]; then \
# 	git clone https://github.com/codam-coding-college/MLX42.git; \
# fi
	$(MAKE) -C $(MLXDIR)

runlibft:
	$(MAKE) -C $(LIBDIR)

$(NAME): $(LIBFT) $(MLX) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lminilibx-linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBDIR) clean

fclean: clean
	rm -rf $(OBJDIR)
	rm -f $(NAME)
	make -C $(LIBDIR) fclean
	make -C $(MLXDIR) clean
	rm -rf $(MLXDIR)


re: fclean all

.PHONY: all clean fclean re