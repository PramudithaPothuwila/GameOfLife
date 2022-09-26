﻿#include "GLFW.cuh"
#include <GLFW/glfw3.h>


namespace GameOfLife::GLFW
{
	int run()
	{
		if (!glfwInit())
			return -1;
		/* Create a windowed mode window and its OpenGL context */
		
		GLFWwindow* window = glfwCreateWindow(1920, 1080, "Conway's Game of World", NULL, NULL);
		
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			
			
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);
			/* Swap front and back buffers */
			glfwSwapBuffers(window);
			/* Poll for and process events */
			glfwPollEvents();
		}
		glfwTerminate();
		return 0;
	}
}