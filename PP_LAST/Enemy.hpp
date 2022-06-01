#pragma once
#include "GameObject.hpp"
#include <Windows.h>
#include <GLFW/glfw3.h>

#include "Collider.hpp"
#include "Bullet.hpp"

#pragma once
class Enemy : public GameObject
{
private:

public:
    float enemy_x;
    float enemy_y;
    bool enemy_UP = false;
    float bullet_x;
    float bullet_y;


    Enemy(float x, float y)
    {
        enemy_x = x;
        enemy_y = y;
    }
    ~Enemy() {}

    void Update(float bullet_x,float bullet_y)
    {
        enemy_x += 0.001f;

        //if (enemy_y > 0.1) {
        //    enemy_UP = true;
        //}
        //if (enemy_y < 0)
        //{
        //    enemy_UP = false;
        //}

        //if (enemy_UP) {
        //    enemy_y += (0.2 * enemy_x) ;
        //    //std::cout << "up";
        //}
        //if (!enemy_UP)
        //{
        //    enemy_y += (-0.2 * enemy_x) ;
        //    //std::cout << "down";
        //}
        Collider_bullet(enemy_x, enemy_y, bullet_x, bullet_y);
    }
    void Render()
    {
        glBegin(GL_TRIANGLES);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
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

    }

};