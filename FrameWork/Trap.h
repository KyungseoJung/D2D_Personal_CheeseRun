#pragma once
#include "Include.h"

class Trap		//@9-1 트랩 클래스. 벡터 이용할 예정
{


public :
	Trap(int x, int y);	//@9-1-2

	Trap();
	~Trap();


	Sprite Trapimg[7];			//트랩 이미지
	Sprite gyeokja;				//격자 이미지	//@9-3

	bool ShowTrapArr;			//트랩의 격자 보여주기	//@9-3

	DWORD TrapCountTime;		//트랩 이미지 카운트 시간
	DWORD TrapMoveTime;			//트랩 움직이는 시간 조절

	int Trap_count;				//@10-2 트랩 이미지 카운트
	int x, y;					//트랩의 좌표		//Update에서 row, col의 위치를 이용해서 나오므로 int로 지정하자	//다른 클래스에서도 쓰니까 public으로 선언
	int TrapArr[18][30];		//트랩의 배열	-	Block.cpp에서 특정 행,열이 MAP_TRAP이도록 Update할 거임
	int pos = UP;				//@10-2 트랩 움직이는 방향 (UP DOWN)
	int speed = 42;				//@10-2 한번에 움직이는 거리


	void Init();
	void Update();
	void Draw();
	
	void Reset();				//key.cpp(1번 키), Over.cpp(F11키)에서 선언하기
	void PushTrap(int pos);		//@14-1 함수 정리만
};

extern Trap trap;