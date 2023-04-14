#include "Include.h"
//@15-1 방법 이미지 띄울 파일 추가
Method::Method()
{
	//ShowHowto1 = false;	//@15-1 기본 값은 false여야 하니까~
}

Method::~Method()
{
}

void Method::Init()
{
	methodimg.Create("./resource/Img/Method/Howto2-1.png", false, D3DCOLOR_XRGB(0, 0, 0));
}

// Chap, 재정의 함수 호출
void Method::Update(double frame)
{
}

void Method::Draw()
{
	methodimg.Render(-10, -25, 0, 0.315, 0.315); //이미지출력		//@3-4 메인 화면을 (-50,0)부터 띄우겠다~
}

void Method::OnMessage(MSG* msg)
{

	switch (msg->message)
	{
	case WM_KEYDOWN:
		switch (msg->wParam) {
		case VK_F12:		//@1 METHOD 화면에서, F12 누르면~ GAME에 해당하는 Game파일 실행해라~
			if (g_Mng.n_Chap == METHOD) {	g_Mng.n_Chap = GAME;	}
			break;				
		}
	}
}