#pragma once
#include "Include.h"

class Target
{
	Sprite Tgimg[13];		//@2-3 ������ �׸� ����


public :
	Target();
	~Target();

	//@1 Ÿ�� ȿ���� �Ѿ� ȿ���� ȭ�鿡 ������ Ÿ�̹��� ���� �ٸ��� �ϱ� ����
	DWORD AniTime1;

	//@4-1 ����(Ÿ��) ��� ���� ���� / ������ = ���� LOSE
	bool Target_Life = true;	//���� ����ִ�. ó�� Include.h ���Ϸ� �� �� true�� ������

	int pos;					//Ÿ���� �����̴� ����(RIGHT �Ǵ� LEFT) - key.cpp���� �����ϵ���
	int m_TgCount1;
	double t_x;					//@1 Ÿ���� X�� ��ǥ //�ǽð� ��ġ
	double t_y;					//@1 Ÿ���� Y�� ��ǥ //�ǽð� ��ġ

	void Init();
	void Update();
	void Draw();
	void CheckLife();			//@4-1 ���Ϳ��� �Ÿ� ����ؼ�, Ÿ��(����) ����ֳ� Ȯ���ϴ� �Լ�
	void Reset();
};

extern Target target;