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

		int imgSizeTemp = bitmapHeader->bi.biWidth * bitmapHeader->bi.biHeight;	//�̹��� ������ ���
		*imgSize = imgSizeTemp;	// �̹��� ����� ���� ������ �Ҵ�

		BYTE* image = (BYTE*)malloc(sizeof(BYTE) * imgSizeTemp * 3);	//�̹��� ũ�� ��ŭ �޸��Ҵ�____________________



		fread(image, sizeof(BYTE), imgSizeTemp * 3, fp);          //�̹��� ũ�⸸ŭ ���Ͽ��� �о����
		fclose(fp);

		

		return image;
	}
}

void Render(const char *textureName)
{
	BYTE B = NULL;
	BYTE G = NULL;
	BYTE R = NULL;


	BITMAPHEADER originalHeader;	//��Ʈ���� ����κ��� ���Ͽ��� �о� ������ ����ü
	int imgSize;			//�̹����� ũ�⸦ ������ ����
	BYTE* image = LoadBitmapFile(&originalHeader, &imgSize, textureName); //��Ʈ�������� �о� ȭ�������� ����
	//--------------------------------------
	if (image == NULL) return;        //���� �б⿡ �����ϸ� ���α׷� ����

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