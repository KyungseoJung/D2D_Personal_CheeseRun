#pragma once
#include "Include.h"

class Block									//@7-1
{			
	typedef struct MapBlock
	{
		int BlockState;						//MAP_EMPTY, MAP_BLOCK. MAP_BROKEN 차례대로 0, 1, 2 + MAP_TRAP이면 3
		int CrushState;						//부숴진 정도 - 블록이 있는 경우, 3의 크기씩 갖고 있음. 0이면 다 부숴진 것.
	};

public:
	Block();
	~Block();

	MapBlock BlockArr[18][30];				//맵 배열		//int BlockArr[30][18];	이거 아님. 헷갈리지 말자. 다시 생각해
	//MAP_EMPTY(0), MAP_BLOCK(1), MAP_BROKEN(2), MAP_TRAP(3), MAP_ITEM(4)

	Sprite Blockimg1, Blockimg2, Blockimg3;	//부숴진만큼 블록 이미지 보여주도록(각각 CrushState가 2/ 1/ 0일 때)
//@6-1-2	맵 배열 ==================================
	Sprite gyeokja;							//격자 이미지
	Sprite map_Block;						//블록 이미지

	bool ShowBlockArr;						//맵의 격자 보여주기

	DWORD BlockMakeTime;					//부서진 블록(MAP_BROKEN) 시간 지나면, 다시 생기도록(MAP_BLOCK)

	void Init();
	void Update();
	void Draw();

	void CrushBlock();						//@11-2
	void PushBlock(int pos);				//@14-1 함수 정리만
};

extern Block block;