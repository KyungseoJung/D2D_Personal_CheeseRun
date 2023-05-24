#pragma once

struct SysTem
{
	int m_Save1;
	int m_Save2;

};

class GameManager
{
	Sprite Menuimg[2];

public:
	GameManager(void);
	~GameManager(void);

	FILE *fp;
	SysTem m_SysTem;

	bool m_Pause;	
	bool m_GameStart;
	bool m_Collision;		//@1 충돌표시 시작 의미 - key에서 특정 키 누르면 게임 실행(true)
	BOOL GAME_INIT;			//@13-1 배경음악 한번만 틀기 위함. 게임 시작 유무 - Game.cpp Init함수에서 true, false 지정

	DWORD GameTime;
	
	int m_GameSpeed;
	int OverCase;			//@5-2 게임 종료 경우 : 0(LOSE), 1(WIN)

	//@14-2 사운드 관련 변수 지정 ===================================================
	int	MainBG;			//@13-1 사운드 트는 목적
	int WinBG;			//BGSound 1번 : 이겼을 때 화면 배경음	
	int LoseBG;			//BGSound 2번 : 졌을 때 화면 배경음

	int PushBlockSound;		// BlockSound 0번 : 블록 밀 때 
	int CrashBlockSound;	// BlockSound 1번 : 블록 부술 때
	int ShowTrapSound;		// BlockSound 2번 : 블록 부쉈는데, Trap(함정) 등장할 때

	int InstallBombSound;	// BombSound 0번 : 폭탄 놓을 때
	int PushBombSound;		// BombSound 0번 : 폭탄 밀 때

	int GetItemSound;		// ItemSound 0번 : 아이템 먹을 때

	int GetScoreSound;		// ScoreSound 0번 : 점수(치즈) 먹을 때

	int MonsterFollowSound;	// MonsterSound 0번 : 몬스터 Follow존 안에 타겟이 들어갔을 때
			
	// ==============================================================================


	void GameReset(void);
	void Init();
	void Update();
	void Draw();
	void Save();
	void Delete();
	
	
};

extern GameManager Gmanager;