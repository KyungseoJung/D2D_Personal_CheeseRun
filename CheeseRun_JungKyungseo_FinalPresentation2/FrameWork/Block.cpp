#include "Include.h"

Block block;

//extern std::vector<Trap> targetTrap;	//@9-1-1 �׽�Ʈ��
extern std::list<Trap*> targetTrap;	//@9-1-2			//@������ (vector->list�θ� ����)

extern FmodSound BlockSound;	//@14-2	���� �߰�


Block::Block()
{
	BlockMakeTime = GetTickCount64();
}

Block::~Block() {}

void Block::Init()
{
	//@6-1-2 �� �迭 �����	==================================================
	//�� ��� �׸� 
	char FileName[256];
	sprintf_s(FileName, "./resource/Img/Block/Block00.png");
	map_Block.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Block/Block01.png");
	Blockimg1.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Block/Block02.png");
	Blockimg2.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Block/Block03.png");
	Blockimg3.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//�� �迭 Ÿ�� �ʱ�ȭ �Լ�
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			this->BlockArr[row][col].BlockState = MAP_EMPTY;

			if ((row == 5) || (row == 6) || (row == 11) || (row == 12))	//@��� ��ġ 10-2 ����
			{
				this->BlockArr[row][col].BlockState = MAP_BLOCK;	//��� �ִ�.
			}
		}
	}

	gyeokja.Create("./resource/Img/Map/gyeokja.png", false, D3DCOLOR_XRGB(0, 0, 0));	//���� �׷��ִ� �ڵ� - GameManager.cpp�� Draw�Լ��� ����
	
	//@7-1 MAP_BLOCK�� ���, CrushState =3 �� �ο� ==================================================
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			this->BlockArr[row][col].CrushState = 4; //4�� ũ�⾿ ��ƿ �� �ִ�. //key.cpp���� VK_CONTROL ���� ������ ������
			/* ����� ���� �κ��� �ڵ����� 0���� ó���Ǿ, ���߿� ����� ���ڱ� ����� ���� �߻��ұ��)
			if (BlockArr[row][col].BlockState = MAP_BLOCK) �ּ� ó�� �� */
		}
	}

}

void Block::Update()
{
	//�μ��� ���(MAP_BROKEN) �ð� ������, �ٽ� ���⵵��(MAP_BLOCK)		//��� ����� �ð� ���� ����
	if( (Gmanager.m_GameStart == true) && (GetTickCount64() - BlockMakeTime > 3000) ) 
	{	
		for (int row = 0; row < 18; row++)
		{
			for (int col = 0; col < 30; col++)
			{
						//@9-1  Ʈ���� �ִ� ���� �ƴϸ�	
						//������ CrushState�� �پ��� ��, MAP_BLOCK�� �� ���̴ϱ�(key.cpp VK_CONTROL ����)
						// && (block.BlockArr[row][col].BlockState != MAP_ALREADYTRAP) ������ �� �ɸ�
						//&& (block.BlockArr[row][col].BlockState != MAP_TRAP) ������ �� �ɸ�
				if ( (BlockArr[row][col].CrushState < 4) 
					&& (BlockArr[row][col].BlockState != MAP_TRAP) 
					&& (BlockArr[row][col].BlockState != MAP_ITEM)			)	//@10-1 //@������ �����̳� �������� �ִ� ����� �μ��� �߿��� ��� ������� �ʵ���.
				{
					BlockArr[row][col].CrushState += 1;
					BlockArr[row][col].BlockState = MAP_BLOCK;	//����� �ϳ��� ��Ƴ���, Ÿ���� �� ������.
				}
			}
		}

		BlockMakeTime = GetTickCount64();
		
	}

	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if ((BlockArr[row][col].CrushState == 0)	)
			/* && (BlockArr[row][col].BlockState != MAP_TRAP)
				&& (BlockArr[row][col].BlockState != MAP_ITEM)	*/			//@10-1 //@9-3 ���⿡ ������� �̹� Ʈ���� ���� ��ǥ�� MAP_BROKEN���� ������ ���� �� ���� 
																		//-> MAP_BROKEN���� ���ϸ�, ����(�����̳�)�� ���ѻ����Ǿ����	//@������ ���� �׷� ���� �߻����� ����. if�� �� �� ����
			{
				BlockArr[row][col].BlockState = MAP_BROKEN;	//�ν����� ������ �� �ִ� ����. Update�Ŀ��� �ð��� ������, �ڵ����� ��Ƴ�����(MAP_BLOCK) ������ֱ�
			}
		}
	}

	//@12-2 CrushBlock()�� ������ �ߴµ�, ������Ʈ�� ������ �ٷιٷ� ����� ������ �� ��.
	//@9-1 ����� �ν��µ�, �� ����� TRAP�� �ִ� ���̾��ٸ�
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			//	MAP_TRAP�� �ƴ϶�� ���ǵ� �־���� �����̳ʰ� ���̻� �������� ����
			if ( (BlockArr[row][col].BlockState == MAP_BROKEN) && (trap.TrapArr[row][col] == TRAP_YES) )	
			{				
				//@������ ���� ���� 
				targetTrap.push_back(new Trap((col * 42) + 15, (row * 42) + 10));	// (����/����Ʈ) �̿�! ����� �ִ� ��ġ�� Ʈ���� �����.
				
				trap.TrapArr[row][col] = TRAP_NO;					//Ʈ��(����(�����̳�)) Ȱ�� ����. //@������ ���� TRAP_NO�� ����.
				BlockArr[row][col].BlockState = MAP_TRAP;			//�̹� Ʈ���� ���� ���� 
				//Ʈ���� �̹� �����������, MAP_TRAP ���� ����. �׷��� �̹� ���� ��ü�� ��� ����� �� ���� �� ����
				BlockSound.EffectPlay(Gmanager.ShowTrapSound);		//@14-1 ��� �ν��µ�, Ʈ�� ������ ȿ����
			}
		}
	}	
	

	//@10-1 ����� �ν��µ�, �� ����� ������1�� �ִ� ���̾��ٸ�
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if ((BlockArr[row][col].BlockState == MAP_BROKEN) && (item.ItemArr1[row][col].ItemState == ITEM_YES))
			{
				item.ItemArr1[row][col].show = TRUE;		//������ ��Ÿ������
				item.ItemArr1[row][col].ItemState = ITEM_NO;	//������ �̹� ���� ����
				BlockArr[row][col].BlockState = MAP_ITEM;	//�̹� �������� ���� ����
				//Ʈ���� �̹� �����������, MAP_TRAP ���� ����. �׷��� �̹� ���� ��ü�� ��� ����� �� ���� �� ����
			}
		}
	}



}

