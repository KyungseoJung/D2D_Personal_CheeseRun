#include "Include.h"
//@15-1 ��� �̹��� ��� ���� �߰�
Method::Method()
{
	//ShowHowto1 = false;	//@15-1 �⺻ ���� false���� �ϴϱ�~
}

Method::~Method()
{
}

void Method::Init()
{
	methodimg.Create("./resource/Img/Method/Howto2-1.png", false, D3DCOLOR_XRGB(0, 0, 0));
}

// Chap, ������ �Լ� ȣ��
void Method::Update(double frame)
{
}

void Method::Draw()
{
	methodimg.Render(-10, -25, 0, 0.315, 0.315); //�̹������		//@3-4 ���� ȭ���� (-50,0)���� ���ڴ�~
}

void Method::OnMessage(MSG* msg)
{

	switch (msg->message)
	{
	case WM_KEYDOWN:
		switch (msg->wParam) {
		case VK_F12:		//@1 METHOD ȭ�鿡��, F12 ������~ GAME�� �ش��ϴ� Game���� �����ض�~
			if (g_Mng.n_Chap == METHOD) {	g_Mng.n_Chap = GAME;	}
			break;				
		}
	}
}