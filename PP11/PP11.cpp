#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

//#include "Vector2.h"

#include <string>
#include<iostream>

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
	if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
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

	glfwMakeContextCurrent(window); // 윈도우 이벤트 잡아옴 사용하겠다// 합친다
	glfwSetKeyCallback(window, key_callback);

	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	float enemy_x = 0, enemy_y = 0;
	float player_x = 0, player_y = 0;

	while (!glfwWindowShouldClose(window))
	{
		//enemy_x -= 0.01f;

		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);

		glBegin(GL_TRIANGLES);
		glColor4f(1.0f, 0.0f, 0.0f,1.0f);
		glVertex2f(0.0f + enemy_x, 0.1f + enemy_y); // 1 

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex2f(0.1f + enemy_x, 0.1f + enemy_y);// 2

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex2f(0.0f + enemy_x, 0.0f + enemy_y);// 3

		glBegin(GL_TRIANGLES);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex2f(0.1f + enemy_x, 0.1f + enemy_y); // 1

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex2f(0.0f + enemy_x, 0.0f + enemy_y);// 2

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex2f(0.1f + enemy_x, 0.0f + enemy_y);// 3

		glEnd();
		
		std::string text;
		text = "Test Text";
		
		//(text.data(), text.size(), 0, 0);


		if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
		{
			player_y += 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
		{
			player_y -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
		{
			player_x += 0.01f;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
		{
			player_x -= 0.01f;
		}
		/*else
		{
			player_y = 0;
		}*/

		//glBegin(GL_POINTS);
		//glColor3f(0.811, 1, 0.9);
		//glVertex2f(player_x, player_y);
		//glEnd();

		//glPointSize(1);

		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.0f+ player_x, 0.1f + player_y); // 1 

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.1f+ player_x, 0.1f + player_y);// 2

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.0f+ player_x, 0.0f + player_y);// 3

		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.1f+ player_x, 0.1f + player_y); // 1

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.0f+ player_x, 0.0f + player_y);// 2

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.1f+ player_x, 0.0f + player_y);// 3

		glEnd();

		if (0.0f + enemy_x< player_x && 0.1f + enemy_y>0.1f + player_y) {
			std::cout << "반맞음";
		}

		if (0.1f + enemy_x > 0.1f + player_x && 0.0f + enemy_y < 0.0f + player_y)
		{
			std::cout << "맞음";
		}

		if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
		{
			std::cout << "맞음";
		}
		/*if (0.1f + enemy_x > 0.1f + player_x && 0.0f + enemy_y < 0.0f + player_y)
		{

		}*/


		glfwSwapBuffers(window); // 그리는ㄴ 모습이 나오지 않도록 버퍼끼리 스왑해주며 더블버퍼 스왑
		glfwPollEvents(); // 쌓아뒀다가 사용
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);

}