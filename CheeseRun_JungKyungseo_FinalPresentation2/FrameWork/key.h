#pragma once
#include "Include.h"

class Key
{

public:
	Key(void);
	~Key(void);
	
	DWORD KeyTime;
	// 동시 키 선택을 위함	//@1 - 각각의 실행 속도도 조정할 겸
	DWORD KeyTime1;
	DWORD KeyTime2;
	DWORD KeyTime3;
	DWORD KeyTime4;	//@12-1


	
	void Update();
};

extern Key key;