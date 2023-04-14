#pragma once
#include "Include.h"

class Bomb
{
	typedef struct BombBomb
	{
		//@2-4 ==============================================================
		bool Bomb_Life;				//@2-4 폭탄이 살았나 죽었나	-	key에 space누르면 폭탄 살아있는 상태(true) / 죽은 상태(false)
		
		DWORD m_BombLifeTime;		//@2-4 (총) 폭탄 터지는 시간 조정용 변수	- 값을 입력하는 게 아님. GetTickCount64랑 같이 계산되는 변수. 처음부터 0 

		int BombSecond;				//@2-4 (실시간) 폭탄 살아있는 시간	- 폭탄 수명 시간 조절 가능 - InstallBomb(int BombSecond)함수에서 값 입력함.
	
	  //@11-1 이 변수 대신 배열로 위치 지정
	//	double Bomb_x;			//@2-4 스페이스바로 폭탄 놓은 x위치
	//	double Bomb_y;			//@2-4 스페이스바로 폭탄 놓은 y위치
	
		//@3-1 =============================================================
		bool Bomb_burst;			//@3-1 폭탄 터짐(true), 폭탄 안 터짐(false)

		DWORD m_BurstLifeTime;		//@3-1 (총) 연기 나오는 시간 조정 
		
		int BurstSecond;			//@3-1 (실시간)연기 살아있는 시간 - InstallBomb함수에서 상수로 값 설정
		int BombYesNo = BOMB_NO;				//@11-1 BOMB_YES 또는 BOMB_NO
	};

public:
	Bomb();
	~Bomb();

	BombBomb BombArr[18][30];		//@11-1 폭탄이 놓여있나, 아닌가 배열
	
	Sprite Bombimg[8];			//@ 폭탄 이미지 넣을 배열	//@3-1 private 위쪽에서 public으로 위치 옮김
	Sprite BombBurstimg[10];	//@3-1 폭탄 터졌을 때 이미지	

	DWORD m_BombAniTime;		//@2 폭탄 이미지 재생 관련 변수
	DWORD m_BurstAniTime;		//@3-1 폭탄 터졌을 때 이미지 재생 관련 변수
	
	int m_BombCount;			//@2 폭탄 이미지 재생 관련 변수
	int m_BurstCount;			//@3-1 폭탄 터졌을 때 이미지 재생 관련 변수
	int BombPushCount;			//@12-1 폭탄 밀려나는 거 그리기 속도 조절 함수
	int BombNumber;				//@2-5 현재 화면에 나온 폭탄의 개수	//key.cpp에서 SPACE 누를 때마다 증가하도록
	int BombNumberlimit;		// 개수 제한은 생성자에서


	void Init();
	void Update();
	void Draw();

	void Reset();						//@4-1	초기화 할 때, 설정
	void InstallBomb(int BombSecond);	//@11-1 정리 목적으로 key.cpp에서 코드 가져옴
	void PushBomb(int pos);				//@12-1 폭탄 미는 함수
};

extern Bomb bomb;