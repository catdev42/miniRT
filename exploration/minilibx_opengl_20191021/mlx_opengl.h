/*
**
** mlx_opengl.h 
**
** public include, use it after mlx.h
** designed only for minilibx_macos
**
*/
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include "/home/myakoven/sgoinfre/local/glew/glew-2.2.0/include/GL/glew.h"
#include <GL/gl.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>
// # include "/home/myakoven/sgoinfre/local/opengl/include/GLFW/glfw3native.h"
#endif

void    *mlx_new_opengl_window(void *mlx_ptr, int size_x, int size_y, char *title);

/* create an opengl window. put_image & pixel_put & string_put do not work there. */

int	mlx_opengl_swap_buffers(void *win_ptr);

/* the created window is double buffered. Use this funct to swap buffers */
/* this funct will call glFlush(). Don't call it. */

int	mlx_opengl_window_set_context(void *win_ptr);

/* in case multiple opengl windows are present, change opengl active context */
