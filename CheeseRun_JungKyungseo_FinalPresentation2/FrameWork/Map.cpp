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
	
	//@2-1 ���� �����̵� �׸� for�� 3�� �����, ���ο� ��� �׸� ���� - �迭 2_1�� �̿�, 2_2, 2_3�� �ƿ� �� ������
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
		m_MapImg1_1.Render(0, -10, 0, 1, 1);		//@2-1 �� ����	(�� �ٿ� �ణ ��� ��ó�� ������ ���� ���� �ű�)	
	}
}
