#pragma once
#include "Include.h"

class Trap		//@9-1 Ʈ�� Ŭ����. ���� �̿��� ����
{


public :
	Trap(int x, int y);	//@9-1-2

	Trap();
	~Trap();


	Sprite Trapimg[7];			//Ʈ�� �̹���
	Sprite gyeokja;				//���� �̹���	//@9-3

	bool ShowTrapArr;			//Ʈ���� ���� �����ֱ�	//@9-3

	DWORD TrapCountTime;		//Ʈ�� �̹��� ī��Ʈ �ð�
	DWORD TrapMoveTime;			//Ʈ�� �����̴� �ð� ����

	int Trap_count;				//@10-2 Ʈ�� �̹��� ī��Ʈ
	int x, y;					//Ʈ���� ��ǥ		//Update���� row, col�� ��ġ�� �̿��ؼ� �����Ƿ� int�� ��������	//�ٸ� Ŭ���������� ���ϱ� public���� ����
	int TrapArr[18][30];		//Ʈ���� �迭	-	Block.cpp���� Ư�� ��,���� MAP_TRAP�̵��� Update�� ����
	int pos = UP;				//@10-2 Ʈ�� �����̴� ���� (UP DOWN)
	int speed = 42;				//@10-2 �ѹ��� �����̴� �Ÿ�


	void Init();
	void Update();
	void Draw();
	
	void Reset();				//key.cpp(1�� Ű), Over.cpp(F11Ű)���� �����ϱ�
	void PushTrap(int pos);		//@14-1 �Լ� ������
};

extern Trap trap;