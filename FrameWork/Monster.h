#pragma once
#include "Include.h"


class Monster
{
	typedef struct Mon
	{
		bool life;							// ����(false), ���(true)

		DWORD m_SleepLifeTime;				//@3-3-3 �� ������ (��) ���� �ð� ���� - ���� �Է��ϴ� �� �ƴ�. GetTickCount64�� ���� ���Ǵ� ����. ó������ 0 

		int pos;							// ���ϴ� ���� (RIGHT �Ǵ� LEFT)
		int m_SleepSecond;					//@3-3-3 �� ������ (�ǽð�) �����ִ� ���� �ð� - ���� �ð� ���� - Monster.cpp �� Boom �Լ����� m_Boom1 = true ���� ��, �ð� ����

		double m_x, m_y;					// �ǽð� ��ġ
		double speed;
		double scale;
		double w;							//@3-5-2 �ʿ��� ���� �ְڴ�!! ������ġ�� ���� ���̴� ��ġ �Ÿ� ������	//@1 ���� Draw �� ��, RIGHT�� �̵��ϴ� ���ʹ� �ణ ��ġ�� �̵��ؼ� �׷��� ��. ���� ����

	
	};


public:
	Monster(void);
	~Monster(void);

	Mon cat[4];						//@2-2 2->3 ���� ���� //�ϴ� ����� 3���� ��� �صα�(����� 2, ����� 1)	//@3-5-1 fish[3]���� 4�� ����

	Sprite catimg1[6], Sleepimg;	//@1 ������ �̹��� ������ŭ �迭 ���� - ���� ����(�ִϸ��̼�) ȿ��
	Sprite FollowZone;

	//@3-3 ���߿� ������ �ٲ��ֱ�============================================
	DWORD BoomTime1;				//�̸� ���� : SleepTime		//@3-3 ���� �¾��� ��, ���� �ð�
	DWORD MonsterMoveTime;
	DWORD MonsterCountTime;
	DWORD FollowTime;				//���Ͱ� ������� �ð� ����


	int MonsterCount;				//@3-5-1 ���� �� - �ϳ��ϳ� ��Ÿ���� �ʹ� ����ϱ�. //�� �Ÿ� Reset�Լ����� ����������
	int m_Acount, m_Bulletcount;



	void GoodFunction(double m_x, double m_y, double speed,				//@1 ���� ���� - ��ġ, ����, �ӵ�, �Ը�, 
		int pos, double w, int num);

	void Init();
	void Update();
	void Draw();

	void Boom();
	void Follow(int num);	//@10-4 �Ÿ� ��������� n��° ���Ͱ� Ÿ���� ���󰡵���
	void Reset();

};

extern Monster monster;