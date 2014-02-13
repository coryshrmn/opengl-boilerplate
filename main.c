#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "main.h"
#include "callbacks.h"
//#include "utils.h"

#include <stdlib.h>
#include <stdio.h>

/*
void app_init()
{
  //this can be an array of arrays, but keeping things
  //simple, we'll only use one vertex array object for now
  //(this vao is already bound)
  GLuint vao = create_vert_arr();
}
*/

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

  //See main.h for configuring these properties
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, MY_GL_MAJOR);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, MY_GL_MINOR);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window;
  window = glfwCreateWindow(
    MY_SCREEN_WIDTH,
    MY_SCREEN_HEIGHT,
    MY_WINDOW_TITLE,
    FULLSCREEN ? glfwGetPrimaryMonitor() : NULL,
    NULL
  );
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

  //app_init();

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
