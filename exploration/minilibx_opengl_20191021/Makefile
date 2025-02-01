#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

# added by myakoven
# Include paths for headers
CFLAGS += -I$(HOME)/sgoinfre/local/opengl/include
CFLAGS += -I$(HOME)/sgoinfre/local/glew/include

# OpenGL related definitions
CFLAGS += -DGL_GLEXT_PROTOTYPES
CFLAGS += -DSTRINGPUTX11

# Library paths and linking flags
LDFLAGS += -L$(HOME)/sgoinfre/local/opengl/lib
LDFLAGS += -L$(HOME)/sgoinfre/local/glew/lib

# Libraries to link
LDFLAGS += -lGLEW    # GLEW library
LDFLAGS += -lGL      # OpenGL library
LDFLAGS += -lglfw    # GLFW library
LDFLAGS += -lX11     # X11 library
LDFLAGS += -lXext    # X11 extensions
LDFLAGS += -lm       # Math library
# end of added by myakoven

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

re: clean all
