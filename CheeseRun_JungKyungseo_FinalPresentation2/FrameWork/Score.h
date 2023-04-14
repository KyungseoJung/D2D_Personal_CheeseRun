#pragma once
#include "Include.h"

class Score					//@5-1 
{
	//@5-1 �� ġ�� ���� ��ġ, ���� ����
	typedef struct Food
	{
		bool eat;						//Ÿ��(����)�� �Ծ���. true�̸� ġ�� ���� �� = ȭ�鿡 ���̸� �� ��. life�� �ݴ� �ǹ̷� �ۿ�
		int num;						//�� ��° ġ���	(�� num <= CheeseNumber ���� ��)
		double Food_x, Food_y;			//�� ġ���� ��ġ/ ��ǥ
	};

	//@7-2
	typedef struct Baby		//�������� ���� ����
	{	
		bool show;			//ġ�� �� ������ �Ʊ� ���� ��Ÿ������
		bool win;			//ġ�� �� �԰� && �Ʊ� ���㿡 �ٴٸ���, WIN ���� - GameManager.cpp���� �̿�		
		double x;			//�Ʊ� ���� ��ǥ
		double y;
	};

public:
	Score();
	~Score();

	Food cheese[10];			//@7-2 ����ü �迭 ����
	Baby baby;					//@7-2 ����ü ��ü ����

	Sprite Scoreimg;			// ���� �̹��� ���� �迭
	Sprite BabyMouse;			//�Ʊ� ��. ġ�� �� ������ ��Ÿ��. ġ�� �� ���� ���¿��� �� ������ �����ؾ� �¸�
	Sprite Showscore;			//@10-7 ���� ���� ġ�� ���̵���
	Sprite ShowscoreNum[16];		//@10-7 Showscore�� �Բ� ��� ���� �̹���(0���� 15)

	int FoodNumber;				// �� ġ�� ����- Reset �Լ����� �����ְ� ���� - 1�� Ű ������, �������� ġ� ��������
	int GetFoodNumber;			// �� ȹ���� ġ�� ����	- Reset �Լ����� 0���� �ʱ�ȭ����


	void FoodFunction(double Cheese_x, double Cheese_y, int num);		//Monster.cpp �� ���� �ƶ� - Reset���� �����ϱ�

	void Init();
	void Update();
	void Draw();

	void Reset();

};

extern Score score;
