#pragma once
#include "Include.h"

class Bomb
{
	typedef struct BombBomb
	{
		//@2-4 ==============================================================
		bool Bomb_Life;				//@2-4 ��ź�� ��ҳ� �׾���	-	key�� space������ ��ź ����ִ� ����(true) / ���� ����(false)
		
		DWORD m_BombLifeTime;		//@2-4 (��) ��ź ������ �ð� ������ ����	- ���� �Է��ϴ� �� �ƴ�. GetTickCount64�� ���� ���Ǵ� ����. ó������ 0 

		int BombSecond;				//@2-4 (�ǽð�) ��ź ����ִ� �ð�	- ��ź ���� �ð� ���� ���� - InstallBomb(int BombSecond)�Լ����� �� �Է���.
	
	  //@11-1 �� ���� ��� �迭�� ��ġ ����
	//	double Bomb_x;			//@2-4 �����̽��ٷ� ��ź ���� x��ġ
	//	double Bomb_y;			//@2-4 �����̽��ٷ� ��ź ���� y��ġ
	
		//@3-1 =============================================================
		bool Bomb_burst;			//@3-1 ��ź ����(true), ��ź �� ����(false)

		DWORD m_BurstLifeTime;		//@3-1 (��) ���� ������ �ð� ���� 
		
		int BurstSecond;			//@3-1 (�ǽð�)���� ����ִ� �ð� - InstallBomb�Լ����� ����� �� ����
		int BombYesNo = BOMB_NO;				//@11-1 BOMB_YES �Ǵ� BOMB_NO
	};

public:
	Bomb();
	~Bomb();

	BombBomb BombArr[18][30];		//@11-1 ��ź�� �����ֳ�, �ƴѰ� �迭
	
	Sprite Bombimg[8];			//@ ��ź �̹��� ���� �迭	//@3-1 private ���ʿ��� public���� ��ġ �ű�
	Sprite BombBurstimg[10];	//@3-1 ��ź ������ �� �̹���	

	DWORD m_BombAniTime;		//@2 ��ź �̹��� ��� ���� ����
	DWORD m_BurstAniTime;		//@3-1 ��ź ������ �� �̹��� ��� ���� ����
	
	int m_BombCount;			//@2 ��ź �̹��� ��� ���� ����
	int m_BurstCount;			//@3-1 ��ź ������ �� �̹��� ��� ���� ����
	int BombPushCount;			//@12-1 ��ź �з����� �� �׸��� �ӵ� ���� �Լ�
	int BombNumber;				//@2-5 ���� ȭ�鿡 ���� ��ź�� ����	//key.cpp���� SPACE ���� ������ �����ϵ���
	int BombNumberlimit;		// ���� ������ �����ڿ���


	void Init();
	void Update();
	void Draw();

	void Reset();						//@4-1	�ʱ�ȭ �� ��, ����
	void InstallBomb(int BombSecond);	//@11-1 ���� �������� key.cpp���� �ڵ� ������
	void PushBomb(int pos);				//@12-1 ��ź �̴� �Լ�
};

extern Bomb bomb;