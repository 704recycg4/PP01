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
	FILE* fp = fopen(filename, "rb");	//파일을 이진읽기모드로 열기
	if (fp == NULL)
	{
		printf("파일로딩에 실패했습니다.\n");	//fopen에 실패하면 NULL값을 리턴
		return NULL;
	}
	else
	{
		fread(&bitmapHeader->bf, sizeof(BITMAPFILEHEADER), 1, fp);	//비트맵파일헤더 읽기
		fread(&bitmapHeader->bi, sizeof(BITMAPINFOHEADER), 1, fp);	//비트맵인포헤더 읽기
		fread(&bitmapHeader->hRGB, sizeof(RGBQUAD), 256, fp);	//색상팔렛트 읽기

		int imgSizeTemp = bitmapHeader->bi.biWidth * bitmapHeader->bi.biHeight ;	//이미지 사이즈 계산
		*imgSize = imgSizeTemp;	// 이미지 사이즈를 상위 변수에 할당

		BYTE* image = (BYTE*)malloc(sizeof(BYTE) * imgSizeTemp*3 );	//이미지 크기 만큼 메모리할당____________________

		// 새로운 배열로 GBR을 RGB로 바꾸기

		//for(int i = 0 ;i<)


		//std::cout << imgSizeTemp/8 << "\n";
		//std::cout << imgSizeTemp << "\n";
				



		fread(image, sizeof(BYTE), imgSizeTemp*3 , fp);          //이미지 크기만큼 파일에서 읽어오기
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




	BITMAPHEADER originalHeader;	//비트맵의 헤더부분을 파일에서 읽어 저장할 구조체
	int imgSize;			//이미지의 크기를 저장할 변수
	BYTE* image = LoadBitmapFile(&originalHeader, &imgSize, "Player.bmp"); //비트맵파일을 읽어 화소정보를 저장
	//--------------------------------------
	if (image == NULL) return;        //파일 읽기에 실패하면 프로그램 종료

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

		glfwSwapBuffers(window); // 그리는 모습이 나오지 않도록 버퍼끼리 스왑해주며 더블버퍼 스왑
		glfwPollEvents(); // 쌓아뒀다가 사용
	}
}
