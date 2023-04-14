#include "Include.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()	//@������ �� ����Ǵ� �Լ�
{
	map.Init();
	target.Init();
	monster.Init();

	bomb.Init();	//@2-4 ��ź �߰�
	score.Init();	//@5-1
	block.Init();	//@7-1
	trap.Init();	//@9-1
	item.Init();	//@10-1
	minimap.Init();

	//sound.Init();	//@13-1
	Gmanager.Init();
	// ����Ÿ ���̽�///////////////////
	//sql.Init();		//@2-6 �ּ� ó��

	Gmanager.GAME_INIT = TRUE;	//@13-1 ���� �����ߴ�~ �˷��༭ GameManager.cpp���� ���� �� �� �ֵ���
}

void Game::Draw()	//@ �Ź� �׸� �׸��� �Լ�
{
	map.Draw();
	trap.Draw();		//@9-1	//�ٽ� ��� �տ� �׷������� ��ġ �ٲ� //@10-3 �ٽ� �ٲ�. ���, �����, ��ź���� �Ʒ���
	monster.Draw();

	bomb.Draw();	//@2-4 ��ź �߰�
	block.Draw();		//@7-1
	item.Draw();		//@10-1
	target.Draw();

	score.Draw();		//@5-1	//�Ʊ� �� �̹����� �� ������ �Ϻη� Block.h���� �ڷ� �ű�	//������ �־ �� �ڷ� �ű�

	minimap.Draw();		//@16-1
	Gmanager.Draw();
	// ����Ÿ ���̽�///////////////////
	//sql.Draw();	//@2-6 �ּ� ó��

}

// Chap, ������ �Լ� ȣ��
void Game::Update(double frame)	//@ �� ������Ʈ ������ �����ϴ� �Լ�
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

		bomb.Update();		//@2-4 ��ź �߰�
		score.Update();			//@5-1
		block.Update();			//@7-1
		trap.Update();			//@9-1
		item.Update();			//@10-1
		minimap.Update();

		// �� ���� �°�
		map.Update(130);
		Gmanager.Update();
		// ����Ÿ ���̽�///////////////////
		// �� ���� �°� (���⼱ �Ⱦ���..������ ���� �ʿ� �Ҷ���.. �׳� �����...)
		//sql.Update(frame+3000);		//@2-6 �ּ� ó��

		a = GetTickCount64();
	}


}


void Game::OnMessage(MSG* msg)
{

}