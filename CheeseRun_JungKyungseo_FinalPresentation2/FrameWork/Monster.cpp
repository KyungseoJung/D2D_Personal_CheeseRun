#include "Include.h"


Monster monster;							//@1 Ŭ���� ��ü �����

extern FmodSound MonsterSound;


Monster::Monster(void)
{
	//LifeTime = GetTickCount64();
	MonsterCountTime = GetTickCount64();
	MonsterMoveTime = GetTickCount64();
	FollowTime = GetTickCount64();
}

Monster::~Monster(void)
{
}

void Monster::Init()					//@1 ������ ��, �� �̹����� �ִϸ��̼�ó�� �����̵��� ������.
{

	char FileName[256];

	for (int i = 0; i < 6; i++)
	{
		sprintf_s(FileName, "./resource/Img/Monster/Cat/output_Cat/Cat_002_00%02d.png", i);				
		catimg1[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	//@3-3 ����� �ڴ� �̹��� �� ����
	//@3-5-1-1
	sprintf_s(FileName, "./resource/Img/Monster/Cat/output_Sleep/Sleep_0001.png");
	Sleepimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//@10-5 FollowZone �̹��� 
	sprintf_s(FileName, "./resource/Img/Monster/FollowZone.png");
	FollowZone.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	

}

//@1 ���� ����� �Լ�(������ġ, ����, ���ǵ� ���� �� �Լ��� ���� ��������)
//@1 m_x : ������� �ǽð� ��ġ,
//@3-5-1 ���� �� �ϴ� ���� �ذ� : ���� ����� �������, fishkind�� ���� ���� �ᵵ ��(A_, B_) ��, num�� �ٸ��� �ؾ� ��
void Monster::GoodFunction(double m_x, double m_y, double speed, int pos, double w, int num)
{
	cat[num].m_x = m_x;
	cat[num].m_y = m_y;

	cat[num].speed = speed;
	cat[num].scale = 0.6;		//ũ�� ����
	cat[num].life = false;	
	cat[num].pos = pos;
	cat[num].w = w;				//@3-5-2 �ʿ��� ���� �ְڴ�!! ������ġ�� ���� ���̴� ��ġ �Ÿ� ������

	cat[num].m_SleepSecond = 5;	//@4-1 5�� ������ ���·� ����
}


void Monster::Update()
{


	if (Gmanager.m_GameStart == true)
	{
		//@3-3-2 �ð� ������ �ڵ����� ��Ƴ��� �ϸ� �� ��. ���� ���� �ð��� ������ ��, ��Ƴ��� ��.
		//if (GetTickCount64() - LifeTime > 100)	//@1 Ư�� �ð����� �����(����)�� �������� �츲
		//{
		//	for (m_FishLifeSelect = 0; m_FishLifeSelect < 3; m_FishLifeSelect++)		//@2-2 ����� �߰� (<2)���� �κ��� (<3)���� ����.
		//	{
		//		if (catkind[m_FishLifeSelect].life == false)
		//		{
		//			catkind[m_FishLifeSelect].life = true;

		//		}

		//	}
		//	m_FishLifeSelect = 0;
		//	LifeTime = GetTickCount64();
		//}


		//@1 Ư�� �ð����� & �ӵ����� ���� �̵�
		if (GetTickCount64() - MonsterMoveTime > 20)			//@1 ����/���������� ���� m_x���� dx�� ��/�������ν� -> ����� �����̴� �ӵ� �����ϴ� for��
		{
			for (int i = 0; i < MonsterCount; i++)							//@2-2 ����� �߰� (i<2)���� �κ��� (i<3)���� ����.	//@3-5-1
			{
				if (cat[i].pos == LEFT && cat[i].life == true)		// �����ʿ��� �������� ����!  x�� - ���Ѿ���		//@1 ����Ⱑ ����ִٸ� �����̵���~ //@3-2 ���� Boom�Լ����� life = false�� �ٲ�� ���� �� �ǰ���
				{
					cat[i].m_x -= cat[i].speed; /* cat[i].dx -= cat[i].speed; */	//@10-5 �ּ� ó��
				}		//@1 ������� ��ġ�� �̵��ϰ�, ���������� �̵��ϰ�~

				else if (cat[i].pos == RIGHT && cat[i].life == true)
				{
					cat[i].m_x += cat[i].speed;  /* cat[i].dx += cat[i].speed; */	//@10-5 �ּ� ó��
				}

			}

			MonsterMoveTime = GetTickCount64();
		}


		// �����̴� ���� ��ȯ
		for (int i = 0; i < MonsterCount; i++)	
		{
			if (cat[i].life == true)
			{
				if (cat[i].pos == LEFT 
					&& ((cat[i].m_x < 50)	//@3-5-1 ȭ���� ���� ���� ������
					|| block.BlockArr[(int)(cat[i].m_y / 42)][(int)(cat[i].m_x / 42) - 1].BlockState == MAP_BLOCK	//���� ���⿡ ����� �ִٸ�
					/* || bomb.BombArr[(int)(cat[i].m_y / 42)][(int)(cat[i].m_x / 42) - 1].BombYesNo == BOMB_YES*/	))	//���� ���⿡ ��ź�� �ִٸ�	
				{
					cat[i].pos = RIGHT;	//@3-5-3 �Դٰ��� �ϵ���
				}
				else if (cat[i].pos == RIGHT 
					&& ((cat[i].m_x > 1150)	//@3-5-1  ȭ���� ������ ���� ������. ȭ�鿡�� �ƿ� ������� �ʵ��� 1280 - 100
					|| block.BlockArr[(int)(cat[i].m_y / 42)][(int)(cat[i].m_x / 42) +1].BlockState == MAP_BLOCK	//���� ���⿡ ����� �ִٸ�
					/* || bomb.BombArr[(int)(cat[i].m_y / 42)][(int)(cat[i].m_x / 42) + 1].BombYesNo == BOMB_YES*/	))	//���� ���⿡ ��ź�� �ִٸ�
				{
					cat[i].pos = LEFT;	//@3-5-3 �Դٰ��� �ϵ���
				}
			}
		}

		if (GetTickCount64() - MonsterCountTime > 50)		//@1 Draw���� ���Ǵ� ����~����� �ִϸ��̼�ó�� ���̰�	//@1 �ӵ� ���� ���⼭ ������ �� �ƴ� ��
		{
			m_Acount++;

			m_Bulletcount++;

			if (m_Acount > 5)  m_Acount = 0;


			if (m_Bulletcount > 20) m_Bulletcount = 0;
			MonsterCountTime = GetTickCount64();
		}


		Boom();



		//@3-3-3 ���� �ð��� Ǯ���� .life = true �ǵ���===============================
		for (int i = 0; i < MonsterCount; i++)		//@3-5-1
		{
			if (cat[i].life == false)	//&& Gmanager.m_GameStart == true ����
			{
				if ((cat[i].m_SleepSecond > 0) && (GetTickCount64() - cat[i].m_SleepLifeTime > 1000))	//@ (�ǽð�) �����ð� ���� ���Ҵٸ�
				{
					cat[i].m_SleepSecond--;							//@ (�ǽð�) ���� �ð� �ٿ�
					cat[i].m_SleepLifeTime = GetTickCount64();
				}

				if (cat[i].m_SleepSecond <= 0)	//@ (�ǽð�) �����ð� ����Ǹ�
				{
					cat[i].life = true;		//@ �����ߴ� �� �ٽ� ��Ƴ�����!
				}
			}
		}


		//@10-4 <�簢�� �浹 ó��>	// ���Ͱ� �������� �ʴٸ� Ÿ�ٰ� �Ÿ��� ���������, ����� �ϴ� �� ��� ��Ż�ؼ� Ÿ���� ���󰡵���
		for (int i = 0; i < MonsterCount; i++)		
		{
			if (cat[i].life == true)
			{

				// ������ FollowRegion �ȿ� ����
				//�簢�� �Ÿ� ���	(�����¿� 3ĭ�� 3 * 42(ũ��) )
				if ( sqrt((target.t_x - cat[i].m_x) * (target.t_x - cat[i].m_x)) < 126 
					&& sqrt((target.t_y - cat[i].m_y) * (target.t_y - cat[i].m_y)) < 126 )
				{
					Follow(i); //Ÿ��(����) ����
				}
			}
		}


	}
}

/*

	�⺻ �浹ó��

	= �簢�� �⵿ ���� ó��
	�÷��̾���� �浹 ���� ��ǥ�� (ML, MT) ~ (MR, MB), ź�� �浹 ���� ��ǥ�� (BL, BT) ~ (BR, BB)��� �غ���.
	(ML, MT), (BL, BT)�� ������ �簢���� ���� �� ��ǥ�̰� (MR. MB), (BR, BB)�� �簢���� ������ �Ʒ� ��ǥ�̴�.
	�� ���, �÷��̾�⿡ ź�� �浹 ������ ������ ����.
	* ML < BR && BL < MR && MT < BB && BT < MB		//@1 ���� �� ���� �����ϸ�~ �浹 �´ٰ� �Ǵ�

	= ���� �̿��� �浹 ���� ó��
	���� �̿��� �浹 ���� ó���� ������ ����.
	�÷��̾���� �߽���ǥ�� (MX, MY), ź�� �߽���ǥ�� (BX, BY)��� �ϰ�, �÷��̾���� �浹 ���� �ݰ��� MR,
	ź�� �浹 ���� �ݰ��� BR�̶�� ����. �̶� �÷��̾��� ź�� �浹 ������ �Ʒ��� ����.
	* (MX-BX)*(MX-BX) + (MY-BY)*(MY-BY) < (MR+BR)*(MR+BR)		//@1 ���� �� ���� �����ϸ�~ �浹 �´ٰ� �Ǵ�

*/

//@1 ��Ӱ�� �׸��� �Լ�
void Monster::Draw()
{


	for (int i = 0; i < MonsterCount; i++)		//@3-5-1
	{
		if ((Gmanager.m_GameStart == true) && (cat[i].life == false))				//@1 ���� ���� ������ �� && ����� �� �¾�����
		{
			Sleepimg.Render(cat[i].m_x, cat[i].m_y, 0, 0.3, 0.3);		//@3-3 �ڴ� ����� �׸� 	
		}
	}

	//@10-5 Follow Region �׸� �׸���	//�����¿� 3ĭ�� (3ĭ * 42ũ��)
	for (int i = 0; i < MonsterCount; i++)	
	{
		if ((Gmanager.m_GameStart == true))				
		{
			FollowZone.Render(cat[i].m_x-80, cat[i].m_y - 80, 0, 0.4, 0.4);			//@������ - �ȷο� �� ���� �� �۰� �����. �߽ɵ� �̵� //���� : -126�� 0.5 ũ�⿴��	
		}
	}

	if (Gmanager.m_GameStart == true)
	{
		for (int i = 0; i < MonsterCount; i++)			//@2-2 ����� �߰� (i<2)���� �κ��� (i<3)���� ����.	//@3-5-1 (i<4)�� ����
		{
			if (cat[i].life == true)		//@1 ����� ������� ��
			{
				if (cat[i].pos == LEFT)	//@1 �����(����)�� �������� ���� �ֶ��, ���⿡ �׸��� �׷��ش�
				{
					//@1 m_Account(��� ���ϴ�)�� ���� �׸��� ��� �׷� - �ִϸ��̼�ó��
					catimg1[m_Acount].Render(cat[i].m_x, cat[i].m_y, 0, cat[i].scale, cat[i].scale);						
				}
				if (cat[i].pos == RIGHT)	//@1 �����(����)�� ���������� ���� �ֶ��, ���⿡ �׸��� �׷��ش�.
				{
					 catimg1[m_Acount].Render(cat[i].m_x + cat[i].w, cat[i].m_y, 0, -cat[i].scale, cat[i].scale);

				}
			}

		}
	}

}


//@3-5-2 ���� �̿��� �浹ó��? (��Ÿ��� ������ �̿� - �밢�� �Ÿ��� ���� �Ŵϱ�)
void Monster::Boom()	//@ �� �� �� �� �¾Ҵ��� Ȯ��~ �� ������ ����(���� false, �� true, ����ȿ�� true)
{
	for (int i = 0; i < MonsterCount; i++)		//@3-3-3 i��° ����//@2-2 ����� �߰� (i<2)���� �κ��� (i<3)���� ����.	//@3-5-1 (i<4)�� ����
	{
		for (int row = 0; row < 18; row++)	//@3-3-3 row��° ��ź
		{
			for (int col = 0; col < 30; col++)
			{
				//@3-2 ���� ���� ���� -> m_Boom = true �۵�
				if (cat[i].life == true && bomb.BombArr[row][col].Bomb_burst == true)	//@3-3 ���Ͱ� ����ִ� ���� && ���� ������ ����
				{
					float distance = (float)sqrt((col * 42 - cat[i].m_x) * (col * 42 - cat[i].m_x) +
						(row * 42 - cat[i].m_y) * (row * 42 - cat[i].m_y));

					if (distance < 100)		//@3-2 �浹ó�� �Ÿ� ����
					{
						cat[i].life = false;	//@3-2 ���� ���� - ������ ����.

						cat[i].m_SleepSecond = 5;	//@3-3-3 5�ʵ��� ����
					}
				}

			}
		}
	}

}


//��ǥ�� ���� �ǵ�, ������ ��ġ(X,Y ����) (Ÿ���� X - ������ X) ��ŭ �̵��ϸ� Ÿ�ٿ� �����Ѵٴ� ������ ���� �̿�
void Monster::Follow(int num)	//�Ÿ� ��������� num��° ���Ͱ� Ÿ���� ����
{
	if (GetTickCount64() - FollowTime > 200)
	{
		cat[num].m_x += (target.t_x - cat[num].m_x) / 10;	//10���ʿ� ������ ����������� ������ 10
		cat[num].m_y += (target.t_y - cat[num].m_y) / 10;

		MonsterSound.EffectPlay(Gmanager.MonsterFollowSound);

		FollowTime = GetTickCount64();
	}

}


void Monster::Reset()
{
	/* m_x | double m_y | double x | double y |  double speed |
	int pos | double w | int catkind | int num		*/
	GoodFunction(800, 150, 3, LEFT, 100.0f, 0);	//@2-1 ������ 3���� 0.8�� ����. �ӵ��� ����(10->5)	//@3-3 �ӵ� 3���� ����. m_x, x�� ���� //@3-3-3 �ӵ� 2�� ����, m_x, x�� ����
	GoodFunction(0, 350, 3, RIGHT, 100.0f, 1);	//@2-1 3���� 0.8�� ������ ����. ���� GoodFunction �Լ����� 0.8�� �ϰ� �־����ϱ�~
	GoodFunction(300, 400, 3, RIGHT, 100.0f, 2);	//@2-2 �Դٰ��� ����̿� ���� ��ü �����	//@3-3 �ӵ� 3���� ����. m_x, x�� ����
	GoodFunction(1000, 600, 3, LEFT, 100.0f, 3);		//@3-5-1 ���ο� ���� �߰�����	- D_�κ��̶�, �� �ڿ� num�� �ش��ϴ� �κ�

	MonsterCount = 4;		//@3-5-3 ���� �� ����(�̰ɷ� for�� ���� ����)
}