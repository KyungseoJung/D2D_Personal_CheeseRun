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

// Chap, 재정의 함수 호출
void Over::Update(double frame)
{
	//if(처리 후) g_Mng.n_Chap = MENU; 
}

void Over::Draw()
{
	if (Gmanager.OverCase == 0)
	{
		loseBG.Render(0, 0, 0, 1, 1);	//@4-1	(73%로 크기 줄임)
	}

	if (Gmanager.OverCase == 1)
	{
		winBG.Render(0, 0, 0, 1, 1);	//@5-2
	}
}

void Over::OnMessage( MSG* msg )
{
	//@4-1 OVER에서 F11 누르면 다시 메뉴 화면(MENU)으로 가도록
	switch (msg->message)
	{
	case WM_KEYDOWN:
		switch (msg->wParam) {
		case VK_F11:		//@1 게임 끝난 후, F11 누르면~
			if (g_Mng.n_Chap == OVER) {		//@1 현재 화면이 Over.cpp 라면~
				for (int i = 0; i < TOTALCHAP; i++)
					g_Mng.chap[i]->Init();
				
				//@4-1 재시작시, 리셋해야 하는 변수 =================================
				monster.Reset();	//@4-1 몬스터 원 위치로. 잠시 기절했다가
				target.Reset();		//@4-1 타겟 다시 살아나라. 원 위치로
				bomb.Reset();		//@4-1 폭탄 다 사라져라
				score.Reset();		//@5-1 치즈 초기화(위치, 총 치즈 개수, 총 획득한 개수)
				trap.Reset();		//@9-1 트랩 초기화
				item.Reset();						//@10-1 아이템 초기화

				//===================================================================

				g_Mng.n_Chap = MENU;

			}
			break;
		}
	}
}