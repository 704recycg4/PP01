#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#pragma comment(lib,"OpenGL32")


static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void Input()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
	{
		
	}
	else
	{
		
	}

}

void main()
{
	GLFWwindow* window;
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(800, 800, "Simple example", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	float enemy_x=1, enemy_y = 0;
	float player_x=0, player_y = 0;

	while (!glfwWindowShouldClose(window))
	{
		enemy_x -= 0.01f;

		glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT);

		glPointSize(30);

		glBegin(GL_POINTS);
		glColor3f(255, 0, 0);
		glVertex2f(enemy_x, enemy_y);

		glEnd();

		if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
		{
			player_y = 0.5f;
		}
		else
		{
			player_y = 0;
		}

		glBegin(GL_POINTS);
		glColor3f(207, 255, 229);
		glVertex2f(player_x, player_y);
		glEnd();

		/*glPointSize(1);

		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, 0.0f);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(1.0f, 1.0f);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, 1.0f);

		glEnd();*/

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);

}