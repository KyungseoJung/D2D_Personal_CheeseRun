#include "Include.h"


Target	target;


Target::Target()
{
	t_x = 600;				//@1 Ÿ��(���׶�� ����)�� x��ǥ ��ġ	//�ǽð� ��ġ
	t_y = 300;				//@1 Ÿ��(���׶�� ����)�� y��ǥ ��ġ	//�ǽð� ��ġ
}

Target::~Target()
{
}

void Target::Init()
{
	char FileName[256];

	for (int i = 0; i < 13; i++)		//@2-3 ������ �׸� �����ϱ�
	{
		sprintf_s(FileName, "./resource/Img/Target/Mouse/output/Mouse_001_%04d.png", i);
		Tgimg[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
}

void Target::Update()
{


	if(GetTickCount() - AniTime1 > 100)				//@2-3 ������ �ӵ��� (>1000)���� (>100)���� ����
	{
		m_TgCount1++;
		if(m_TgCount1>12) m_TgCount1 = 0;			//@2-3 (m_TgCount1>1) �κ��� 12�� ����
		AniTime1 = GetTickCount();
	}

	//@4-1
	CheckLife();

}

//@4-1 <���� �̿��� �浹ó��> - ���Ϳ��� �Ÿ� ����ؼ�, Ÿ��(����) ����ֳ� Ȯ���ϴ� �Լ�
void Target::CheckLife()
{
	for (int i = 0; i < monster.MonsterCount; i++)		//@3-3-3 i��° ����//@2-2 ����� �߰� (i<2)���� �κ��� (i<3)���� ����.	//@3-5-1 (i<4)�� ����
	{
		if (Target_Life == true)		//Ÿ���� ����ִٸ�
		{
			float distance = (float)sqrt((monster.cat[i].m_x - t_x) * (monster.cat[i].m_x - t_x) +
				(monster.cat[i].m_y - t_y) * (monster.cat[i].m_y - t_y));

			if (distance < 50)	// ���Ϳ��� �Ÿ�
			{
				Target_Life = false;	//Ÿ��(����) ���� ��
			}
		}
	}
}

void Target::Draw()
{	
	if((Gmanager.m_GameStart==true)	&& pos == LEFT)				//@1 ���� ���� ���¶�� && �������� ���� �ִٸ�
		Tgimg[m_TgCount1].Render(t_x, t_y, 0, 0.7, 0.7);		//@ Ÿ�� �׸���. �� ��ǥ ��ġ��		//��! ����! �׸���
	else if ((Gmanager.m_GameStart == true) && pos == RIGHT)
		Tgimg[m_TgCount1].Render(t_x + 50, t_y, 0, -0.7, 0.7);	//���� �ٲٸ�, �¿� ����� �׸���.
}

void Target::Reset()
{
	t_x = 600;
	t_y = 300;
	
	Target_Life = true;	//@4-1 Ÿ�� ����ִ�
}