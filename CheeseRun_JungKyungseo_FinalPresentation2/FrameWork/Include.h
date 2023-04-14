#pragma once

/* ---------------------------------------------------
///////////////// 프로그램 파일 //////////////////////

		라이브러리에 필요한 파일입니다.
		지우면 안돼요~~^^;

//////////////////////////////////////////////////////
-----------------------------------------------------*/

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dsound.lib")

// 데이타 베이스///////////////////
//#include <my_global.h>
#include <winsock2.h>
//#include <mysql.h>		//@2-6 주석 처리
//#pragma comment(lib, "libmySQL.lib")	//@2-6 주석 처리

//////////////////////////////////

#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <d3d9.h>
#include <d3dx9.h>
#include <dsound.h>
#include <vector>		//@9-1
#include <list>			//@마지막	//@마지막 (vector->list로만 변경)

#include "DXUTsound.h"

#include "Define.h"
#include "DeviceFont.h"
#include "Sprite.h"
#include "Chap.h"

//@13-1 FMOD 사운드 파일 추가 (3줄) ====================================
#include "FMODENGIN/inc/fmod.hpp"
#pragma	comment (lib, "FMODENGIN/lib/fmodex64_vc.lib") // 1. 경로의 명시적 효과, 속성 창에 라이브러리 추가
using namespace FMOD;

/* ---------------------------------------------------
///////////////// 사용자 추가 파일 ///////////////////

		새로 클래스 만들 때 마다
		헤더파일을 추가해 주세요~

//////////////////////////////////////////////////////
-----------------------------------------------------*/
#include "Game.h"
#include "Logo.h"
#include "Menu.h"
#include "Over.h"
#include "CMng.h"

#include "Method.h"	//@15-1 파일 추가(게임 방법 띄울 페이지)

//#include "Night.h"

#include "Map.h"
#include "Target.h"
#include "Monster.h"

#include "Key.h"
//#include "Sound.h"
#include "GameManager.h"

#include "Bomb.h"		//@2-4 폭탄 파일 추가
#include "Score.h"		//@5-1 점수 파일 추가	
#include "Block.h"		//@7-1 블록 파일 추가	
#include "Trap.h"		//@9-1 트랩 파일 추가 (쥐덫)
#include "Item.h"		//@10-1 아이템 파일 추가

#include "MiniMap.h"	//@16-1 미니맵 파일 추가

#include "FmodSound.h"	//@13-1 사운드 파일 추가





// 데이타 베이스///////////////////
//#include "Mysql.h"	//@2-6 주석 처리

/* ---------------------------------------------------
///////////////// 사용자 추가 파일 ///////////////////

		키 입력 처리 함수입니다.

//////////////////////////////////////////////////////
-----------------------------------------------------*/

inline int KeyDown(int vk)
{
	return ((GetAsyncKeyState(vk) & 0x8000) ? 1 : 0);
}

inline int KeyUp(int vk)
{
	return ((GetAsyncKeyState(vk) & 0x8000) ? 0 : 1);
}