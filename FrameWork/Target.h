#pragma once
#include "Include.h"

class Target
{
	Sprite Tgimg[13];		//@2-3 제리로 그림 변경


public :
	Target();
	~Target();

	//@1 타겟 효과와 총알 효과가 화면에 나오는 타이밍을 각각 다르게 하기 위함
	DWORD AniTime1;

	//@4-1 제리(타겟) 사망 유무 변수 / 죽으면 = 게임 LOSE
	bool Target_Life = true;	//제리 살아있다. 처음 Include.h 파일로 갈 때 true로 들어가도록

	int pos;					//타겟이 움직이는 방향(RIGHT 또는 LEFT) - key.cpp에서 설정하도록
	int m_TgCount1;
	double t_x;					//@1 타겟의 X축 좌표 //실시간 위치
	double t_y;					//@1 타겟의 Y축 좌표 //실시간 위치

	void Init();
	void Update();
	void Draw();
	void CheckLife();			//@4-1 몬스터와의 거리 계산해서, 타겟(제리) 살아있나 확인하는 함수
	void Reset();
};

extern Target target;