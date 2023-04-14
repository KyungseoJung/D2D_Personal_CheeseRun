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

	bool ShowAll;			//��ü �̴ϸ� ���̰� �ϴ� ���
	bool ShowItem;			//��� �� ������ ���̰� �ϴ� ���

	double t_mx, t_my;		//Ÿ���� �̴ϸ� ��ǥ
	double m_mx, m_my;		//������ �̴ϸ� ��ǥ

	//double mini_x, mini_y;			//@16-2 �̴ϸ��� �������� ��ǥ ����

	void Init();
	void Update();
	void Draw();
};

extern MiniMap minimap;