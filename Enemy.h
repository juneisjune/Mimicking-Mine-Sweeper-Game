#pragma once
#include "GameObject.h"
class Enemy : public GameObject
{

public:
    Enemy(int x, int y) : GameObject('*', x, y) {}

    void update() override
    {
        Position pos = getPos();
        int idx = rand() % 9;
        switch (idx)
        {
        case 0:
            pos.x--; pos.y--;
            break;
        case 1:
            pos.y--;
            break;
        case 2:
            pos.x++; pos.y--;
            break;
        case 3:
            pos.x--; 
            break;
        case 4:
            break;
        case 5:
            pos.x++;
            break;
        case 6:
            pos.x--; pos.y++;
            break;            
        case 7:
            pos.x++; pos.y++;
            break;
        case 8:
            break;
        }

        setPos(pos);//원본이 아니니까 내가 복사한 정보를 원본에다가 수정
    }
};

