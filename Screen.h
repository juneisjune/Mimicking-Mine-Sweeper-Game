#pragma once
#include <iostream>
#include<Windows.h>
#include "Utils.h"

using namespace std;

class Screen
{
	char* lines;
	int n_rows;
	int n_cols;

	int pos2offset(int x, int y, int n_cols)
	{
		return y * n_cols + x;
	}

public:
	Screen(int n_rows, int n_cols) : n_rows(n_rows), n_cols(n_cols), lines(new char[n_rows * n_cols + 1])
	{
		Borland::Initialize();
		clear();
	}

	virtual ~Screen() { delete[] lines; }

	void clear()
	{
		memset(lines, ' ', n_rows * n_cols);
		//memset(memomry + setting)= 함수는 메모리의 내용을 원하는 크기만큼 특정 값으로 세팅할수 있는 함수
		//첫번째인자= 그 주소를 가리키고 있는 포인터가 우치하는 자리
		//두번째인자= 메로리에 세팅하고자 하는 값을 집어 넣으면 됨
		//세번째인자= 바이트 단위 메모리의 크기 한조각 단위의 길이
		for (int i = 0; i <= n_rows; i++)
		{
			
			lines[i * n_cols + n_rows -1]= 'O';
			lines[i * n_cols + n_rows] = '\n';
			int j = 0;
			if (j == n_rows)
			{
				int z = 0;
				while (z < n_cols)
				{
					lines[n_rows * n_cols - (n_cols - z)] = '0';
				}
			}
			j++;
		}
		
		
		lines[n_rows * n_cols] = '\0';
	}

	void draw(const Position& pos, char shape)
	{
		int offset = pos2offset(pos.x, pos.y, n_cols);

		lines[offset] = shape;
	}
	//void drawRestrainOfMap()
	//{
	//	if()
	//	printf("ㅁ")
	//}

	void render()
	{
		Borland::GotoXY(0, 0);
		printf("%s", lines);
		Sleep(100);
	}
};

