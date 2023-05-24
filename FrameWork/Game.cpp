#include "Include.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()	//@시작할 때 실행되는 함수
{
	map.Init();
	target.Init();
	monster.Init();

	bomb.Init();	//@2-4 폭탄 추가
	score.Init();	//@5-1
	block.Init();	//@7-1
	trap.Init();	//@9-1
	item.Init();	//@10-1
	minimap.Init();

	//sound.Init();	//@13-1
	Gmanager.Init();
	// 데이타 베이스///////////////////
	//sql.Init();		//@2-6 주석 처리

	Gmanager.GAME_INIT = TRUE;	//@13-1 게임 시작했다~ 알려줘서 GameManager.cpp에서 사운드 켤 수 있도록
}

void Game::Draw()	//@ 매번 그림 그리는 함수
{
	map.Draw();
	trap.Draw();		//@9-1	//다시 블록 앞에 그려지도록 위치 바꿈 //@10-3 다시 바꿈. 블록, 고양이, 폭탄보다 아래에
	monster.Draw();

	bomb.Draw();	//@2-4 폭탄 추가
	block.Draw();		//@7-1
	item.Draw();		//@10-1
	target.Draw();

	score.Draw();		//@5-1	//아기 쥐 이미지가 안 보여서 일부러 Block.h보다 뒤로 옮김	//점수판 있어서 맨 뒤로 옮김

	minimap.Draw();		//@16-1
	Gmanager.Draw();
	// 데이타 베이스///////////////////
	//sql.Draw();	//@2-6 주석 처리

}

// Chap, 재정의 함수 호출
void Game::Update(double frame)	//@ 매 업데이트 때마다 실행하는 함수
{
	//static int a = 0;
	//if(a == 0) 
	//{
	//	GameTime = GetTickCount();
	//	a = 1;
	//}
	static DWORD a = 0;

	if (GetTickCount64() - a > frame)
	{
		key.Update();
		target.Update();
		monster.Update();

		bomb.Update();		//@2-4 폭탄 추가
		score.Update();			//@5-1
		block.Update();			//@7-1
		trap.Update();			//@9-1
		item.Update();			//@10-1
		minimap.Update();

		// 입 맛에 맞게
		map.Update(130);
		Gmanager.Update();
		// 데이타 베이스///////////////////
		// 입 맛에 맞게 (여기선 안쓰임..프레임 값이 필요 할때만.. 그냥 방법만...)
		//sql.Update(frame+3000);		//@2-6 주석 처리

		a = GetTickCount64();
	}


}


void Game::OnMessage(MSG* msg)
{

}