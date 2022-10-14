#pragma once
#include "GameObject.h"
#include <conio.h>

class Player :public GameObject
{

public:
	Player(int x, int y) : GameObject('>', x, y) {}

	void update() override //기존의 update 함수를 오버라이딩 즉 기존의 함수를 다시 쓰겠다.
	{
		processInput(); //내가 만드는 기능을 노출시킬것인지
		//api외부에 노출되는 함수
	}

	void processInput()
	{
		char key;
		if (~_kbhit() == 0)  return ;
		Borland::GotoXY(0, 21);
		key = _getch();
		//스크린 범위 내에 있는 것도 구현해야
		printf("key is %c %d\n", key, key);
		
		//_kbhit 앞에 언더바가 있는 이유는 c++  스탠다드 함수가 아니라느 것을 의미함 
		//bool 자료형은 c++에 있는 자료형임 c에서는 없어서 0으로 표현

		Position pos = getPos();

		switch (key) {
		case 'w':
			pos.y--;
			break;
		case 'a':
			pos.x--;
			break;
		case 's':
			pos.y++;
			break;
		case 'd':
			pos.x++;
			break;
		}

		setPos(pos);

	}
};

