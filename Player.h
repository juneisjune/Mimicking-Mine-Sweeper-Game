#pragma once
#include "GameObject.h"
#include <conio.h>

class Player :public GameObject
{

public:
	Player(int x, int y) : GameObject('>', x, y) {}

	void update() override //������ update �Լ��� �������̵� �� ������ �Լ��� �ٽ� ���ڴ�.
	{
		processInput(); //���� ����� ����� �����ų������
		//api�ܺο� ����Ǵ� �Լ�
	}

	void processInput()
	{
		char key;
		if (~_kbhit() == 0)  return ;
		Borland::GotoXY(0, 21);
		key = _getch();
		//��ũ�� ���� ���� �ִ� �͵� �����ؾ�
		printf("key is %c %d\n", key, key);
		
		//_kbhit �տ� ����ٰ� �ִ� ������ c++  ���Ĵٵ� �Լ��� �ƴ϶�� ���� �ǹ��� 
		//bool �ڷ����� c++�� �ִ� �ڷ����� c������ ��� 0���� ǥ��

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

