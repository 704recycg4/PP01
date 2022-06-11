#define _CRT_SECURE_NO_WARNINGS


#include <GLFW/glfw3.h>
#include <stdio.h>
#include <Windows.h>

#include <iostream>
#include <string.h>

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

		int imgSizeTemp = bitmapHeader->bi.biWidth * bitmapHeader->bi.biHeight;	//이미지 사이즈 계산
		*imgSize = imgSizeTemp;	// 이미지 사이즈를 상위 변수에 할당

		BYTE* image = (BYTE*)malloc(sizeof(BYTE) * imgSizeTemp * 3);	//이미지 크기 만큼 메모리할당____________________



		fread(image, sizeof(BYTE), imgSizeTemp * 3, fp);          //이미지 크기만큼 파일에서 읽어오기
		fclose(fp);

		

		return image;
	}
}

void Render(const char *textureName)
{
	BYTE B = NULL;
	BYTE G = NULL;
	BYTE R = NULL;


	BITMAPHEADER originalHeader;	//비트맵의 헤더부분을 파일에서 읽어 저장할 구조체
	int imgSize;			//이미지의 크기를 저장할 변수
	BYTE* image = LoadBitmapFile(&originalHeader, &imgSize, textureName); //비트맵파일을 읽어 화소정보를 저장
	//--------------------------------------
	if (image == NULL) return;        //파일 읽기에 실패하면 프로그램 종료

	for (int i = 1; i < imgSize * 3; i += 3)
	{
		B = image[i];
		G = image[i + 1];
		R = image[i + 2];

		image[i] = R;
		image[i + 1] = G;
		image[i + 2] = B;

	}


	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &player_tex);
	glBindTexture(GL_TEXTURE_2D, player_tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
}