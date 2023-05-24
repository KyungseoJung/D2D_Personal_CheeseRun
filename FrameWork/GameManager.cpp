#define _CRT_NONSTDC_NO_DEPRECATE
#include "Include.h"

GameManager Gmanager;

//@13-1 FMOD ��ü ���� - Ŭ���� �̸��� ���� �̸��� ������ ��ġ�� �ʵ��� �ڿ� -Sound�� �ٿ�����
//@14-2 FMOD Ŭ���� ��ü ����
FmodSound BGSound;
FmodSound BlockSound;		
FmodSound BombSound;	
FmodSound ItemSound;
FmodSound ScoreSound;
FmodSound MonsterSound;


//@������ (vector->list�θ� ����)
std::list<Trap*> targetTrap;	//@9-1-2 �׽�Ʈ��. Ʈ�� 10����~
//std::vector<Trap*>::iterator iter;	//@9-1-2 �ݺ��� ����
//���� ������ ���� : https://senticoding.tistory.com/54 // http://printf.egloos.com/v/1824410


static DWORD ALPHATime = GetTickCount64();

GameManager::GameManager(void)
{
	GameTime = GetTickCount64();
	m_GameSpeed = 1;
	m_Pause = false;

	//@10-7 �ּ� ó�� �ϱ�. �� �ߵ���
	/*m_SysTem.m_Save1 = 100;	
	m_SysTem.m_Save2 = 200;*/
	//Save();

	m_GameStart = true;			//@1 GameManager(Gmanager) ��ü�� ��������� �������� ���� ����(true)
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

	// �ؽ�Ʈ ����
	//if ((fp = fopen("C:\\SYSTEM.txt","r"))== NULL)
	//{
	//	return ;
	//}
	
	// ���� ����
	if ((fp = fopen("./Save/save.fss","rb"))== NULL)
	{
		return ;
	}
	
	fread(&m_SysTem,sizeof(SysTem),1,fp);

	fclose(fp);
	

	//@13-1 //@14-2 FMOD ���� �׽�Ʈ��
	MainBG = BGSound.AddSoundFile("./resource/Sound/MainBG.mp3", true);	//������ó�� �뷡 ��� ���´�~	//BGSound 0�� ����
	WinBG = BGSound.AddSoundFile("./resource/Sound/WinBG.mp3", false);		//BGSound 1�� : �̰��� �� ȭ�� �����
	LoseBG = BGSound.AddSoundFile("./resource/Sound/LoseBG.mp3", false);	//BGSound 2�� : ���� �� ȭ�� �����


	// ��� ���� ���� ===========================================================
	PushBlockSound = BlockSound.AddSoundFile("./resource/Sound/PushSound.mp3", false);		// BlockSound 0�� : ��� �� �� 
	CrashBlockSound = BlockSound.AddSoundFile("./resource/Sound/CrashBlockSound.mp3", false);		// BlockSound 1�� : ��� �μ� ��
	ShowTrapSound = BlockSound.AddSoundFile("./resource/Sound/ShowTrapSound.mp3", false);		// BlockSound 2�� : ��� �ν��µ�, Trap(����) ������ ��

	// ��ź ���� ���� ===========================================================
	InstallBombSound = BombSound.AddSoundFile("./resource/Sound/InstallBombSound.mp3", false);		// BombSound 0�� : ��ź ���� ��
	PushBombSound = BombSound.AddSoundFile("./resource/Sound/PushSound.mp3", false);		// BombSound 0�� : ��ź �� ��

	// ������ ���� ���� ===========================================================
	GetItemSound = ItemSound.AddSoundFile("./resource/Sound/GetItemSound.mp3", false);			// ItemSound 0�� : ������ ���� ��
	
	// ����(ġ��) ���� ���� ===========================================================
	GetScoreSound = ScoreSound.AddSoundFile("./resource/Sound/GetScoreSound.mp3", false);		// ScoreSound 0�� : ����(ġ��) ���� ��
	
	//���� ���� ����
	MonsterFollowSound = MonsterSound.AddSoundFile("./resource/Sound/MonsterFollowSound.mp3", false);

}

void GameManager::Update()
{
	//if(���� �����) g_Mng.n_Chap = OVER; 
	//@4-1
	if (target.Target_Life == false)
	{
		OverCase = 0;			//@5-2 ���� ���� ��� : 0(LOSE)
		g_Mng.n_Chap = OVER;
		
		BGSound.BGStop();		//@14-2 ���� �� ȭ�� �����
		BGSound.BGPlay(LoseBG);
	}

	//@5-2
	if ((Gmanager.m_Collision == true) && (score.baby.win == true))	//@5-2 Gmanager.m_Collision == true �־���� ��. ������ ȭ�� �������� ���� ���� ȭ�� ���.
	{
		OverCase = 1;			//@5-2 ���� ���� ��� : 1(WIN)
		g_Mng.n_Chap = OVER;

		BGSound.BGStop();		//@14-2 �̰��� �� ȭ�� �����	
		BGSound.BGPlay(WinBG);
	}


	//@13-1 FMOD ���� �׽�Ʈ��
	if (GAME_INIT == TRUE)
	{
		BGSound.BGStop();		//������ Ʋ���� ����� ����
		BGSound.BGPlay(MainBG);
		GAME_INIT = FALSE;		//? �뷡 �̹� Ʋ�����ϱ� �ѹ��� ������ �ϴ� �����ε�! 
								//���� �뷡�� ��� Ʋ�� - �� ó�� �κ��� ���� �ݺ��ż� �ƹ� �Ҹ��� �� ������ �� ������~
	}


}
void GameManager::Save()
{
	// �ؽ�Ʈ ������ "w" ��
	if ((fp = fopen("./Save/save.fss", "wb")) == NULL)
	{
		return;
	}
	fwrite(&m_SysTem, sizeof(SysTem), 1, fp);
	fclose(fp);

}

void GameManager::Delete()
{
//	sound.g_pSoundManager->drr  //@13-1 Sound ���� ���� �ּ� ó��

}
 



void GameManager::GameReset(void)  // ����� ���ӻ� ÷�� �ѹ���  �ʱ�ȭ�Ǵ� �κи� �־���.
{

}


void GameManager::Draw()
{
	//@6-1-2 �� �迭, ���� �׸���(�����ֱ�) ========================================
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

	//@9-3 Ʈ���� �迭, ���� �׸���(�����ֱ�) ========================================
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

	//@10-1 �������� �迭, ���� �׸���(�����ֱ�) ========================================
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
