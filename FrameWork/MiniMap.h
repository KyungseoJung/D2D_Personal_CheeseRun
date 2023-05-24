#pragma once
#include "Include.h"

class MiniMap	//@16-1
{

public:
	MiniMap();
	~MiniMap();

	Sprite MiniMapimg;
	Sprite Targetimg;
	Sprite Monsterimg;
	
	Sprite Blockimg;
	Sprite Itemimg;
	Sprite Trapimg;

	bool ShowAll;			//전체 미니맵 보이게 하는 모드
	bool ShowItem;			//블록 속 아이템 보이게 하는 모드

	double t_mx, t_my;		//타겟의 미니맵 좌표
	double m_mx, m_my;		//몬스터의 미니맵 좌표

	//double mini_x, mini_y;			//@16-2 미니맵이 보여지는 좌표 조정

	void Init();
	void Update();
	void Draw();
};

extern MiniMap minimap;