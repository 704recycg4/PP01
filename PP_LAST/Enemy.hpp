#pragma once
#include "GameObject.hpp"
#include <Windows.h>
#include <GLFW/glfw3.h>
#include <cmath>

#include "Collider.hpp"
#include "Bullet.hpp"

#pragma once

class Enemy : public GameObject
{
private:

public:
    bool isDead = false;
    bool dct = true;



    double enemy_x;
    double enemy_y;



    float bullet_x;
    float bullet_y;

    bool enemy_UP = false;

    float EnemyWayspeed = 0.01f;


    Enemy(float x, float y)
    {
        enemy_x = x;
        enemy_y = y;
    }
    ~Enemy(){}

    void Update(float bullet_x, float bullet_y)
    {
        if (!isDead)
        {
            if (Collider_bullet(enemy_x, enemy_y, bullet_x, bullet_y))
            {
                std::cout << "충돌";
                isDead = true;
            }
        }
    }

    void Standby()
    {
        enemy_x = 0;
        enemy_y = 0;
    }

    void Attack(float enemy_x, float player_y)
    {
        enemy_y=(player_y / enemy_x)* enemy_x + player_y;
 
        // 함수 시작한 순간의 플레이어 좌표 받기
        // 
    }

    void Patten(float Direction)
    {
        if (!isDead)
        {
            enemy_x += EnemyWayspeed * Direction;

            if (enemy_y > 0.1) {
                enemy_UP = true;
            }
            if (enemy_y < 0)
            {
                enemy_UP = false;
            }

            if (enemy_UP) {
                enemy_y -= EnemyWayspeed;
                //std::cout << "up";
            }
            if (!enemy_UP)
            {
                enemy_y += EnemyWayspeed; ;
                //std::cout << "down";
            }

            
        }
    }

    void Patten2(float Direction)
    {
        if (!isDead)
        {
         enemy_x += EnemyWayspeed * Direction;
         enemy_y = (sqrt(1- (enemy_x* enemy_x*5)));
         if (enemy_x > 0.4)
         {
             Direction*-1;
         }

         //enemy_y -= 0.3;
        }

        /*std::cout << enemy_x<<"\n";
        std::cout << enemy_y << "\n";*/
        //std::cout.precision(3);
        //std::cout << round(sqrt(1 - (enemy_x * enemy_x))) << "\n";

    }
    void Patten3(float Direction)
    {
        
        if ( dct) {
            enemy_x += EnemyWayspeed;
            if ( -0.3 < enemy_x && enemy_x < 0)enemy_y = enemy_x + 0.3; std::cout << "1" << "\n";      //1
            if ( 0 < enemy_x && enemy_x < 0.3)enemy_y = -enemy_x + 0.3;   std::cout << "2" << "\n";   //2
            if (enemy_x > 0.3) dct = false;
            
        }
        if ( !dct)
        {
            enemy_x -= EnemyWayspeed;
            if (0 < enemy_x && enemy_x < 0.4)enemy_y = enemy_x - 0.3;  std::cout << "3" << "\n"; //3
            if (-0.3 < enemy_x && enemy_x < 0) enemy_y = -(enemy_x + 0.3); std::cout << "4" << "\n";//4
            if (enemy_x < -0.3) dct = true;
        }


        //std::cout << enemy_x<<"\n";
        //std::cout << enemy_y << "\n";
    }

    void Patten4(float Direction)
    {
        
        if (enemy_x < 0.3&& dct) 
        {
            enemy_x += EnemyWayspeed;
        }else if (enemy_x > 0.3&& dct)
        {
            dct = false;;

        }if (enemy_x > -0.3 && !dct)
        {
            enemy_x -= EnemyWayspeed;
        }
        else if ((enemy_x < -0.3 && !dct))
        {
            dct = true;
        }


        if (enemy_x > 0.3) {
            Direction *= -1;
            std::cout << "Direction : " << Direction << "\n";
        }


        //std::cout << enemy_x<<"\n";
        //std::cout << enemy_y << "\n";
    }


    void Render()
    {
        if (!isDead)
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
    }
};
