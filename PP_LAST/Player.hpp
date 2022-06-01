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
    void Render()
    {

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f + player_x, 0.1f + player_y); // 1 

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.1f + player_x, 0.1f + player_y);// 2

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f + player_x, 0.0f + player_y);// 3

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.1f + player_x, 0.1f + player_y); // 1

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f + player_x, 0.0f + player_y);// 2

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.1f + player_x, 0.0f + player_y);// 3

        glEnd();
    }
};
