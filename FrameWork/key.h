#pragma once
#include "Include.h"

class Key
{

public:
	Key(void);
	~Key(void);
	
	DWORD KeyTime;
	// ���� Ű ������ ����	//@1 - ������ ���� �ӵ��� ������ ��
	DWORD KeyTime1;
	DWORD KeyTime2;
	DWORD KeyTime3;
	DWORD KeyTime4;	//@12-1


	
	void Update();
};

extern Key key;