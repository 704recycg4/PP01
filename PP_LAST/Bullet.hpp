#pragma once
#include "GameObject.hpp"
#include <Windows.h>
#include <GLFW/glfw3.h>

#include "Collider.hpp"

#pragma once
class Bullet : public GameObject
{
private:
    float bullet_speed = 0.07f;
public:
    float bullet_x;
    float bullet_y;

    Bullet()
    {

    }
    ~Bullet() {}

    void Shot(float x, float y)
    {
        this->bullet_x = x;
        this->bullet_y = y;
    }

    void Update()
    {
        bullet_y += bullet_speed;
    }
    void Render()
    {
        glBegin(GL_POINTS);
        glColor3f(0.811, 1, 0.9);
        glVertex2f(bullet_x, bullet_y);
        
        glEnd();
        glPointSize(5);
    }
};
