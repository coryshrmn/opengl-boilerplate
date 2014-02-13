#ifndef _CALLBACKS_
#define _CALLBACKS_

#include <GLFW/glfw3.h>

void error_callback(int, const char*);

void close_callback(GLFWwindow*);

void key_callback(GLFWwindow*, int, int, int, int);

void fb_size_callback(GLFWwindow*, int, int);

void char_callback(GLFWwindow*, unsigned int);

void cursor_enter_callback(GLFWwindow*, int);

void cursor_pos_callback(GLFWwindow*, double, double);

void mouse_butt_callback(GLFWwindow*, int, int, int);

void scroll_callback(GLFWwindow*, double, double);

void register_callbacks(GLFWwindow*);

#endif
