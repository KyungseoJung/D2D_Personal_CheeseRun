#include "Include.h"

Score score;

extern FmodSound ScoreSound;	//@14-2	사운드 추가

Score::Score()
{
	/*	// 나중에 그림 여러개 쓸 때 사용할 변수 // 
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

	sprintf_s(FileName, "./resource/Img/Score/Baby.png");		//@7-2 아기 쥐 이미지
	BabyMouse.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Score/Showscore.png");		//@10-7 먹은 치즈 개수
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
	cheese[num].eat = false;		//처음 만들 땐, 안 먹은 상태니까
}

void Score::Reset()	//@5-2 놓아야 하는 위치 : 가로(0~1280), 세로(0~768) 이내에. rand()로 표현할 수도 있긴 함~
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

	FoodNumber = 10;	//0번부터 n번까지니까 n+1개
	GetFoodNumber = 0;

	baby.show = false;	//@7-2 리셋!
	baby.win = false;
}

void Score::Update()
{
	if (Gmanager.m_GameStart == true)
	{
		//(만약 치즈 안 먹은 상태&& 타겟(제리) 살아있으면) - 거리 계산 후 거리 가까우면 - 치즈 먹은 상태로 변경(cheese[num].eat = true)
		for (int i = 0; i < FoodNumber; i++)
		{

			if ((cheese[i].eat == false) && (target.Target_Life == true))
			{
				float distance = (float)sqrt((cheese[i].Food_x - target.t_x) * (cheese[i].Food_x - target.t_x) +
					(cheese[i].Food_y - target.t_y) * (cheese[i].Food_y - target.t_y));

				if (distance < 40)
				{
					cheese[i].eat = true;	//치즈 먹었다!
					GetFoodNumber++;
					ScoreSound.EffectPlay(Gmanager.GetScoreSound);	//@14-2 점수 먹을 때 효과음
				}
			}
		}
	
		if (GetFoodNumber == FoodNumber)	//치즈 다 먹으면 아기 쥐 나타나도록
		{
			baby.show = true;
				
			//타겟과 아기 쥐의 거리
			float distance = (float)sqrt((baby.x - target.t_x) * (baby.x - target.t_x) +
				(baby.y - target.t_y) * (baby.y - target.t_y));

			if ((score.GetFoodNumber == score.FoodNumber) && (distance < 60))	//치즈 다 먹고 && 아기 쥐한테 다다르면 게임 WIN
			{
				baby.win = true;	//GameManger.cpp 에서 승리조건에 적용됨
			}

		}
	}
}

void Score::Draw()
{
	for (int i = 0; i < FoodNumber; i++)
	{
		if ((Gmanager.m_GameStart == true) && (cheese[i].eat == false))	//치즈 아직 안 먹힌 상태이면 그림 띄운다.
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
	ShowscoreNum[GetFoodNumber].Render(1130, 20, 0, 0.5, 0.5);	//@10-7 먹은 치즈 개수만큼 숫자 띄우기
}


