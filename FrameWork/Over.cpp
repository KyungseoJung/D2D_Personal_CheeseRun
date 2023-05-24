#include "Include.h"


Over::Over()
{
}

Over::~Over()
{
}

void Over::Init()
{
	//@4-1
	loseBG.Create("./resource/Img/Ending/LOSE3.png", false, D3DCOLOR_XRGB(0, 0, 0));

	//@5-2
	winBG.Create("./resource/Img/Ending/WIN3.png", false, D3DCOLOR_XRGB(0, 0, 0));
}

// Chap, ������ �Լ� ȣ��
void Over::Update(double frame)
{
	//if(ó�� ��) g_Mng.n_Chap = MENU; 
}

void Over::Draw()
{
	if (Gmanager.OverCase == 0)
	{
		loseBG.Render(0, 0, 0, 1, 1);	//@4-1	(73%�� ũ�� ����)
	}

	if (Gmanager.OverCase == 1)
	{
		winBG.Render(0, 0, 0, 1, 1);	//@5-2
	}
}

void Over::OnMessage( MSG* msg )
{
	//@4-1 OVER���� F11 ������ �ٽ� �޴� ȭ��(MENU)���� ������
	switch (msg->message)
	{
	case WM_KEYDOWN:
		switch (msg->wParam) {
		case VK_F11:		//@1 ���� ���� ��, F11 ������~
			if (g_Mng.n_Chap == OVER) {		//@1 ���� ȭ���� Over.cpp ���~
				for (int i = 0; i < TOTALCHAP; i++)
					g_Mng.chap[i]->Init();
				
				//@4-1 ����۽�, �����ؾ� �ϴ� ���� =================================
				monster.Reset();	//@4-1 ���� �� ��ġ��. ��� �����ߴٰ�
				target.Reset();		//@4-1 Ÿ�� �ٽ� ��Ƴ���. �� ��ġ��
				bomb.Reset();		//@4-1 ��ź �� �������
				score.Reset();		//@5-1 ġ�� �ʱ�ȭ(��ġ, �� ġ�� ����, �� ȹ���� ����)
				trap.Reset();		//@9-1 Ʈ�� �ʱ�ȭ
				item.Reset();						//@10-1 ������ �ʱ�ȭ

				//===================================================================

				g_Mng.n_Chap = MENU;

			}
			break;
		}
	}
}