#pragma once
#include "GameObject.hpp"
#include <Windows.h>
#include <GLFW/glfw3.h>

#pragma once
class Enemy : public GameObject
{
private:

public:
    float x;
    float y;
    float xp;
    float yp;
    Enemy(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    ~Enemy() {}
    void Input()
    {

    }
    void Update()
    {


    }
    void Render()
    {
        glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(x, y + yp);
        glVertex2f(x + xp, y + yp);
        glVertex2f(x, y);
        glVertex2f(x + xp, y);
        glEnd();
    }
};
