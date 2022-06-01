#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <crtdbg.h>

//#include "Vector.h"

#include <string>
#include <iostream>

#include "Collider.hpp"
#include "Bullet.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

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

	//_______________________________________________________
	float enemy_x = 0, enemy_y = 0;
	float player_x = 0, player_y = 0;
	float bullet_x = 0, bullet_y = 0;


	float bullet_speed = 0.07f;
	float playerSpeed = 0.015f;

	Bullet b;
	Player p;
	Enemy E(-0.5f,0 );
	Enemy E2(-0.8f,0 );
	Enemy E3(-1.1f,0 );
	Enemy E4(-1.4f,0 );

	while (!glfwWindowShouldClose(window))
	{
		//enemy_x -= 0.01f;

		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);

		/*스페이스 바를 누르면 총알이 나감
		총알의 좌표는

		누르는 순간의 플레이어 좌표에서
	    일직선상*/


		b.Update();
		b.Render();

		E.Update(b.bullet_x,b.bullet_y);
		E.Render();
		E2.Update(b.bullet_x, b.bullet_y);
		E2.Render();
		E3.Update(b.bullet_x, b.bullet_y);
		E3.Render();
		E4.Update(b.bullet_x, b.bullet_y);
		E4.Render();

		p.Input();
		p.Render();
		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		{
			// Bullet.shot()
			std::cout << "\n SPACE  ";
			bullet_x = (p.player_x + 0.05);
			bullet_y = (p.player_y + 0.1f);
			b.Shot(bullet_x, bullet_y);

			std::cout << "\nX: " << bullet_x << "  Y:  " << bullet_y;
		}

		Collider(enemy_x, enemy_y, player_x, player_y);

		// bullet ----------------------------



		glfwSwapBuffers(window); // 그리는ㄴ 모습이 나오지 않도록 버퍼끼리 스왑해주며 더블버퍼 스왑
		glfwPollEvents(); // 쌓아뒀다가 사용
		//if (GetAsyncKeyState(VK_F1) & 0x0001)
		//{

		//}
	}
	_CrtDumpMemoryLeaks();
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
