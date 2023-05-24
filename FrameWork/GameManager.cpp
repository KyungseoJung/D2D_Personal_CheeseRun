#define _CRT_NONSTDC_NO_DEPRECATE
#include "Include.h"

GameManager Gmanager;

//@13-1 FMOD 객체 생성 - 클래스 이름과 사운드 이름이 완전히 겹치지 않도록 뒤에 -Sound를 붙여주자
//@14-2 FMOD 클래스 객체 선언
FmodSound BGSound;
FmodSound BlockSound;		
FmodSound BombSound;	
FmodSound ItemSound;
FmodSound ScoreSound;
FmodSound MonsterSound;


//@마지막 (vector->list로만 변경)
std::list<Trap*> targetTrap;	//@9-1-2 테스트용. 트랩 10개만~
//std::vector<Trap*>::iterator iter;	//@9-1-2 반복자 선언
//벡터 포인터 참조 : https://senticoding.tistory.com/54 // http://printf.egloos.com/v/1824410


static DWORD ALPHATime = GetTickCount64();

GameManager::GameManager(void)
{
	GameTime = GetTickCount64();
	m_GameSpeed = 1;
	m_Pause = false;

	//@10-7 주석 처리 하기. 안 뜨도록
	/*m_SysTem.m_Save1 = 100;	
	m_SysTem.m_Save2 = 200;*/
	//Save();

	m_GameStart = true;			//@1 GameManager(Gmanager) 객체가 만들어지는 순간부터 게임 시작(true)
}

GameManager::~GameManager(void)
{
}

void GameManager::Init()
{
	//Menuimg[0].Create("./resource/Effect/menu/1.png",false,D3DCOLOR_XRGB(0,0,0));
	//Menuimg[1].Create("./resource/Effect/menu/2.png",false,D3DCOLOR_XRGB(0,0,0));


	//char seps[] = ",\n";
	//char *token;

	// 텍스트 버전
	//if ((fp = fopen("C:\\SYSTEM.txt","r"))== NULL)
	//{
	//	return ;
	//}
	
	// 기계어 버전
	if ((fp = fopen("./Save/save.fss","rb"))== NULL)
	{
		return ;
	}
	
	fread(&m_SysTem,sizeof(SysTem),1,fp);

	fclose(fp);
	

	//@13-1 //@14-2 FMOD 사운드 테스트용
	MainBG = BGSound.AddSoundFile("./resource/Sound/MainBG.mp3", true);	//루프문처럼 노래 계속 나온다~	//BGSound 0번 사운드
	WinBG = BGSound.AddSoundFile("./resource/Sound/WinBG.mp3", false);		//BGSound 1번 : 이겼을 때 화면 배경음
	LoseBG = BGSound.AddSoundFile("./resource/Sound/LoseBG.mp3", false);	//BGSound 2번 : 졌을 때 화면 배경음


	// 블록 관련 사운드 ===========================================================
	PushBlockSound = BlockSound.AddSoundFile("./resource/Sound/PushSound.mp3", false);		// BlockSound 0번 : 블록 밀 때 
	CrashBlockSound = BlockSound.AddSoundFile("./resource/Sound/CrashBlockSound.mp3", false);		// BlockSound 1번 : 블록 부술 때
	ShowTrapSound = BlockSound.AddSoundFile("./resource/Sound/ShowTrapSound.mp3", false);		// BlockSound 2번 : 블록 부쉈는데, Trap(함정) 등장할 때

	// 폭탄 관련 사운드 ===========================================================
	InstallBombSound = BombSound.AddSoundFile("./resource/Sound/InstallBombSound.mp3", false);		// BombSound 0번 : 폭탄 놓을 때
	PushBombSound = BombSound.AddSoundFile("./resource/Sound/PushSound.mp3", false);		// BombSound 0번 : 폭탄 밀 때

	// 아이템 관련 사운드 ===========================================================
	GetItemSound = ItemSound.AddSoundFile("./resource/Sound/GetItemSound.mp3", false);			// ItemSound 0번 : 아이템 먹을 때
	
	// 점수(치즈) 관련 사운드 ===========================================================
	GetScoreSound = ScoreSound.AddSoundFile("./resource/Sound/GetScoreSound.mp3", false);		// ScoreSound 0번 : 점수(치즈) 먹을 때
	
	//몬스터 관련 사운드
	MonsterFollowSound = MonsterSound.AddSoundFile("./resource/Sound/MonsterFollowSound.mp3", false);

}