void Block::Draw()
{
	//@6-1-2 �� ��� �׸� �׸���
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if (BlockArr[row][col].BlockState == MAP_BLOCK)	//�ν��� ������ ��� �̹����� ����
			{
				if(BlockArr[row][col].CrushState == 4)	//�ν��� ���°� 4�� ��, �׸�
					map_Block.Render(col * 42 + 15, row * 42 + 35, 0, 1.4, 1.4);		//@7-1 �׸� ��ġ ���ݸ� ����~25��ŭ
				else if(BlockArr[row][col].CrushState == 3)	//�ν��� ���°� 3�� ��, �׸�
					Blockimg1.Render(col * 42 + 15, row * 42 + 35, 0, 1.4, 1.4);
				else if(BlockArr[row][col].CrushState == 2)	//�ν��� ���°� 2�� ��, �׸�
					Blockimg2.Render(col * 42 + 15, row * 42 + 35, 0, 1.4, 1.4);
				else if(BlockArr[row][col].CrushState == 1)	//�ν��� ���°� 1�� ��, �׸�
					Blockimg3.Render(col * 42 + 15, row * 42 + 35, 0, 1.4, 1.4);
			}
		}
	}
}

void Block::CrushBlock()
{
	//(1ĭ ����)Ÿ���� ������ ����� �ִٸ� �� ������ �ִ� �� �ν�����.
			// ��� �迭[�� = ������][�� = ������] �򰥸��� �ʱ�!

	

	if (BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1].BlockState == MAP_BLOCK)	//����
	{
		BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1].CrushState -= 1;
		BlockSound.EffectPlay(Gmanager.CrashBlockSound);	//@14-2 ��� �μ��� ȿ����
	}
	else if (BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 1].BlockState == MAP_BLOCK)	//����
	{
		BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 1].CrushState -= 1;
		BlockSound.EffectPlay(Gmanager.CrashBlockSound);	//@14-2 ��� �μ��� ȿ����
	}
	else if (BlockArr[(int)(target.t_y / 42) - 1][(int)(target.t_x / 42)].BlockState == MAP_BLOCK) //��
	{
		BlockArr[(int)(target.t_y / 42) - 1][(int)(target.t_x / 42)].CrushState -= 1;
		BlockSound.EffectPlay(Gmanager.CrashBlockSound);	//@14-2 ��� �μ��� ȿ����
	}
	else if (BlockArr[(int)(target.t_y / 42) + 1][(int)(target.t_x / 42)].BlockState == MAP_BLOCK) //�Ʒ�
	{
		BlockArr[(int)(target.t_y / 42) + 1][(int)(target.t_x / 42)].CrushState -= 1;
		BlockSound.EffectPlay(Gmanager.CrashBlockSound);	//@14-2 ��� �μ��� ȿ����
	}
}

void Block::PushBlock(int pos)	//@14-1 ���� �Լ��� ������ //����� �и��� ��ó��
{
	
	if (pos == LEFT)
	{
		block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1].BlockState = MAP_EMPTY;
		block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 2].BlockState = MAP_BLOCK;
		BlockSound.EffectPlay(Gmanager.PushBlockSound);	//@14-2 ��� �̴� ȿ����
	}
	else if (pos == RIGHT)
	{
		block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 1].BlockState = MAP_EMPTY;
		block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 2].BlockState = MAP_BLOCK;
		BlockSound.EffectPlay(Gmanager.PushBlockSound);	//@14-2 ��� �̴� ȿ����
	}
	else if (pos == UP)
	{
		block.BlockArr[(int)(target.t_y / 42) - 1][(int)(target.t_x / 42)].BlockState = MAP_EMPTY;
		block.BlockArr[(int)(target.t_y / 42) - 2][(int)(target.t_x / 42)].BlockState = MAP_BLOCK;
		BlockSound.EffectPlay(Gmanager.PushBlockSound);	//@14-2 ��� �̴� ȿ����
	}	
	else if (pos == DOWN)
	{
		block.BlockArr[(int)(target.t_y / 42) + 1][(int)(target.t_x / 42)].BlockState = MAP_EMPTY;
		block.BlockArr[(int)(target.t_y / 42) + 2][(int)(target.t_x / 42)].BlockState = MAP_BLOCK;
		BlockSound.EffectPlay(Gmanager.PushBlockSound);	//@14-2 ��� �̴� ȿ����
	}
}