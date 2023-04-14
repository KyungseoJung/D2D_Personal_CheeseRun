#include "Include.h"

Map map;


Map::Map()
{
	m_Stage = 1;
}

Map::~Map()
{
}

void Map::Init()
{
	//int i,j;
	char FileName[256];
	
	//@2-1 기존 포세이돈 그림 for문 3개 지우고, 새로운 배경 그림 넣음 - 배열 2_1만 이용, 2_2, 2_3은 아예 안 쓰도록
	sprintf_s(FileName, "./resource/Img/Map/Map2.png");
	m_MapImg1_1.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	
}

void Map::Update(double frame)
{

}

void Map::Draw()
{
	
	if(m_Stage==1)
	{
		m_MapImg1_1.Render(0, -10, 0, 1, 1);		//@2-1 맵 설정	(윗 줄에 약간 흰색 선처럼 보여서 조금 위로 옮김)	
	}
}
