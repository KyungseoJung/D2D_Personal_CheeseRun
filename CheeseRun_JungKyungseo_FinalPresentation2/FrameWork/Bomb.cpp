#include "Include.h"
//BombArr[0]�� ���� �κ��� ��� @2-5-2

Bomb bomb;		//@2-5 �ּ� ó��
//Bomb bomb[10];			//@2-5

extern FmodSound BombSound;	//@14-2	���� �߰�


Bomb::Bomb()
{
	m_BombAniTime = 0;
	m_BombCount = 0;
	m_BurstAniTime = 0;		//@3-1 �߰��� ���� 0���� �ʱ�ȭ
	m_BurstCount = 0;		//@3-1 �߰��� ���� 0���� �ʱ�ȭ

	BombNumberlimit = 5;	
}

Bomb::~Bomb()
{

}

void Bomb::Init()
{


	char FileName[256];

	for (int i = 0; i < 8; i++)
	{
		sprintf_s(FileName, "./resource/Img/Bomb/output_Bomb/Bomb_%04d.png", i );
		Bombimg[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	for (int i = 0; i < 10; i++)
	{
		sprintf_s(FileName, "./resource/Img/Bomb/output_Burst/Burst_%04d.png", i );
		BombBurstimg[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
}

void Bomb::Update()
{
	
	//if (GetTickCount64() - m_BombAniTime > 100)			//@2-4 ��ź �׸� �����̴� �ӵ� ����	//GetTickCount64�� �ϴ� �� �´� �� ���Ƽ� �̰ɷ� ��
	if (GetTickCount64() -m_BombAniTime > 100)
	{
		m_BombCount++;
		if (m_BombCount > 6) m_BombCount = 0;			//@2-4 ��ź �׸� 0������ 7������ �����ϱ�
		
		m_BombAniTime = GetTickCount64();
	}

	//@3-1 =====================================
	if(GetTickCount64() - m_BurstAniTime> 100)			//@3-1 ��ź ���� �����̴� �ӵ� ���� - �ٸ� ���� ������
	{
		m_BurstCount++;
		if (m_BurstCount > 8) m_BurstCount = 0;		//@3-1 ���� �׸� 0������ 9������ �����ϱ�

		m_BurstAniTime = GetTickCount64();
	}


	for (int i = 0; i <18; i++)			//@2-5-3 for�� �ɾ��ֱ�(BombNumber ������ ��������)	
	{						//BombNumber ��� BombNumberlimit �ɾ��ָ� - �ƿ� ƨ�� - �׷��� �ƿ� Draw�� for��ó�� �����ϸ� ��!

		for (int j = 0; j < 30; j++)
		{

			if (BombArr[i][j].Bomb_Life == true && Gmanager.m_GameStart == true)
			{
				//BombArr[i][j].Bomb_burst = false;	//@3-1 ��ź�� �� ���� ����	- key.cpp���� �������� - ����Ʈ�� false�� ������ ������?

				if ((BombArr[i][j].BombSecond > 0) && (GetTickCount64() - BombArr[i][j].m_BombLifeTime > 1000))		//@2-4 1�ʸ��� BombSecond �پ�鵵��
				{
					BombArr[i][j].BombSecond--;								//@2-4 �ð��� �������� ��ź ���� �پ��!

					BombArr[i][j].m_BombLifeTime = GetTickCount64();
				}

				if (BombArr[i][j].BombSecond <= 0)		//@2-4 ��ź Ÿ�̸� �ð� ������
				{
					BombArr[i][j].Bomb_burst = true;		//@3-1 ��ź ���� ���� - ���� ���� ����

				}
			}

			if (BombArr[i][j].Bomb_burst == true && Gmanager.m_GameStart == true)	//@3-1 ��ź ���� ���� && ���� ���� ����
			{
				if ((BombArr[i][j].BurstSecond > 0) && (GetTickCount64() - BombArr[i][j].m_BurstLifeTime > 1000))
				{
					BombArr[i][j].BurstSecond--;

					BombArr[i][j].m_BurstLifeTime = GetTickCount64();
				}

				if (BombArr[i][j].BurstSecond <= 0)
				{
					BombArr[i][j].Bomb_burst = false;		//@3-1 ��ź ���� ����
					BombArr[i][j].Bomb_Life = false;		//@2-4 ��ź ���� ����. 
					BombArr[i][j].BombYesNo = BOMB_NO;		//@11-1 �ð� �� �������� ���� �� �ڸ����� ��ź ����.
					BombNumber--;							//@2-5-3 ������ ���� ��ź�� ���� ���ҽ�Ű��
				}
			}
		}
	}



}

void Bomb::Draw()
{

		/*
		if (SmokeBomb[i].Bomb_Life == true && Gmanager.m_GameStart == true)	//@2-4 ��ź ���� ����ִ� ���� && ���� ���� ���¶��
		{
			//@2-4 �� �ڵ带 ���⿡ ������ ��ź�� ��� Ÿ��(����) ��ġ�� ������ ������Ʈ�Ǵϱ� key.cpp�� �׸���
			//Bomb_x = target.t_x;		//@2-4 ��ź ���� ��ġ �����ϰ� �� �ڸ��� ��� �׷�������
			//Bomb_y = target.t_y;

			Bombimg[m_BombCount].SetColor(255, 255, 255, 255);
			Bombimg[m_BombCount].Render(SmokeBomb[i].Bomb_x , SmokeBomb[i].Bomb_y , 0, 1, 1);		//@2-4 ��ź ���� ��ġ ����
		}

		if (SmokeBomb[i].Bomb_burst == true && Gmanager.m_GameStart == true)					//@3-1 ��ź ���� ���� ����ִ� ���� && ���� ���� ����
		{
			BombBurstimg[m_BurstCount].SetColor(255, 255, 255, 255);
			BombBurstimg[m_BurstCount].Render(SmokeBomb[i].Bomb_x -80.0f, SmokeBomb[i].Bomb_y -80.0f, 0, 0.5, 0.5);	//@3-1 ���� �׸��� ��ġ ����
		}

		*/

		//@11-1 ��ź�� �迭�� ��ġ�ϵ��� ����
		for (int row = 0; row < 18; row++)
		{
			for (int col = 0; col < 30; col++)
			{
				if (BombArr[row][col].BombYesNo == BOMB_YES)			//���� ��ź�� ������ �ִٸ�
				{
						if (BombArr[row][col].Bomb_Life == true && Gmanager.m_GameStart == true)	//@2-4 ��ź ���� ����ִ� ���� && ���� ���� ���¶��
						{
							Bombimg[m_BombCount].SetColor(255, 255, 255, 255);
							Bombimg[m_BombCount].Render(col * 42 + 10, row * 42 + 15, 0, 1, 1);
						}

						if (BombArr[row][col].Bomb_burst == true && Gmanager.m_GameStart == true)	// ��ź ���� ���� ����ִ� ���� && ���� ���� ����
						{
							BombBurstimg[m_BurstCount].SetColor(255, 255, 255, 255);
							BombBurstimg[m_BurstCount].Render(col * 42 -80.0f, row * 42 - 80.0f, 0, 0.5, 0.5);	//@3-1 ���� �׸��� ��ġ ����
						}
					
				}
			}
		}

}

void Bomb::Reset()
{
	for (int i = 0; i < 18; i++)		//@2-5-3 VK_CONTROL ������, ��� ��ź �� ����(������ �� �ƴ϶� �ױ⸸ ��)
	{
		for (int j = 0; j < 30; j++)
		{
			BombArr[i][j].Bomb_Life = false;
			BombArr[i][j].Bomb_burst = false;
			BombNumber = 0;						//@ ���� ��ź�� ���� �ʱ�ȭ
		}
	}

}

void Bomb::InstallBomb(int BombSecond)
{
	if (bomb.BombNumber < bomb.BombNumberlimit)					//@2-5-3 ���� �������ֱ�	(���� ȭ�鿡 ���� ��ź�� ���� < ��ź ���� ����)
	{
		if (bomb.BombArr[(int)(target.t_y / 42)][(int)(target.t_x / 42)].BombYesNo == BOMB_NO)	//@11-1 ���� ���� ��ġ�� ��ź�� ������ ���� �ʴٸ�(���� ��ġ�� ��ź �ߺ��ؼ� ���� ���ϵ���)
		{
			int i = (int)(target.t_y / 42);
			int j = (int)(target.t_x / 42);

			if (bomb.BombArr[i][j].Bomb_Life == false)
			{
				bomb.BombArr[i][j].Bomb_Life = true;				//@2-4 �����̽��� ���� ������ ��ź ��Ƴ�����. ���⵵��
				bomb.BombArr[i][j].Bomb_burst = false;				//@3-1 ��ź�� �� ���� ���� - Bomb.cpp���� �̹� ����µ�, ���⿡ �� �� ��������..? @����ǥ

				bomb.BombArr[i][j].BombSecond = BombSecond;			//@2-4 ��ź Ÿ�̸� �ð� ���� - 5��
				bomb.BombArr[i][j].BurstSecond = 5;					//@3-1 ��ź ���� ������ �ð� ���� - 5��

				//@11-1
				bomb.BombArr[(int)(target.t_y / 42)][(int)(target.t_x / 42)].BombYesNo = BOMB_YES;	//@11-1 ��ź�� ���´�.

				bomb.BombNumber++;	//@2-5-3 ���� �� �����ϰ�, ���� �÷�

				BombSound.EffectPlay(Gmanager.InstallBombSound);		//@14-2	//��ź�� ���� �� �ִٸ�, �Ҹ� ��� (���� �ڸ��� ���� ��, ��ź �� ���̴ϱ� �Ҹ� ��� �� �ǰ���)
			}

		}
	}
}

void Bomb::PushBomb(int pos)	//@12-1
{
	//@12-1 VK_SHIFT�� ����Ű�� ���ÿ� ������ pos �������� �и�
	/*
	����ؾ� �� �κ�
	 - ��� : MAP_EMPTY�� �ƴ� ���, ��ź�� �̵� ����
	 - ��ź : BOMB_NO�� �ƴ� ���, ��ź�� �̵� ����

	if �а��� �ϴ� �������� ��ź�� �ִٸ�
		if(�� ���� ���� �ʰ� && ��� ���� && ��ź ���� ������) 
			�̴� �������� ��ź �̵�
	*/

	/*
	��ź ���� �̵� ��ġ ������ִ� �ڵ��

	��ź�� ����������� ��� �������ִ� �ڵ�� ������ �ۼ�
	*/
	
	int row = (int)(target.t_y / 42);	// Ÿ���� ��ġ�� ��ǥ
	int col = (int)(target.t_x / 42);
	int pushrow = row;					// �з��� ��ź�� ��ġ�� ��ǥ
	int pushcol = col;

	int discontrol=2;


	//if (	((pos == LEFT) && (BombArr[row][col - 1].BombYesNo == BOMB_YES))
	//	||	((pos == RIGHT) && (BombArr[row][col + 1].BombYesNo == BOMB_YES))
	//	||  ((pos == UP) && (BombArr[row - 1][col].BombYesNo == BOMB_YES))
	//	|| ((pos == DOWN) && (BombArr[row + 1][col].BombYesNo == BOMB_YES)) )

	//{	BombSound.EffectPlay(Gmanager.PushBombSound);	 //@14-2 ��ź �̴� �Ҹ�. ���� �а��� �ϴ� �������� ��ź�� �����Ѵٸ�

	// �̴� ���� : ���� =====================================================================
	if ((pos == LEFT)
		&& (BombArr[row][col - 1].BombYesNo == BOMB_YES)	//���� �а��� �ϴ� �������� ��ź�� �����Ѵٸ�
		&& (col > 1) 										//@������ - ���� �̴� ��ġ�� 1���ٴ� Ŀ����. �׷��� 1 ��ġ�� �ִ� ��ź�� �� �и���
		&& (block.BlockArr[row][col - 2].BlockState != MAP_BLOCK) )	//@������
	{
		while ((pushcol > 0)
			&& ((block.BlockArr[row][pushcol - 1].BlockState != MAP_BLOCK))
			&& (BombArr[row][pushcol - discontrol].BombYesNo == BOMB_NO))
		{
			pushcol--;	discontrol = 1;
		}
		// ���ǿ�  (BombArr[row][pushcol - 1].BombYesNo == BOMB_NO) �� ������, ���� ������ ��ġ ��ü�� �ǹ��ϱ� ������ �и��� ���� - discontrol�̶�� �Ÿ� ������ ���� ���

		//�� while������ ���� pushrow�� pushcol�� �������� ======================
		BombArr[row][pushcol].Bomb_Life = true;
		BombArr[row][pushcol].BombSecond = BombArr[row][col - 1].BombSecond;
		BombArr[row][pushcol].Bomb_burst = BombArr[row][col - 1].Bomb_burst;
		BombArr[row][pushcol].BurstSecond = BombArr[row][col - 1].BurstSecond;
		BombArr[row][pushcol].BombYesNo = BOMB_YES;

		// ���� ��Ŀ� �ִ� ��ź�� ���ֱ�======================
		BombArr[row][col - 1].Bomb_Life = false;
		//		BombArr[row][col - 1].BombSecond = 0;
		BombArr[row][col - 1].Bomb_burst = false;
		//		BombArr[row][col - 1].BurstSecond = 0;
		BombArr[row][col - 1].BombYesNo = BOMB_NO;

		//	Bomb_Life, BombSecond, Bomb_burst, BurstSecond, BombYesNo
		//	m_BombLifeTime, m_BurstLifeTime, BombSecond, BurstSecond�� ���� �ʿ� ����	
		//	������ ��ź�� ����� ������ �ϴ� ������ ����. �׸��� ���� ���� ��, ���� ���ǵ� 

		BombSound.EffectPlay(Gmanager.PushBombSound);	 //@14-2 ��ź �̴� �Ҹ�. ���� �а��� �ϴ� �������� ��ź�� �����Ѵٸ�
	}

	// �̴� ���� : ������ =====================================================================
	if ((pos == RIGHT)
		&& (BombArr[row][col + 1].BombYesNo == BOMB_YES)
		&& (col < 28)	//@������
		&& (block.BlockArr[row][col + 2].BlockState != MAP_BLOCK) )	//@������
	{	
		while ((pushcol < 29)
			&& ((block.BlockArr[row][pushcol + 1].BlockState != MAP_BLOCK))
			&& (BombArr[row][pushcol + discontrol].BombYesNo == BOMB_NO))
		{	pushcol++;	discontrol = 1;	}
	
		//�� while������ ���� pushrow�� pushcol�� �������� ======================
		BombArr[row][pushcol].Bomb_Life = true;
		BombArr[row][pushcol].BombSecond = BombArr[row][col + 1].BombSecond;
		BombArr[row][pushcol].Bomb_burst = BombArr[row][col + 1].Bomb_burst;
		BombArr[row][pushcol].BurstSecond = BombArr[row][col + 1].BurstSecond;
		BombArr[row][pushcol].BombYesNo = BOMB_YES;

		// ���� ��Ŀ� �ִ� ��ź�� ���ֱ�======================
		BombArr[row][col + 1].Bomb_Life = false;
//		BombArr[row][col + 1].BombSecond = 0;
		BombArr[row][col + 1].Bomb_burst = false;
//		BombArr[row][col + 1].BurstSecond = 0;
		BombArr[row][col + 1].BombYesNo = BOMB_NO;

		BombSound.EffectPlay(Gmanager.PushBombSound);	 //@14-2 ��ź �̴� �Ҹ�. ���� �а��� �ϴ� �������� ��ź�� �����Ѵٸ�
	}
	

	// �̴� ���� : ���� =====================================================================
	if ((pos == UP)
		&& (BombArr[row - 1][col].BombYesNo == BOMB_YES)
		&& (block.BlockArr[row - 2][col].BlockState != MAP_BLOCK)	//@������ - ���� �̴� ���� ��ź �ʸӿ� ����� ���ٸ�, �� �� �ֵ���
		&& (row >1) )								//@������ - ���� ��ġ�� 1���ٴ� Ŀ�� �и�����. �׷��� 1��ġ�� �ִ� ��ź�� �� �̻� �� �и���.
	{
		while ((pushrow > 0)
			&& ((block.BlockArr[pushrow -1][col].BlockState != MAP_BLOCK))
			&& (BombArr[pushrow - discontrol][col].BombYesNo == BOMB_NO))
		{
			pushrow--;	discontrol = 1;
		}

		//�� while������ ���� pushrow�� pushcol�� �������� ======================
		BombArr[pushrow][col].Bomb_Life = true;
		BombArr[pushrow][col].BombSecond = BombArr[row - 1][col].BombSecond;
		BombArr[pushrow][col].Bomb_burst = BombArr[row - 1][col].Bomb_burst;
		BombArr[pushrow][col].BurstSecond = BombArr[row -1][col].BurstSecond;
		BombArr[pushrow][col].BombYesNo = BOMB_YES;

		// ���� ��Ŀ� �ִ� ��ź�� ���ֱ�======================
		BombArr[row - 1][col].Bomb_Life = false;
		//		BombArr[row][col + 1].BombSecond = 0;
		BombArr[row - 1][col].Bomb_burst = false;
		//		BombArr[row][col + 1].BurstSecond = 0;
		BombArr[row - 1][col].BombYesNo = BOMB_NO;

		BombSound.EffectPlay(Gmanager.PushBombSound);	 //@14-2 ��ź �̴� �Ҹ�. ���� �а��� �ϴ� �������� ��ź�� �����Ѵٸ�
	}


	// �̴� ���� : �Ʒ��� =====================================================================
	if ((pos == DOWN)
		&& (BombArr[row + 1][col].BombYesNo == BOMB_YES)
		&& (block.BlockArr[row + 2][col].BlockState != MAP_BLOCK)		//@������ - ���� �̴� ���� ��ź �ʸӿ� ����� ���ٸ�, �� �� �ֵ���
		&& (row < 16) )								//@������ - ���� ��ġ�� 16���ٴ� �۾ƾ� �и�����. �׷��� 1��ġ�� �ִ� ��ź�� �� �̻� �� �и���.
	{
		while ((pushrow < 17)
			&& ((block.BlockArr[pushrow + 1][col].BlockState != MAP_BLOCK))
			&& (BombArr[pushrow + discontrol][col].BombYesNo == BOMB_NO))
		{
			pushrow++;	discontrol = 1;
		}

		//�� while������ ���� pushrow�� pushcol�� �������� ======================
		BombArr[pushrow][col].Bomb_Life = true;
		BombArr[pushrow][col].BombSecond = BombArr[row + 1][col].BombSecond;
		BombArr[pushrow][col].Bomb_burst = BombArr[row + 1][col].Bomb_burst;
		BombArr[pushrow][col].BurstSecond = BombArr[row + 1][col].BurstSecond;
		BombArr[pushrow][col].BombYesNo = BOMB_YES;

		// ���� ��Ŀ� �ִ� ��ź�� ���ֱ�======================
		BombArr[row + 1][col].Bomb_Life = false;
		//		BombArr[row][col + 1].BombSecond = 0;
		BombArr[row + 1][col].Bomb_burst = false;
		//		BombArr[row][col + 1].BurstSecond = 0;
		BombArr[row + 1][col].BombYesNo = BOMB_NO;

		BombSound.EffectPlay(Gmanager.PushBombSound);	 //@14-2 ��ź �̴� �Ҹ�. ���� �а��� �ϴ� �������� ��ź�� �����Ѵٸ�
	}



}