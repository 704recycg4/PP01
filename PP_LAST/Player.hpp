#include "GameObject.hpp"
#include <Windows.h>
#include <GLFW/glfw3.h>

#pragma once
class Player : public GameObject
{
private:
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;

public:
    float player_y;
    float player_x;
    float playerSpeed = 0.015f;

    Player()
    {
        player_y=0;
        player_x=0;
    }
    ~Player() {}

    void Input()
    {
        if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
        {
            player_y += playerSpeed;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
        {
            player_y -= playerSpeed;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
        {
            player_x += playerSpeed;
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
        {
            player_x -= playerSpeed;
        }
    }
    void Attack()
    {

    }
    void Render(GLuint texName)
    {
        glEnable(GL_TEXTURE_2D);

        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glBindTexture(GL_TEXTURE_2D, texName);

        glBegin(GL_TRIANGLES);
        glTexCoord2f(-0.65, 0.0); glVertex3f(-0.1+ player_x, -0.1+ player_y, 0.0); // 왼쪽 점
        glTexCoord2f(0.35, 0.0); glVertex3f(0.1+ player_x, -0.1+ player_y, 0.0); // 오른쪽 점
        glTexCoord2f(-0.15, 1.0); glVertex3f(0.0+ player_x, 0.1+ player_y, 0.0); // 
        //glTexCoord2f(0.0, 1.0); glVertex3f(0.0 + player_x, 0.1 + player_y, 0.0);

        glEnd();
    }
};
