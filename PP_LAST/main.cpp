#define _CRT_SECURE_NO_WARNINGS

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <crtdbg.h>

#include <string>
#include <iostream>

#include "Collider.hpp"
#include "Bullet.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

#pragma comment(lib,"OpenGL32")

static GLuint player_tex;

typedef struct tagBITMAPHEADER {
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;
	RGBQUAD hRGB[256];
}BITMAPHEADER;

BYTE* LoadBitmapFile(BITMAPHEADER* bitmapHeader, int* imgSize, const char* filename)
{
	FILE* fp = fopen(filename, "rb");	//������ �����б���� ����
	if (fp == NULL)
	{
		printf("���Ϸε��� �����߽��ϴ�.\n");	//fopen�� �����ϸ� NULL���� ����
		return NULL;
	}
	else
	{
		fread(&bitmapHeader->bf, sizeof(BITMAPFILEHEADER), 1, fp);	//��Ʈ��������� �б�
		fread(&bitmapHeader->bi, sizeof(BITMAPINFOHEADER), 1, fp);	//��Ʈ��������� �б�
		fread(&bitmapHeader->hRGB, sizeof(RGBQUAD), 256, fp);	//�����ȷ�Ʈ �б�

		int imgSizeTemp = bitmapHeader->bi.biWidth * bitmapHeader->bi.biHeight ;	//�̹��� ������ ���
		*imgSize = imgSizeTemp;	// �̹��� ����� ���� ������ �Ҵ�

		BYTE* image = (BYTE*)malloc(sizeof(BYTE) * imgSizeTemp*3 );	//�̹��� ũ�� ��ŭ �޸��Ҵ�____________________

		// ���ο� �迭�� GBR�� RGB�� �ٲٱ�

		//for(int i = 0 ;i<)


		//std::cout << imgSizeTemp/8 << "\n";
		//std::cout << imgSizeTemp << "\n";
				



		fread(image, sizeof(BYTE), imgSizeTemp*3 , fp);          //�̹��� ũ�⸸ŭ ���Ͽ��� �о����
		fclose(fp);


		return image;
	}
}

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
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
	glfwMakeContextCurrent(window); // ������ �̺�Ʈ ��ƿ� ����ϰڴ�// ��ģ��
	glfwSetKeyCallback(window, key_callback);

	float ratio;
	int width, height;

	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;

	//_______________________________________________________
	float enemy_x = 0, enemy_y = 0;
	float player_x = 0, player_y = 0;
	float bullet_x = 0, bullet_y = 0;

	Bullet b;
	Player p;

	// patten _ 1_________________________
	Enemy E1(-0.5f, 0);
	Enemy E2(-0.8f, 0);
	Enemy E3(-1.1f, 0);
	Enemy E4(-1.4f, 0);

	// patten _ 2_________________________
	Enemy E5(0.5f, 0);
	Enemy E6(0.8f, 0);
	Enemy E7(1.1f, 0);
	Enemy E8(1.4f, 0);

	// patten _ 3_________________________
	Enemy E9( 0.5f, -0.1f);
	Enemy E10(0.8f, -0.1f);
	Enemy E11(1.1f, -0.1f);
	Enemy E12(1.4f, -0.1f);


	Enemy ETest(-1.0f,0.01f);
	//______________________________________________________
	//glClearColor(0.0, 0.0, 0.0, 0.0);

	BYTE B = NULL;
	BYTE G = NULL;
	BYTE R = NULL;




	BITMAPHEADER originalHeader;	//��Ʈ���� ����κ��� ���Ͽ��� �о� ������ ����ü
	int imgSize;			//�̹����� ũ�⸦ ������ ����
	BYTE* image = LoadBitmapFile(&originalHeader, &imgSize, "Player.bmp"); //��Ʈ�������� �о� ȭ�������� ����
	//--------------------------------------
	if (image == NULL) return;        //���� �б⿡ �����ϸ� ���α׷� ����

	for (int i = 1; i < imgSize*3; i+=3)
	{
		B = image[i];
		G = image[i+1];
		R = image[i+2];

		image[i]=R;
		image[i + 1]=G;
		image[i + 2]=B;

	}



	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &player_tex);
	glBindTexture(GL_TEXTURE_2D, player_tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, image);


	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		b.Update();
		b.Render();


		//E1.Update(b.bullet_x,b.bullet_y);
		//E1.Patten(1);
		//E1.Render();

		//E2.Update(b.bullet_x, b.bullet_y);
		//E2.Patten(1);
		//E2.Render();

		//E3.Update(b.bullet_x, b.bullet_y);
		//E3.Patten(1);
		//E3.Render();

		//E4.Update(b.bullet_x, b.bullet_y);
		//E4.Patten(1);
		//E4.Render();

		//// --------------------------------

		//E5.Update(b.bullet_x, b.bullet_y);
		//E5.Patten(-1);
		//E5.Render();

		//E6.Update(b.bullet_x, b.bullet_y);
		//E6.Patten(-1);
		//E6.Render();

		//E7.Update(b.bullet_x, b.bullet_y);
		//E7.Patten(-1);
		//E7.Render();

		//E8.Update(b.bullet_x, b.bullet_y);
		//E8.Patten(-1);
		//E8.Render();

		//// --------------------------------

		//E9.Update(b.bullet_x, b.bullet_y);
		//E9.Patten(-1);
		//E9.Render();

		//E10.Update(b.bullet_x, b.bullet_y);
		//E10.Patten(-1);
		//E10.Render();

		//E11.Update(b.bullet_x, b.bullet_y);
		//E11.Patten(-1);
		//E11.Render();

		//E12.Update(b.bullet_x, b.bullet_y);
		//E12.Patten(-1);
		//E12.Render();

		ETest.Update(b.bullet_x, b.bullet_y);
		ETest.Patten3(1);
		ETest.Render();

		p.Input();
		p.Render(player_tex);
		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		{
			// Bullet.shot(); 
			std::cout << "\n SPACE  ";
			bullet_x = (p.player_x);
			bullet_y = (p.player_y);
			b.Shot(bullet_x, bullet_y);

			std::cout << "\nX: " << bullet_x << "  Y:  " << bullet_y;
		}

		//bullet-----------------------------
		glFlush();
		glDisable(GL_TEXTURE_2D);

		glfwSwapBuffers(window); // �׸��� ����� ������ �ʵ��� ���۳��� �������ָ� ������� ����
		glfwPollEvents(); // �׾Ƶ״ٰ� ���
	}
}
