#pragma once
#include "Include.h"

class Item	//@10-1
{
	typedef struct Item1
	{
		bool show;	//아이템이 나타나있나, 아닌가
		int ItemState;	//ITEM_NO(0) 또는 ITEM_YES(1)
	};

public:
	Item();
	~Item();

	Item1 ItemArr1[18][30];

	Sprite Itemimg1;	//아이템1 이미지 (고양이 모두 기절)
	Sprite gyeokja;		//격자 이미지

	bool ShowItemArr;	//트랩의 격자 보여주기

	//int x1, y1;			//아이템1의 좌표
	//int x2, y2;			//아이템2의 좌표


	void Init();
	void Update();
	void Draw();

	void Reset();		//@10-2 아이템 초기화
	void PushItem(int pos);		//@14-1 함수 정리만
};

extern Item item;