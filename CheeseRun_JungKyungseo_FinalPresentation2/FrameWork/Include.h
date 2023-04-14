#pragma once

/* ---------------------------------------------------
///////////////// ���α׷� ���� //////////////////////

		���̺귯���� �ʿ��� �����Դϴ�.
		����� �ȵſ�~~^^;

//////////////////////////////////////////////////////
-----------------------------------------------------*/

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dsound.lib")

// ����Ÿ ���̽�///////////////////
//#include <my_global.h>
#include <winsock2.h>
//#include <mysql.h>		//@2-6 �ּ� ó��
//#pragma comment(lib, "libmySQL.lib")	//@2-6 �ּ� ó��

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
#include <list>			//@������	//@������ (vector->list�θ� ����)

#include "DXUTsound.h"

#include "Define.h"
#include "DeviceFont.h"
#include "Sprite.h"
#include "Chap.h"

//@13-1 FMOD ���� ���� �߰� (3��) ====================================
#include "FMODENGIN/inc/fmod.hpp"
#pragma	comment (lib, "FMODENGIN/lib/fmodex64_vc.lib") // 1. ����� ����� ȿ��, �Ӽ� â�� ���̺귯�� �߰�
using namespace FMOD;

/* ---------------------------------------------------
///////////////// ����� �߰� ���� ///////////////////

		���� Ŭ���� ���� �� ����
		��������� �߰��� �ּ���~

//////////////////////////////////////////////////////
-----------------------------------------------------*/
#include "Game.h"
#include "Logo.h"
#include "Menu.h"
#include "Over.h"
#include "CMng.h"

#include "Method.h"	//@15-1 ���� �߰�(���� ��� ��� ������)

//#include "Night.h"

#include "Map.h"
#include "Target.h"
#include "Monster.h"

#include "Key.h"
//#include "Sound.h"
#include "GameManager.h"

#include "Bomb.h"		//@2-4 ��ź ���� �߰�
#include "Score.h"		//@5-1 ���� ���� �߰�	
#include "Block.h"		//@7-1 ��� ���� �߰�	
#include "Trap.h"		//@9-1 Ʈ�� ���� �߰� (�㵣)
#include "Item.h"		//@10-1 ������ ���� �߰�

#include "MiniMap.h"	//@16-1 �̴ϸ� ���� �߰�

#include "FmodSound.h"	//@13-1 ���� ���� �߰�





// ����Ÿ ���̽�///////////////////
//#include "Mysql.h"	//@2-6 �ּ� ó��

/* ---------------------------------------------------
///////////////// ����� �߰� ���� ///////////////////

		Ű �Է� ó�� �Լ��Դϴ�.

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