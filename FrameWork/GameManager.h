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
	bool m_Collision;		//@1 �浹ǥ�� ���� �ǹ� - key���� Ư�� Ű ������ ���� ����(true)
	BOOL GAME_INIT;			//@13-1 ������� �ѹ��� Ʋ�� ����. ���� ���� ���� - Game.cpp Init�Լ����� true, false ����

	DWORD GameTime;
	
	int m_GameSpeed;
	int OverCase;			//@5-2 ���� ���� ��� : 0(LOSE), 1(WIN)

	//@14-2 ���� ���� ���� ���� ===================================================
	int	MainBG;			//@13-1 ���� Ʈ�� ����
	int WinBG;			//BGSound 1�� : �̰��� �� ȭ�� �����	
	int LoseBG;			//BGSound 2�� : ���� �� ȭ�� �����

	int PushBlockSound;		// BlockSound 0�� : ��� �� �� 
	int CrashBlockSound;	// BlockSound 1�� : ��� �μ� ��
	int ShowTrapSound;		// BlockSound 2�� : ��� �ν��µ�, Trap(����) ������ ��

	int InstallBombSound;	// BombSound 0�� : ��ź ���� ��
	int PushBombSound;		// BombSound 0�� : ��ź �� ��

	int GetItemSound;		// ItemSound 0�� : ������ ���� ��

	int GetScoreSound;		// ScoreSound 0�� : ����(ġ��) ���� ��

	int MonsterFollowSound;	// MonsterSound 0�� : ���� Follow�� �ȿ� Ÿ���� ���� ��
			
	// ==============================================================================


	void GameReset(void);
	void Init();
	void Update();
	void Draw();
	void Save();
	void Delete();
	
	
};

extern GameManager Gmanager;