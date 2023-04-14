#include "Include.h"

MiniMap minimap;

MiniMap::MiniMap()
{

}

MiniMap::~MiniMap()
{

}

void MiniMap::Init()
{
	char FileName[256];

	//미니맵 배경
	sprintf_s(FileName, "./resource/Img/MiniMap/MiniMap2.png");
	MiniMapimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//타겟
	sprintf_s(FileName, "./resource/Img/MiniMap/Mouse_MiniMap.png");
	Targetimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//몬스터
	sprintf_s(FileName, "./resource/Img/MiniMap/Cat_MiniMap.png");
	Monsterimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//블록 연출 ================
	//블록(투명도 50)
	sprintf_s(FileName, "./resource/Img/MiniMap/Block_MiniMap.png");
	Blockimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//블록 속 아이템
	sprintf_s(FileName, "./resource/Img/MiniMap/Item_MiniMap.png");
	Itemimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//블록 속 트랩
	sprintf_s(FileName, "./resource/Img/MiniMap/Trap_MiniMap.png");
	Trapimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	
}

void MiniMap::Update()
{

}

void MiniMap::Draw()
{
	//@16-1 전체 화면 보이게 하는 모드 ==========================================

if (ShowAll == TRUE)
{
	//미니맵 배경
	MiniMapimg.Render(0, 0, 0, 0.08, 0.08);		//약 0.32일 때 화면 꽉 채움

	//타겟. 실제 타겟의 움직임의 1/4배 움직임 (미니맵을 축소한 만큼)
	Targetimg.Render(target.t_x / 4, target.t_y / 4, 0, 0.1, 0.1);

	//몬스터. 실제 타겟의 움직이의 1/4배 움직임
	for (int i = 0; i < monster.MonsterCount; i++)
		Monsterimg.Render(monster.cat[i].m_x / 4, monster.cat[i].m_y / 4, 0, 0.1, 0.1);

	//블록 속 보이게 하기 ========================
	//블록
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if (block.BlockArr[row][col].BlockState == MAP_BLOCK)
			{
				Blockimg.Render((col * 42 + 15) / 4, (row * 42 + 35) / 4, 0, 0.8, 0.8);	//Block.cpp에서 블록이 그려준 위치의 1/4배
			}
		}
	}

	////아이템
	//for (int row = 0; row < 18; row++)
	//{
	//	for (int col = 0; col < 30; col++)
	//	{
	//		if (item.ItemArr1[row][col].ItemState == ITEM_YES)
	//		{
	//			Itemimg.Render((col * 42 + 15) / 4, (row * 42 + 35) / 4, 0, 0.3, 0.3);	//블록 위에 그대로 그려지도록
	//		}
	//	}
	//}

	////트랩
	//for (int row = 0; row < 18; row++)
	//{
	//	for (int col = 0; col < 30; col++)
	//	{
	//		if (trap.TrapArr[row][col] == TRAP_YES)
	//		{
	//			Trapimg.Render((col * 42 + 5) / 4, (row * 42 + 35) / 4, 0, 0.3, 0.3);
	//		}
	//	}
	//}

}


	//@16-2 가까이서 블록 속 보이게 하는 모드 ============================================
	
if (ShowItem == TRUE)
	{
		//미니맵 배경
		MiniMapimg.Render(0, 0, 0, 0.08, 0.08);		//약 0.32일 때 화면 꽉 채움

		//타겟. 실제 타겟의 움직임의 1/4배 위치 (미니맵을 축소한 만큼)
		Targetimg.Render(150, 75, 0, 0.2, 0.2);	//(600,300 의 1/4 위치)

		//블록 속 보이게 하기 ========================
		//블록
		for (int row = 0; row < 18; row++)
		{
			for (int col = 0; col < 30; col++)
			{
				if (block.BlockArr[row][col].BlockState == MAP_BLOCK)
				{				
					if (	((col * 42 + 15)  - target.t_x +140 < 300 ) && ((row * 42 + 35)  - target.t_y +75 < 180)	)	//그리려 하는 부분이 이 범위를 넘어서지 않는다면, 그려라
																							//@16-2 미니맵 크기에 벗어나는 부분은 그려지지 않도록
					{
						Blockimg.Render((col * 42 + 15)  - target.t_x +140, (row * 42 + 35)  - target.t_y +75, 0, 3, 3);	//Block.cpp에서 블록이 그려준 위치의 1/4배
					}
				}
			}
		}

		//아이템
		for (int row = 0; row < 18; row++)
		{
			for (int col = 0; col < 30; col++)
			{
				if (item.ItemArr1[row][col].ItemState == ITEM_YES)
				{
					if (	((col * 42 + 15) - target.t_x + 140 < 300) && ((row * 42 + 35) - target.t_y + 75 < 180)	)
					{
						Itemimg.Render((col * 42 + 15) - target.t_x + 140, (row * 42 + 35) - target.t_y + 75, 0, 1, 1);	//블록 위에 그대로 그려지도록
					}
				}
			}
		}

		//트랩
		for (int row = 0; row < 18; row++)
		{
			for (int col = 0; col < 30; col++)
			{
				if (trap.TrapArr[row][col] == TRAP_YES)
				{
					if (	((col * 42 + 15) - target.t_x + 140 < 300) && ((row * 42 + 35) - target.t_y + 75 < 180)	)
					{
						Trapimg.Render((col * 42 + 15) - target.t_x + 140, (row * 42 + 35) - target.t_y + 75, 0, 0.8, 0.8);
					}
				}
			}
		}

	}




}