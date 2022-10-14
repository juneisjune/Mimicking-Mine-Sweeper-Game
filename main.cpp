#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main()
{
	Screen screen(10, 10);

	Player player{ 2, 4, screen };

	Enemy enemy1{ rand() % 10, rand() % 10, screen };
	
	while (1)
	{
		screen.clear();

		screen.draw(player.getPos(), player.getShape());
		screen.draw(enemy1.getPos(), enemy1.getShape());

		screen.render();
		
		
		player.update();
		enemy1.update();
	}
	
	return 0;
}