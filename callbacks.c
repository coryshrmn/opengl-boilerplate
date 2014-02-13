#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

void error_callback(int error, const char* description)
{
  fputs(description, stderr);
}

void close_callback(GLFWwindow* w)
{
}

void key_callback(GLFWwindow* w, int key, int scancode, int action, int mods)
{
  //if (key == GLFW_SOME_KEY && action == GLFW_SOMEACTION)
  //{
  //  do something
  //}
  //...
}

void fb_size_callback(GLFWwindow* w, int width, int height)
{
  glViewport(0, 0, width, height);
}

void char_callback(GLFWwindow* w, unsigned int code)
{
  //handle text input; e.g. font rendering not button presses
  //for button presses see key_callback
}

void cursor_enter_callback(GLFWwindow* w, int entered)
{
}

void cursor_pos_callback(GLFWwindow* w, double x, double y)
{
}

void mouse_butt_callback(GLFWwindow* w, int button, int action, int mods)
{
}

void scroll_callback(GLFWwindow* w, double xoffset, double yoffset)
{
}

void register_callbacks(GLFWwindow* w)
{
  //note: doesn't register error_callback
  glfwSetWindowCloseCallback(w, close_callback);
  glfwSetFramebufferSizeCallback(w, fb_size_callback);
  glfwSetCharCallback(w, char_callback);
  glfwSetCursorEnterCallback(w, cursor_enter_callback);
  glfwSetCursorPosCallback(w, cursor_pos_callback);
  glfwSetKeyCallback(w, key_callback);
  glfwSetMouseButtonCallback(w, mouse_butt_callback);
  glfwSetScrollCallback(w, scroll_callback);
}
