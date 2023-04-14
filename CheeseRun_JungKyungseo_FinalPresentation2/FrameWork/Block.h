#pragma once
#include "Include.h"

class Block									//@7-1
{			
	typedef struct MapBlock
	{
		int BlockState;						//MAP_EMPTY, MAP_BLOCK. MAP_BROKEN ���ʴ�� 0, 1, 2 + MAP_TRAP�̸� 3
		int CrushState;						//�ν��� ���� - ����� �ִ� ���, 3�� ũ�⾿ ���� ����. 0�̸� �� �ν��� ��.
	};

public:
	Block();
	~Block();

	MapBlock BlockArr[18][30];				//�� �迭		//int BlockArr[30][18];	�̰� �ƴ�. �򰥸��� ����. �ٽ� ������
	//MAP_EMPTY(0), MAP_BLOCK(1), MAP_BROKEN(2), MAP_TRAP(3), MAP_ITEM(4)

	Sprite Blockimg1, Blockimg2, Blockimg3;	//�ν�����ŭ ��� �̹��� �����ֵ���(���� CrushState�� 2/ 1/ 0�� ��)
//@6-1-2	�� �迭 ==================================
	Sprite gyeokja;							//���� �̹���
	Sprite map_Block;						//��� �̹���

	bool ShowBlockArr;						//���� ���� �����ֱ�

	DWORD BlockMakeTime;					//�μ��� ���(MAP_BROKEN) �ð� ������, �ٽ� ���⵵��(MAP_BLOCK)

	void Init();
	void Update();
	void Draw();

	void CrushBlock();						//@11-2
	void PushBlock(int pos);				//@14-1 �Լ� ������
};

extern Block block;