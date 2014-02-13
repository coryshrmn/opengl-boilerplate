#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "callbacks.h"

#include <stdlib.h>
#include <stdio.h>

void render(GLFWwindow* w)
{
}

int main(int argc, char* argv[])
{
  glfwSetErrorCallback(error_callback);

  printf(
    "GLFW Meta "
    "(version, window system api, context creation api, additional api):"
    "\n%s\n",
    glfwGetVersionString()
  );

  if (!glfwInit())
  {
    exit(EXIT_FAILURE);
  }

  //probably smart to set these
  //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
  //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window;
  window = glfwCreateWindow(800, 600, "Default", NULL, NULL);
  if(!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);
  register_callbacks(window);

  ////////////////////////////////

  glewExperimental = GL_TRUE;
  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
    fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
    exit(EXIT_FAILURE);
  }
  printf("GLEW Meta (version):\n%s\n", glewGetString(GLEW_VERSION));

  /////////////////////////////////

  double time;
  while (!glfwWindowShouldClose(window))
  {
    time = glfwGetTime();

    render(window);

    glfwSwapBuffers(window);

    /*
     * When rendering continually use glfwPollEvents();
     * e.g. games
     */
    glfwPollEvents();

    /*
     * When rendering based on received input use glfwWaitEvents();
     * e.g. editing tools
     */
    //glfwWaitEvents();
  }

  ////////////////////////////////

  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}
