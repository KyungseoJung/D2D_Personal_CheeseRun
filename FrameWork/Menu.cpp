#include "Include.h"

static DWORD KeyTime = GetTickCount();	//@1 KeyTime�� ���⼭ ���ǵǾ �ٸ� ������ ���̴� �ǰ�~

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Init()
{
	count = 0;
	alpha = 0;
	menuimg.Create("./resource/Img/Menu/Lobby6.png", false, D3DCOLOR_XRGB(0, 0, 0));
}

// Chap, ������ �Լ� ȣ��
void Menu::Update(double frame)
{

	//key.Update();

	//if (xx.xxx > 100 * xxx.xxx)
	//{
	//	if (GetTickCount() - CoinTime > 100)
	//	{
	//		count++;
	//		CoinTime = GetTickCount();
	//	}
	//	if (count > 1) count = 0;
	//}


}

void Menu::Draw()
{

	menuimg.Render(-50, 0, 0, 0.75, 0.75); //�̹������		//@3-4 ���� ȭ���� (-50,0)���� ���ڴ�~
	//@3-4-1 �ʿ� ����
	dv_font.DrawString("Cheese Run-���漭", 0, 0);   //�������

	//if (GetTickCount() - AlTime > 100)
	//{
	//	alpha++;
	//	AlTime = GetTickCount();
	//}

	//if (alpha == 0) menuimg[2].SetColor(255, 255, 255, 255);
	//if (alpha == 1) menuimg[2].SetColor(255, 255, 255, 0);

	//if (xxx.xxx == 0) menuimg[2].Draw(407, 336);
	//else if (count < 2) menuimg[count].Draw(412, 276);

}

void Menu::OnMessage(MSG* msg)
{
	//char aaa[256];
	//_itoa_s(msg->message, aaa,2);
	//dv_font.DrawString(aaa, 10 , 210 ) ;   
	//PostQuitMessage(0);

	switch (msg->message)
	{
	case WM_KEYDOWN:
		switch (msg->wParam) 
		{

		case VK_F9 :			//@15-1 ���� ���� ��, F11 ������
			if (g_Mng.n_Chap == MENU) {		g_Mng.n_Chap = METHOD;	}
			break;



		case VK_F12:	
			//MessageBox(NULL, "", "", 0);		
			if (g_Mng.n_Chap == MENU) {		g_Mng.n_Chap = GAME;	}
			break;
			//@1 ���� ���� ��, F12 ������~
			//@1 ���� ȭ���� 'MENU'���, GAME�� ���۽��Ѷ�~
			// ���� == �̰� �´µ�, =�� �߸� �Ǿ��־���	
			

				

//@13-1 Sound ���� ���� �ּ� ó�� //sound.m_Bk1->Play(0, DSBPLAY_LOOPING);

			
			


		}
		
	}

}