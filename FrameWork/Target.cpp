#include "Include.h"


Target	target;


Target::Target()
{
	t_x = 600;				//@1 타겟(동그라미 과녁)의 x좌표 위치	//실시간 위치
	t_y = 300;				//@1 타겟(동그라미 과녁)의 y좌표 위치	//실시간 위치
}

Target::~Target()
{
}

void Target::Init()
{
	char FileName[256];

	for (int i = 0; i < 13; i++)		//@2-3 제리로 그림 변경하기
	{
		sprintf_s(FileName, "./resource/Img/Target/Mouse/output/Mouse_001_%04d.png", i);
		Tgimg[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
}

void Target::Update()
{


	if(GetTickCount() - AniTime1 > 100)				//@2-3 나오는 속도도 (>1000)에서 (>100)으로 변경
	{
		m_TgCount1++;
		if(m_TgCount1>12) m_TgCount1 = 0;			//@2-3 (m_TgCount1>1) 부분을 12로 변경
		AniTime1 = GetTickCount();
	}

	//@4-1
	CheckLife();

}

//@4-1 <원을 이용한 충돌처리> - 몬스터와의 거리 계산해서, 타겟(제리) 살아있나 확인하는 함수
void Target::CheckLife()
{
	for (int i = 0; i < monster.MonsterCount; i++)		//@3-3-3 i번째 몬스터//@2-2 고양이 추가 (i<2)였던 부분을 (i<3)으로 변경.	//@3-5-1 (i<4)로 변경
	{
		if (Target_Life == true)		//타겟이 살아있다면
		{
			float distance = (float)sqrt((monster.cat[i].m_x - t_x) * (monster.cat[i].m_x - t_x) +
				(monster.cat[i].m_y - t_y) * (monster.cat[i].m_y - t_y));

			if (distance < 50)	// 몬스터와의 거리
			{
				Target_Life = false;	//타겟(제리) 죽음 ㅠ
			}
		}
	}
}

void Target::Draw()
{	
	if((Gmanager.m_GameStart==true)	&& pos == LEFT)				//@1 게임 시작 상태라면 && 왼쪽으로 가고 있다면
		Tgimg[m_TgCount1].Render(t_x, t_y, 0, 0.7, 0.7);		//@ 타겟 그린다. 이 좌표 위치에		//쥐! 제리! 그리기
	else if ((Gmanager.m_GameStart == true) && pos == RIGHT)
		Tgimg[m_TgCount1].Render(t_x + 50, t_y, 0, -0.7, 0.7);	//방향 바꾸면, 좌우 뒤집어서 그린다.
}

void Target::Reset()
{
	t_x = 600;
	t_y = 300;
	
	Target_Life = true;	//@4-1 타겟 살아있다
}