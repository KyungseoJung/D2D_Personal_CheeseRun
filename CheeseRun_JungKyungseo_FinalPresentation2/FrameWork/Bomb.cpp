#include "Include.h"
//BombArr[0]라 적힌 부분은 모두 @2-5-2

Bomb bomb;		//@2-5 주석 처리
//Bomb bomb[10];			//@2-5

extern FmodSound BombSound;	//@14-2	사운드 추가


Bomb::Bomb()
{
	m_BombAniTime = 0;
	m_BombCount = 0;
	m_BurstAniTime = 0;		//@3-1 추가한 변수 0으로 초기화
	m_BurstCount = 0;		//@3-1 추가한 변수 0으로 초기화

	BombNumberlimit = 5;	
}

Bomb::~Bomb()
{

}

void Bomb::Init()
{


	char FileName[256];

	for (int i = 0; i < 8; i++)
	{
		sprintf_s(FileName, "./resource/Img/Bomb/output_Bomb/Bomb_%04d.png", i );
		Bombimg[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	for (int i = 0; i < 10; i++)
	{
		sprintf_s(FileName, "./resource/Img/Bomb/output_Burst/Burst_%04d.png", i );
		BombBurstimg[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
}

void Bomb::Update()
{
	
	//if (GetTickCount64() - m_BombAniTime > 100)			//@2-4 폭탄 그림 움직이는 속도 조정	//GetTickCount64로 하는 게 맞는 것 같아서 이걸로 함
	if (GetTickCount64() -m_BombAniTime > 100)
	{
		m_BombCount++;
		if (m_BombCount > 6) m_BombCount = 0;			//@2-4 폭탄 그림 0번부터 7번까지 있으니까
		
		m_BombAniTime = GetTickCount64();
	}

	//@3-1 =====================================
	if(GetTickCount64() - m_BurstAniTime> 100)			//@3-1 폭탄 연기 움직이는 속도 조정 - 다른 변수 만들자
	{
		m_BurstCount++;
		if (m_BurstCount > 8) m_BurstCount = 0;		//@3-1 연기 그림 0번부터 9번까지 있으니까

		m_BurstAniTime = GetTickCount64();
	}


	for (int i = 0; i <18; i++)			//@2-5-3 for문 걸어주기(BombNumber 변수를 기준으로)	
	{						//BombNumber 대신 BombNumberlimit 걸어주면 - 아예 튕김 - 그러면 아예 Draw의 for문처럼 구현하면 됨!

		for (int j = 0; j < 30; j++)
		{

			if (BombArr[i][j].Bomb_Life == true && Gmanager.m_GameStart == true)
			{
				//BombArr[i][j].Bomb_burst = false;	//@3-1 폭탄이 안 터진 상태	- key.cpp에서 구현하자 - 디폴트로 false가 들어가있지 않을까?

				if ((BombArr[i][j].BombSecond > 0) && (GetTickCount64() - BombArr[i][j].m_BombLifeTime > 1000))		//@2-4 1초마다 BombSecond 줄어들도록
				{
					BombArr[i][j].BombSecond--;								//@2-4 시간이 지날수록 폭탄 수명 줄어듦!

					BombArr[i][j].m_BombLifeTime = GetTickCount64();
				}

				if (BombArr[i][j].BombSecond <= 0)		//@2-4 폭탄 타이머 시간 끝나면
				{
					BombArr[i][j].Bomb_burst = true;		//@3-1 폭탄 터진 상태 - 연기 나기 시작

				}
			}

			if (BombArr[i][j].Bomb_burst == true && Gmanager.m_GameStart == true)	//@3-1 폭탄 터진 상태 && 게임 시작 상태
			{
				if ((BombArr[i][j].BurstSecond > 0) && (GetTickCount64() - BombArr[i][j].m_BurstLifeTime > 1000))
				{
					BombArr[i][j].BurstSecond--;

					BombArr[i][j].m_BurstLifeTime = GetTickCount64();
				}

				if (BombArr[i][j].BurstSecond <= 0)
				{
					BombArr[i][j].Bomb_burst = false;		//@3-1 폭탄 연기 종료
					BombArr[i][j].Bomb_Life = false;		//@2-4 폭탄 수명 종료. 
					BombArr[i][j].BombYesNo = BOMB_NO;		//@11-1 시간 다 지났으니 이제 이 자리에는 폭탄 없다.
					BombNumber--;							//@2-5-3 죽으면 현재 폭탄의 개수 감소시키기
				}
			}
		}
	}



}

void Bomb::Draw()
{

		/*
		if (SmokeBomb[i].Bomb_Life == true && Gmanager.m_GameStart == true)	//@2-4 폭탄 수명 살아있는 상태 && 게임 시작 상태라면
		{
			//@2-4 이 코드를 여기에 적으면 폭탄이 계속 타겟(제리) 위치와 같도록 업데이트되니까 key.cpp에 그리기
			//Bomb_x = target.t_x;		//@2-4 폭탄 놓은 위치 저장하고 그 자리에 계속 그려지도록
			//Bomb_y = target.t_y;

			Bombimg[m_BombCount].SetColor(255, 255, 255, 255);
			Bombimg[m_BombCount].Render(SmokeBomb[i].Bomb_x , SmokeBomb[i].Bomb_y , 0, 1, 1);		//@2-4 폭탄 놓는 위치 지정
		}

		if (SmokeBomb[i].Bomb_burst == true && Gmanager.m_GameStart == true)					//@3-1 폭탄 연기 수명 살아있는 상태 && 게임 시작 상태
		{
			BombBurstimg[m_BurstCount].SetColor(255, 255, 255, 255);
			BombBurstimg[m_BurstCount].Render(SmokeBomb[i].Bomb_x -80.0f, SmokeBomb[i].Bomb_y -80.0f, 0, 0.5, 0.5);	//@3-1 연기 그리는 위치 지정
		}

		*/

		//@11-1 폭탄을 배열에 위치하도록 설정
		for (int row = 0; row < 18; row++)
		{
			for (int col = 0; col < 30; col++)
			{
				if (BombArr[row][col].BombYesNo == BOMB_YES)			//만약 폭탄이 놓여져 있다면
				{
						if (BombArr[row][col].Bomb_Life == true && Gmanager.m_GameStart == true)	//@2-4 폭탄 수명 살아있는 상태 && 게임 시작 상태라면
						{
							Bombimg[m_BombCount].SetColor(255, 255, 255, 255);
							Bombimg[m_BombCount].Render(col * 42 + 10, row * 42 + 15, 0, 1, 1);
						}

						if (BombArr[row][col].Bomb_burst == true && Gmanager.m_GameStart == true)	// 폭탄 연기 수명 살아있는 상태 && 게임 시작 상태
						{
							BombBurstimg[m_BurstCount].SetColor(255, 255, 255, 255);
							BombBurstimg[m_BurstCount].Render(col * 42 -80.0f, row * 42 - 80.0f, 0, 0.5, 0.5);	//@3-1 연기 그리는 위치 지정
						}
					
				}
			}
		}

}

void Bomb::Reset()
{
	for (int i = 0; i < 18; i++)		//@2-5-3 VK_CONTROL 누르면, 모든 폭탄 다 죽음(터지는 게 아니라 죽기만 함)
	{
		for (int j = 0; j < 30; j++)
		{
			BombArr[i][j].Bomb_Life = false;
			BombArr[i][j].Bomb_burst = false;
			BombNumber = 0;						//@ 현재 폭탄의 개수 초기화
		}
	}

}

void Bomb::InstallBomb(int BombSecond)
{
	if (bomb.BombNumber < bomb.BombNumberlimit)					//@2-5-3 개수 제한해주기	(현재 화면에 나온 폭탄의 개수 < 폭탄 제한 개수)
	{
		if (bomb.BombArr[(int)(target.t_y / 42)][(int)(target.t_x / 42)].BombYesNo == BOMB_NO)	//@11-1 만약 현재 위치에 폭탄이 놓여져 있지 않다면(같은 위치에 폭탄 중복해서 넣지 못하도록)
		{
			int i = (int)(target.t_y / 42);
			int j = (int)(target.t_x / 42);

			if (bomb.BombArr[i][j].Bomb_Life == false)
			{
				bomb.BombArr[i][j].Bomb_Life = true;				//@2-4 스페이스바 누를 때마다 폭탄 살아나도록. 생기도록
				bomb.BombArr[i][j].Bomb_burst = false;				//@3-1 폭탄이 안 터진 상태 - Bomb.cpp에서 이미 해줬는데, 여기에 왜 또 적었었지..? @물음표

				bomb.BombArr[i][j].BombSecond = BombSecond;			//@2-4 폭탄 타이머 시간 설정 - 5초
				bomb.BombArr[i][j].BurstSecond = 5;					//@3-1 폭탄 연기 나오는 시간 설정 - 5초

				//@11-1
				bomb.BombArr[(int)(target.t_y / 42)][(int)(target.t_x / 42)].BombYesNo = BOMB_YES;	//@11-1 폭탄을 놓는다.

				bomb.BombNumber++;	//@2-5-3 각각 값 설정하고, 숫자 늘려

				BombSound.EffectPlay(Gmanager.InstallBombSound);		//@14-2	//폭탄이 놓일 수 있다면, 소리 재생 (같은 자리에 놓을 땐, 폭탄 안 놓이니까 소리 재생 안 되겠지)
			}

		}
	}
}

void Bomb::PushBomb(int pos)	//@12-1
{
	//@12-1 VK_SHIFT와 방향키를 동시에 누르면 pos 방향으로 밀림
	/*
	고려해야 할 부분
	 - 블록 : MAP_EMPTY가 아닌 경우, 폭탄이 이동 멈춤
	 - 폭탄 : BOMB_NO가 아닌 경우, 폭탄이 이동 멈춤

	if 밀고자 하는 방향으로 폭탄이 있다면
		if(벽 끝에 닿지 않고 && 블록 없고 && 폭탄 없을 때까지) 
			미는 방향으로 폭탄 이동
	*/

	/*
	폭탄 최종 이동 위치 계산해주는 코드와

	폭탄의 멤버변수들을 모두 복사해주는 코드로 나눠서 작성
	*/
	
	int row = (int)(target.t_y / 42);	// 타겟이 위치한 좌표
	int col = (int)(target.t_x / 42);
	int pushrow = row;					// 밀려난 폭탄이 위치할 좌표
	int pushcol = col;

	int discontrol=2;


	//if (	((pos == LEFT) && (BombArr[row][col - 1].BombYesNo == BOMB_YES))
	//	||	((pos == RIGHT) && (BombArr[row][col + 1].BombYesNo == BOMB_YES))
	//	||  ((pos == UP) && (BombArr[row - 1][col].BombYesNo == BOMB_YES))
	//	|| ((pos == DOWN) && (BombArr[row + 1][col].BombYesNo == BOMB_YES)) )

	//{	BombSound.EffectPlay(Gmanager.PushBombSound);	 //@14-2 폭탄 미는 소리. 만약 밀고자 하는 방향으로 폭탄이 존재한다면

	// 미는 방향 : 왼쪽 =====================================================================
	if ((pos == LEFT)
		&& (BombArr[row][col - 1].BombYesNo == BOMB_YES)	//만약 밀고자 하는 방향으로 폭탄이 존재한다면
		&& (col > 1) 										//@마지막 - 현재 미는 위치가 1보다는 커야지. 그래야 1 위치에 있는 폭탄이 안 밀리지
		&& (block.BlockArr[row][col - 2].BlockState != MAP_BLOCK) )	//@마지막
	{
		while ((pushcol > 0)
			&& ((block.BlockArr[row][pushcol - 1].BlockState != MAP_BLOCK))
			&& (BombArr[row][pushcol - discontrol].BombYesNo == BOMB_NO))
		{
			pushcol--;	discontrol = 1;
		}
		// 조건에  (BombArr[row][pushcol - 1].BombYesNo == BOMB_NO) 을 적으면, 현재 폭단의 위치 자체를 의미하기 때문에 밀리지 않음 - discontrol이라는 거리 조정용 변수 사용

		//위 while문에서 얻은 pushrow와 pushcol을 기준으로 ======================
		BombArr[row][pushcol].Bomb_Life = true;
		BombArr[row][pushcol].BombSecond = BombArr[row][col - 1].BombSecond;
		BombArr[row][pushcol].Bomb_burst = BombArr[row][col - 1].Bomb_burst;
		BombArr[row][pushcol].BurstSecond = BombArr[row][col - 1].BurstSecond;
		BombArr[row][pushcol].BombYesNo = BOMB_YES;

		// 기존 행렬에 있던 폭탄은 없애기======================
		BombArr[row][col - 1].Bomb_Life = false;
		//		BombArr[row][col - 1].BombSecond = 0;
		BombArr[row][col - 1].Bomb_burst = false;
		//		BombArr[row][col - 1].BurstSecond = 0;
		BombArr[row][col - 1].BombYesNo = BOMB_NO;

		//	Bomb_Life, BombSecond, Bomb_burst, BurstSecond, BombYesNo
		//	m_BombLifeTime, m_BurstLifeTime, BombSecond, BurstSecond은 설정 필요 없음	
		//	어차피 폭탄이 생기기 전까지 하는 역할이 없음. 그리고 새로 생길 때, 새로 정의됨 

		BombSound.EffectPlay(Gmanager.PushBombSound);	 //@14-2 폭탄 미는 소리. 만약 밀고자 하는 방향으로 폭탄이 존재한다면
	}

	// 미는 방향 : 오른쪽 =====================================================================
	if ((pos == RIGHT)
		&& (BombArr[row][col + 1].BombYesNo == BOMB_YES)
		&& (col < 28)	//@마지막
		&& (block.BlockArr[row][col + 2].BlockState != MAP_BLOCK) )	//@마지막
	{	
		while ((pushcol < 29)
			&& ((block.BlockArr[row][pushcol + 1].BlockState != MAP_BLOCK))
			&& (BombArr[row][pushcol + discontrol].BombYesNo == BOMB_NO))
		{	pushcol++;	discontrol = 1;	}
	
		//위 while문에서 얻은 pushrow와 pushcol을 기준으로 ======================
		BombArr[row][pushcol].Bomb_Life = true;
		BombArr[row][pushcol].BombSecond = BombArr[row][col + 1].BombSecond;
		BombArr[row][pushcol].Bomb_burst = BombArr[row][col + 1].Bomb_burst;
		BombArr[row][pushcol].BurstSecond = BombArr[row][col + 1].BurstSecond;
		BombArr[row][pushcol].BombYesNo = BOMB_YES;

		// 기존 행렬에 있던 폭탄은 없애기======================
		BombArr[row][col + 1].Bomb_Life = false;
//		BombArr[row][col + 1].BombSecond = 0;
		BombArr[row][col + 1].Bomb_burst = false;
//		BombArr[row][col + 1].BurstSecond = 0;
		BombArr[row][col + 1].BombYesNo = BOMB_NO;

		BombSound.EffectPlay(Gmanager.PushBombSound);	 //@14-2 폭탄 미는 소리. 만약 밀고자 하는 방향으로 폭탄이 존재한다면
	}
	

	// 미는 방향 : 위쪽 =====================================================================
	if ((pos == UP)
		&& (BombArr[row - 1][col].BombYesNo == BOMB_YES)
		&& (block.BlockArr[row - 2][col].BlockState != MAP_BLOCK)	//@마지막 - 현재 미는 방향 폭탄 너머에 블록이 없다면, 밀 수 있도록
		&& (row >1) )								//@마지막 - 현재 위치가 1보다는 커야 밀리도록. 그래야 1위치에 있는 폭탄이 그 이상 안 밀리지.
	{
		while ((pushrow > 0)
			&& ((block.BlockArr[pushrow -1][col].BlockState != MAP_BLOCK))
			&& (BombArr[pushrow - discontrol][col].BombYesNo == BOMB_NO))
		{
			pushrow--;	discontrol = 1;
		}

		//위 while문에서 얻은 pushrow와 pushcol을 기준으로 ======================
		BombArr[pushrow][col].Bomb_Life = true;
		BombArr[pushrow][col].BombSecond = BombArr[row - 1][col].BombSecond;
		BombArr[pushrow][col].Bomb_burst = BombArr[row - 1][col].Bomb_burst;
		BombArr[pushrow][col].BurstSecond = BombArr[row -1][col].BurstSecond;
		BombArr[pushrow][col].BombYesNo = BOMB_YES;

		// 기존 행렬에 있던 폭탄은 없애기======================
		BombArr[row - 1][col].Bomb_Life = false;
		//		BombArr[row][col + 1].BombSecond = 0;
		BombArr[row - 1][col].Bomb_burst = false;
		//		BombArr[row][col + 1].BurstSecond = 0;
		BombArr[row - 1][col].BombYesNo = BOMB_NO;

		BombSound.EffectPlay(Gmanager.PushBombSound);	 //@14-2 폭탄 미는 소리. 만약 밀고자 하는 방향으로 폭탄이 존재한다면
	}


	// 미는 방향 : 아래쪽 =====================================================================
	if ((pos == DOWN)
		&& (BombArr[row + 1][col].BombYesNo == BOMB_YES)
		&& (block.BlockArr[row + 2][col].BlockState != MAP_BLOCK)		//@마지막 - 현재 미는 방향 폭탄 너머에 블록이 없다면, 밀 수 있도록
		&& (row < 16) )								//@마지막 - 현재 위치가 16보다는 작아야 밀리도록. 그래야 1위치에 있는 폭탄이 그 이상 안 밀리지.
	{
		while ((pushrow < 17)
			&& ((block.BlockArr[pushrow + 1][col].BlockState != MAP_BLOCK))
			&& (BombArr[pushrow + discontrol][col].BombYesNo == BOMB_NO))
		{
			pushrow++;	discontrol = 1;
		}

		//위 while문에서 얻은 pushrow와 pushcol을 기준으로 ======================
		BombArr[pushrow][col].Bomb_Life = true;
		BombArr[pushrow][col].BombSecond = BombArr[row + 1][col].BombSecond;
		BombArr[pushrow][col].Bomb_burst = BombArr[row + 1][col].Bomb_burst;
		BombArr[pushrow][col].BurstSecond = BombArr[row + 1][col].BurstSecond;
		BombArr[pushrow][col].BombYesNo = BOMB_YES;

		// 기존 행렬에 있던 폭탄은 없애기======================
		BombArr[row + 1][col].Bomb_Life = false;
		//		BombArr[row][col + 1].BombSecond = 0;
		BombArr[row + 1][col].Bomb_burst = false;
		//		BombArr[row][col + 1].BurstSecond = 0;
		BombArr[row + 1][col].BombYesNo = BOMB_NO;

		BombSound.EffectPlay(Gmanager.PushBombSound);	 //@14-2 폭탄 미는 소리. 만약 밀고자 하는 방향으로 폭탄이 존재한다면
	}



}