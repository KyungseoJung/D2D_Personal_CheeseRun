#pragma once
#include "Include.h"

class Item	//@10-1
{
	typedef struct Item1
	{
		bool show;	//�������� ��Ÿ���ֳ�, �ƴѰ�
		int ItemState;	//ITEM_NO(0) �Ǵ� ITEM_YES(1)
	};

public:
	Item();
	~Item();

	Item1 ItemArr1[18][30];

	Sprite Itemimg1;	//������1 �̹��� (����� ��� ����)
	Sprite gyeokja;		//���� �̹���

	bool ShowItemArr;	//Ʈ���� ���� �����ֱ�

	//int x1, y1;			//������1�� ��ǥ
	//int x2, y2;			//������2�� ��ǥ


	void Init();
	void Update();
	void Draw();

	void Reset();		//@10-2 ������ �ʱ�ȭ
	void PushItem(int pos);		//@14-1 �Լ� ������
};

extern Item item;