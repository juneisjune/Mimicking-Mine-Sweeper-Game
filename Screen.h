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
		//memset(memomry + setting)= �Լ��� �޸��� ������ ���ϴ� ũ�⸸ŭ Ư�� ������ �����Ҽ� �ִ� �Լ�
		//ù��°����= �� �ּҸ� ����Ű�� �ִ� �����Ͱ� ��ġ�ϴ� �ڸ�
		//�ι�°����= �޷θ��� �����ϰ��� �ϴ� ���� ���� ������ ��
		//����°����= ����Ʈ ���� �޸��� ũ�� ������ ������ ����
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
	//	printf("��")
	//}

	void render()
	{
		Borland::GotoXY(0, 0);
		printf("%s", lines);
		Sleep(100);
	}
};

