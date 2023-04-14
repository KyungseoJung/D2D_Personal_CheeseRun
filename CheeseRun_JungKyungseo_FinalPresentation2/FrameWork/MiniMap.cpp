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

	//�̴ϸ� ���
	sprintf_s(FileName, "./resource/Img/MiniMap/MiniMap2.png");
	MiniMapimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//Ÿ��
	sprintf_s(FileName, "./resource/Img/MiniMap/Mouse_MiniMap.png");
	Targetimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//����
	sprintf_s(FileName, "./resource/Img/MiniMap/Cat_MiniMap.png");
	Monsterimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//��� ���� ================
	//���(���� 50)
	sprintf_s(FileName, "./resource/Img/MiniMap/Block_MiniMap.png");
	Blockimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//��� �� ������
	sprintf_s(FileName, "./resource/Img/MiniMap/Item_MiniMap.png");
	Itemimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//��� �� Ʈ��
	sprintf_s(FileName, "./resource/Img/MiniMap/Trap_MiniMap.png");
	Trapimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	
}

void MiniMap::Update()
{

}

void MiniMap::Draw()
{
	//@16-1 ��ü ȭ�� ���̰� �ϴ� ��� ==========================================

if (ShowAll == TRUE)
{
	//�̴ϸ� ���
	MiniMapimg.Render(0, 0, 0, 0.08, 0.08);		//�� 0.32�� �� ȭ�� �� ä��

	//Ÿ��. ���� Ÿ���� �������� 1/4�� ������ (�̴ϸ��� ����� ��ŭ)
	Targetimg.Render(target.t_x / 4, target.t_y / 4, 0, 0.1, 0.1);

	//����. ���� Ÿ���� �������� 1/4�� ������
	for (int i = 0; i < monster.MonsterCount; i++)
		Monsterimg.Render(monster.cat[i].m_x / 4, monster.cat[i].m_y / 4, 0, 0.1, 0.1);

	//��� �� ���̰� �ϱ� ========================
	//���
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if (block.BlockArr[row][col].BlockState == MAP_BLOCK)
			{
				Blockimg.Render((col * 42 + 15) / 4, (row * 42 + 35) / 4, 0, 0.8, 0.8);	//Block.cpp���� ����� �׷��� ��ġ�� 1/4��
			}
		}
	}

	////������
	//for (int row = 0; row < 18; row++)
	//{
	//	for (int col = 0; col < 30; col++)
	//	{
	//		if (item.ItemArr1[row][col].ItemState == ITEM_YES)
	//		{
	//			Itemimg.Render((col * 42 + 15) / 4, (row * 42 + 35) / 4, 0, 0.3, 0.3);	//��� ���� �״�� �׷�������
	//		}
	//	}
	//}

	////Ʈ��
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


	//@16-2 �����̼� ��� �� ���̰� �ϴ� ��� ============================================
	
if (ShowItem == TRUE)
	{
		//�̴ϸ� ���
		MiniMapimg.Render(0, 0, 0, 0.08, 0.08);		//�� 0.32�� �� ȭ�� �� ä��

		//Ÿ��. ���� Ÿ���� �������� 1/4�� ��ġ (�̴ϸ��� ����� ��ŭ)
		Targetimg.Render(150, 75, 0, 0.2, 0.2);	//(600,300 �� 1/4 ��ġ)

		//��� �� ���̰� �ϱ� ========================
		//���
		for (int row = 0; row < 18; row++)
		{
			for (int col = 0; col < 30; col++)
			{
				if (block.BlockArr[row][col].BlockState == MAP_BLOCK)
				{				
					if (	((col * 42 + 15)  - target.t_x +140 < 300 ) && ((row * 42 + 35)  - target.t_y +75 < 180)	)	//�׸��� �ϴ� �κ��� �� ������ �Ѿ�� �ʴ´ٸ�, �׷���
																							//@16-2 �̴ϸ� ũ�⿡ ����� �κ��� �׷����� �ʵ���
					{
						Blockimg.Render((col * 42 + 15)  - target.t_x +140, (row * 42 + 35)  - target.t_y +75, 0, 3, 3);	//Block.cpp���� ����� �׷��� ��ġ�� 1/4��
					}
				}
			}
		}

		//������
		for (int row = 0; row < 18; row++)
		{
			for (int col = 0; col < 30; col++)
			{
				if (item.ItemArr1[row][col].ItemState == ITEM_YES)
				{
					if (	((col * 42 + 15) - target.t_x + 140 < 300) && ((row * 42 + 35) - target.t_y + 75 < 180)	)
					{
						Itemimg.Render((col * 42 + 15) - target.t_x + 140, (row * 42 + 35) - target.t_y + 75, 0, 1, 1);	//��� ���� �״�� �׷�������
					}
				}
			}
		}

		//Ʈ��
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