#pragma once
#include "Include.h"


class Monster
{
	typedef struct Mon
	{
		bool life;							// 기절(false), 깨어남(true)

		DWORD m_SleepLifeTime;				//@3-3-3 각 몬스터의 (총) 기절 시간 조정 - 값을 입력하는 게 아님. GetTickCount64랑 같이 계산되는 변수. 처음부터 0 

		int pos;							// 향하는 방향 (RIGHT 또는 LEFT)
		int m_SleepSecond;					//@3-3-3 각 몬스터의 (실시간) 남아있는 기절 시간 - 기절 시간 조절 - Monster.cpp 내 Boom 함수에서 m_Boom1 = true 됐을 때, 시간 설정

		double m_x, m_y;					// 실시간 위치
		double speed;
		double scale;
		double w;							//@3-5-2 필요할 수도 있겠다!! 실제위치와 눈에 보이는 위치 거리 조정용	//@1 몬스터 Draw 할 때, RIGHT로 이동하는 몬스터는 약간 위치를 이동해서 그려줄 때. 쓰는 변수

	
	};


public:
	Monster(void);
	~Monster(void);

	Mon cat[4];						//@2-2 2->3 으로 변경 //일단 물고기 3종류 라고 해두기(물고기 2, 고양이 1)	//@3-5-1 fish[3]에서 4로 변경

	Sprite catimg1[6], Sleepimg;	//@1 각각의 이미지 개수만큼 배열 설정 - 연속 사진(애니메이션) 효과
	Sprite FollowZone;

	//@3-3 나중에 변수명 바꿔주기============================================
	DWORD BoomTime1;				//이름 변경 : SleepTime		//@3-3 연기 맞았을 때, 잠드는 시간
	DWORD MonsterMoveTime;
	DWORD MonsterCountTime;
	DWORD FollowTime;				//몬스터가 따라오는 시간 조절


	int MonsterCount;				//@3-5-1 몬스터 수 - 하나하나 나타내기 너무 힘드니까. //할 거면 Reset함수에서 설정해주자
	int m_Acount, m_Bulletcount;



	void GoodFunction(double m_x, double m_y, double speed,				//@1 몬스터 관련 - 위치, 점수, 속도, 규모, 
		int pos, double w, int num);

	void Init();
	void Update();
	void Draw();

	void Boom();
	void Follow(int num);	//@10-4 거리 가까워지면 n번째 몬스터가 타겟을 따라가도록
	void Reset();

};

extern Monster monster;