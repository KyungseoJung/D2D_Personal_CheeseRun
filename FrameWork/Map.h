#pragma once
#include "Include.h"

class Map
{

public :
	Map();
	~Map();
	Sprite test;
	bool tests;

	Sprite m_MapImg1_1;			//@4-1 �׸� �ϳ� (����ȭ�� Forestmap2-3)

	int m_Stage;


	void Init();
	void Update(double frame);
	void Draw();
};

extern Map map;