void GameManager::Update()
{
	//if(게임 종료시) g_Mng.n_Chap = OVER; 
	//@4-1
	if (target.Target_Life == false)
	{
		OverCase = 0;			//@5-2 게임 종료 경우 : 0(LOSE)
		g_Mng.n_Chap = OVER;
		
		BGSound.BGStop();		//@14-2 졌을 때 화면 배경음
		BGSound.BGPlay(LoseBG);
	}

	//@5-2
	if ((Gmanager.m_Collision == true) && (score.baby.win == true))	//@5-2 Gmanager.m_Collision == true 넣어줘야 됨. 없으면 화면 시작하자 마자 종료 화면 뜬다.
	{
		OverCase = 1;			//@5-2 게임 종료 경우 : 1(WIN)
		g_Mng.n_Chap = OVER;

		BGSound.BGStop();		//@14-2 이겼을 때 화면 배경음	
		BGSound.BGPlay(WinBG);
	}


	//@13-1 FMOD 사운드 테스트용
	if (GAME_INIT == TRUE)
	{
		BGSound.BGStop();		//기존에 틀었던 배경음 끄고
		BGSound.BGPlay(MainBG);
		GAME_INIT = FALSE;		//? 노래 이미 틀었으니까 한번만 나오게 하는 목적인듯! 
								//같은 노래를 계속 틀면 - 맨 처음 부분이 무한 반복돼서 아무 소리도 안 나오는 것 같겠지~
	}


}
void GameManager::Save()
{
	// 텍스트 버전은 "w" 로
	if ((fp = fopen("./Save/save.fss", "wb")) == NULL)
	{
		return;
	}
	fwrite(&m_SysTem, sizeof(SysTem), 1, fp);
	fclose(fp);

}

void GameManager::Delete()
{
//	sound.g_pSoundManager->drr  //@13-1 Sound 파일 관련 주석 처리

}
 



void GameManager::GameReset(void)  // 여기는 게임상 첨에 한번만  초기화되는 부분만 넣어줌.
{

}


void GameManager::Draw()
{
	//@6-1-2 맵 배열, 격자 그리기(보여주기) ========================================
	char str[10];

	if (block.ShowBlockArr == TRUE)
	{
		block.gyeokja.Render(15,42, 0, 1, 1);
		for (int row = 0; row < 18; row++)
		{
			for (int col = 0; col < 30; col++)
			{
				_itoa(block.BlockArr[row][col].BlockState, str, 10);
				dv_font.DrawString(str, col * 42 +42, row * 42 + 42);
			}
		}
	}
	// =======================================================================

	//@9-3 트랩의 배열, 격자 그리기(보여주기) ========================================
	if (trap.ShowTrapArr == TRUE)
	{
		trap.gyeokja.Render(15, 42, 0, 1, 1);
		for (int row = 0; row < 18; row++)
		{
			for (int col = 0; col < 30; col++)
			{
				_itoa(trap.TrapArr[row][col], str, 10);
				dv_font.DrawString(str, col * 42 +42, row * 42 + 42);
			}
		}
	}
	// =======================================================================

	//@10-1 아이템의 배열, 격자 그리기(보여주기) ========================================
	if (item.ShowItemArr == TRUE)
	{
		item.gyeokja.Render(15, 42, 0, 1, 1);
		for (int row = 0; row < 18; row++)
		{
			for (int col = 0; col < 30; col++)
			{
				_itoa(item.ItemArr1[row][col].ItemState, str, 10);
				dv_font.DrawString(str, col * 42 + 42, row * 42 + 42);
			}
		}
	}
	// =======================================================================
}
