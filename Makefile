NAME		= miniRT

LIBNAME 	= libft.a
LIBDIR 		= ./libft
LIBFT 		= ./libft/libft.a

MLXDIR		= MLX42
MLX			= $(MLXDIR)/build/libmlx42.a

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

HEADERS 	= ./include
OBJDIR		= ./obj
SRC     	= test.c
OBJS     	= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC      	= cc
CFLAGS  	= -Wall -Wextra -Werror -g
LDFLAGS 	= -L$(MLXDIR)/build -lmlx42 -lglfw -ldl -pthread -lm

CFLAGS 		+= -I$(HEADERS) -I$(MLXDIR)/include


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

runlibmlx:
	@if [ ! -d "MLX42" ]; then \
	    git clone https://github.com/codam-coding-college/MLX42.git; \
	fi
	@cd MLX42 && \
	cmake -B build && \
	cmake --build build -j4
	@echo "MLX42 build complete"

runlibft:
	$(MAKE) -C $(LIBDIR)

$(NAME): $(LIBFT) $(MLX) $(OBJS) 
	$(CC) $(OBJS) -o $(NAME) $(LIBFT) $(LDFLAGS)

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