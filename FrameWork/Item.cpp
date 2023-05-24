#include "Include.h"

Item item;

//@������ (vector->list�θ� ����)
extern std::list<Trap*> targetTrap;	//@10-3 ���� extern ����. Ʈ�� ��� ���ִ� ȿ�� ����ϱ� ����
extern FmodSound ItemSound;	//@14-2	���� �߰�

Item::Item()
{

}

Item::~Item()
{

}

void Item::Init()
{
	char FileName[256];

	sprintf_s(FileName, "./resource/Img/Item/Item4.png");
	Itemimg1.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));


	//@10-1 ������1 ��ġ �־��ֱ�
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			ItemArr1[row][col].ItemState = ITEM_NO;

			if ((block.BlockArr[row][col].BlockState == MAP_BLOCK) && ( (col != 0) && (col % 7== 0) )	  )	//@ ������ - ��� if������ ����ϰ�
			{
				this->ItemArr1[row][col].ItemState = ITEM_YES;	//������1 �ִ�.
			}
		}
	}

	gyeokja.Create("./resource/Img/Map/gyeokja.png", false, D3DCOLOR_XRGB(0, 0, 0));	//���� �׷��ִ� �ڵ�


}

void Item::Update()
{
	//Ÿ���� ������ ����, �� �������� ����. �� �������� ���� �����(ITEM_NO). ������ ȿ�� �߻�. 
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			//	MAP_TRAP�� �ƴ϶�� ���ǵ� �־���� �����̳ʰ� ���̻� �������� ����
			if (item.ItemArr1[row][col].show == TRUE)
			{
				float distance = (float)sqrt(((col * 42.0) - target.t_x) * ((col * 42.0) - target.t_x) +
					((row * 42.0) - target.t_y) * ((row * 42.0) - target.t_y));

				if(distance < 30)	//Ÿ�ٰ� �����۰��� �Ÿ�	
				{
					item.ItemArr1[row][col].show = FALSE;			//��������� ������ ����

					ItemArr1[row][col].ItemState = ITEM_NO;			//������ ����� (���� �迭���� 0���� ����)

					ItemSound.EffectPlay(Gmanager.GetItemSound);	//@14-2 ������ ���� �� ȿ����

					//������ ȿ�� �߻�
					for (int i = 0; i < monster.MonsterCount; i++)	//����̵� ��� ����				
					{
						monster.cat[i].life = false;	

						monster.cat[i].m_SleepSecond = 5;
					}

					targetTrap.clear();								//�����ִ� Ʈ�� ��� �����
																
				}
				

			}
		}
	}
}

void Item::Draw()
{
	//show == TRUE �� ����, �׸���. �ƴ� ��, �� ���̰�
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if (item.ItemArr1[row][col].show == TRUE)
			{
				Itemimg1.Render(col * 42 + 15, row * 42 + 42, 0, 0.4, 0.4);
			}
		}
	}

}

void Item::Reset()
{
	//������ �ʱ�ȭ���ֱ�
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if (item.ItemArr1[row][col].show == TRUE)
			{
				item.ItemArr1[row][col].show = FALSE;
			}
		}
	}
}

void Item::PushItem(int pos)	//@14-1 ���� �Լ��� ������
{
	if (pos == LEFT)
	{
		item.ItemArr1[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1].ItemState = ITEM_NO;
		item.ItemArr1[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 2].ItemState = ITEM_YES;
	}
	else if (pos == RIGHT)
	{
		item.ItemArr1[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 1].ItemState = ITEM_NO;
		item.ItemArr1[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 2].ItemState = ITEM_YES;
	}
	else if (pos == UP)
	{
		item.ItemArr1[(int)(target.t_y / 42) - 1][(int)(target.t_x / 42)].ItemState = ITEM_NO;
		item.ItemArr1[(int)(target.t_y / 42) - 2][(int)(target.t_x / 42)].ItemState = ITEM_YES;
	}
	else if (pos == DOWN)
	{
		item.ItemArr1[(int)(target.t_y / 42) + 1][(int)(target.t_x / 42)].ItemState = ITEM_NO;
		item.ItemArr1[(int)(target.t_y / 42) + 2][(int)(target.t_x / 42)].ItemState = ITEM_YES;
	}
}
