#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include "/home/myakoven/sgoinfre/local/glew/glew-2.2.0/include/GL/glew.h"
#include <GL/gl.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>
// # include "/home/myakoven/sgoinfre/local/opengl/include/GLFW/glfw3native.h"
#endif


void    *mlx_png_file_to_image(void *xvar, char *file, int *width, int *height);
