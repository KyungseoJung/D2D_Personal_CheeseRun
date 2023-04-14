#include "Include.h"

Score score;

extern FmodSound ScoreSound;	//@14-2	���� �߰�

Score::Score()
{
	/*	// ���߿� �׸� ������ �� �� ����� ���� // 
	m_ScoreAniTime = 0;	
	m_ScoreCount = 0;
	*/

}

Score::~Score(){}

void Score::Init()
{
	char FileName[256];

	sprintf_s(FileName, "./resource/Img/Score/Cheese.png");
	Scoreimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Score/Baby.png");		//@7-2 �Ʊ� �� �̹���
	BabyMouse.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Score/Showscore.png");		//@10-7 ���� ġ�� ����
	Showscore.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	
	for (int i = 0; i < 16; i++)	//@10-7
	{
		sprintf_s(FileName, "./resource/Img/Score/CheeseNum/%02d.png", i);		
		ShowscoreNum[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
		
	}

	baby.x = 1200;
	baby.y = 700;
	baby.show = false;
	baby.win = false;
}

void Score::FoodFunction(double x, double y, int num)
{
	cheese[num].Food_x = x;
	cheese[num].Food_y = y;
	cheese[num].eat = false;		//ó�� ���� ��, �� ���� ���´ϱ�
}

void Score::Reset()	//@5-2 ���ƾ� �ϴ� ��ġ : ����(0~1280), ����(0~768) �̳���. rand()�� ǥ���� ���� �ֱ� ��~
{
	FoodFunction(100, 100, 0);
	FoodFunction(200, 100, 1);
	FoodFunction(300, 100, 2);
	FoodFunction(400, 200, 3);
	FoodFunction(500, 200, 4);
	FoodFunction(600, 200, 5);
	FoodFunction(100, 500, 6);
	FoodFunction(200, 500, 7);
	FoodFunction(300, 500, 8);
	FoodFunction(400, 500, 9);

	FoodNumber = 10;	//0������ n�������ϱ� n+1��
	GetFoodNumber = 0;

	baby.show = false;	//@7-2 ����!
	baby.win = false;
}

void Score::Update()
{
	if (Gmanager.m_GameStart == true)
	{
		//(���� ġ�� �� ���� ����&& Ÿ��(����) ���������) - �Ÿ� ��� �� �Ÿ� ������ - ġ�� ���� ���·� ����(cheese[num].eat = true)
		for (int i = 0; i < FoodNumber; i++)
		{

			if ((cheese[i].eat == false) && (target.Target_Life == true))
			{
				float distance = (float)sqrt((cheese[i].Food_x - target.t_x) * (cheese[i].Food_x - target.t_x) +
					(cheese[i].Food_y - target.t_y) * (cheese[i].Food_y - target.t_y));

				if (distance < 40)
				{
					cheese[i].eat = true;	//ġ�� �Ծ���!
					GetFoodNumber++;
					ScoreSound.EffectPlay(Gmanager.GetScoreSound);	//@14-2 ���� ���� �� ȿ����
				}
			}
		}
	
		if (GetFoodNumber == FoodNumber)	//ġ�� �� ������ �Ʊ� �� ��Ÿ������
		{
			baby.show = true;
				
			//Ÿ�ٰ� �Ʊ� ���� �Ÿ�
			float distance = (float)sqrt((baby.x - target.t_x) * (baby.x - target.t_x) +
				(baby.y - target.t_y) * (baby.y - target.t_y));

			if ((score.GetFoodNumber == score.FoodNumber) && (distance < 60))	//ġ�� �� �԰� && �Ʊ� ������ �ٴٸ��� ���� WIN
			{
				baby.win = true;	//GameManger.cpp ���� �¸����ǿ� �����
			}

		}
	}
}

void Score::Draw()
{
	for (int i = 0; i < FoodNumber; i++)
	{
		if ((Gmanager.m_GameStart == true) && (cheese[i].eat == false))	//ġ�� ���� �� ���� �����̸� �׸� ����.
		{
			Scoreimg.SetColor(255, 255, 255, 255);
			Scoreimg.Render(cheese[i].Food_x, cheese[i].Food_y, 0, 1, 1);
		}
	}
	
	if (baby.show == true)
	{
		BabyMouse.SetColor(255, 255, 255, 255);
		BabyMouse.Render(baby.x, baby.y, 0, 0.5, 0.5);
	}

	Showscore.Render(1000, 30, 0, 0.5, 0.5);						//@10-7
	ShowscoreNum[GetFoodNumber].Render(1130, 20, 0, 0.5, 0.5);	//@10-7 ���� ġ�� ������ŭ ���� ����
}


