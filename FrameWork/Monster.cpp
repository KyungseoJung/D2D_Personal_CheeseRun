#include "Include.h"


Monster monster;							//@1 클래스 객체 만들고

extern FmodSound MonsterSound;


Monster::Monster(void)
{
	//LifeTime = GetTickCount64();
	MonsterCountTime = GetTickCount64();
	MonsterMoveTime = GetTickCount64();
	FollowTime = GetTickCount64();
}

Monster::~Monster(void)
{
}

void Monster::Init()					//@1 시작할 때, 각 이미지가 애니메이션처럼 움직이듯이 보여줌.
{

	char FileName[256];

	for (int i = 0; i < 6; i++)
	{
		sprintf_s(FileName, "./resource/Img/Monster/Cat/output_Cat/Cat_002_00%02d.png", i);				
		catimg1[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	//@3-3 고양이 자는 이미지 한 개만
	//@3-5-1-1
	sprintf_s(FileName, "./resource/Img/Monster/Cat/output_Sleep/Sleep_0001.png");
	Sleepimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//@10-5 FollowZone 이미지 
	sprintf_s(FileName, "./resource/Img/Monster/FollowZone.png");
	FollowZone.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	

}

//@1 몬스터 만드는 함수(시작위치, 점수, 스피드 등을 이 함수를 통해 지정해줌)
//@1 m_x : 물고기의 실시간 위치,
//@3-5-1 기절 안 하는 문제 해결 : 같은 물고기 종류라면, fishkind는 같은 변수 써도 돼(A_, B_) 단, num은 다르게 해야 돼
void Monster::GoodFunction(double m_x, double m_y, double speed, int pos, double w, int num)
{
	cat[num].m_x = m_x;
	cat[num].m_y = m_y;

	cat[num].speed = speed;
	cat[num].scale = 0.6;		//크기 지정
	cat[num].life = false;	
	cat[num].pos = pos;
	cat[num].w = w;				//@3-5-2 필요할 수도 있겠다!! 실제위치와 눈에 보이는 위치 거리 조정용

	cat[num].m_SleepSecond = 5;	//@4-1 5초 기절한 상태로 시작
}


void Monster::Update()
{


	if (Gmanager.m_GameStart == true)
	{
		//@3-3-2 시간 지나면 자동으로 살아나게 하면 안 됨. 일정 기절 시간이 지났을 때, 살아나야 함.
		//if (GetTickCount64() - LifeTime > 100)	//@1 특정 시간별로 물고기(몬스터)를 랜덤으로 살림
		//{
		//	for (m_FishLifeSelect = 0; m_FishLifeSelect < 3; m_FishLifeSelect++)		//@2-2 고양이 추가 (<2)였던 부분을 (<3)으로 변경.
		//	{
		//		if (catkind[m_FishLifeSelect].life == false)
		//		{
		//			catkind[m_FishLifeSelect].life = true;

		//		}

		//	}
		//	m_FishLifeSelect = 0;
		//	LifeTime = GetTickCount64();
		//}


		//@1 특정 시간별로 & 속도별로 몬스터 이동
		if (GetTickCount64() - MonsterMoveTime > 20)			//@1 왼쪽/오른쪽으로 가면 m_x에서 dx를 뺌/더함으로써 -> 물고기 움직이는 속도 조절하는 for문
		{
			for (int i = 0; i < MonsterCount; i++)							//@2-2 고양이 추가 (i<2)였던 부분을 (i<3)으로 변경.	//@3-5-1
			{
				if (cat[i].pos == LEFT && cat[i].life == true)		// 오른쪽에서 왼쪽으로 가면!  x를 - 시켜야지		//@1 물고기가 살아있다면 움직이도록~ //@3-2 만약 Boom함수에서 life = false로 바뀌면 실행 안 되겠지
				{
					cat[i].m_x -= cat[i].speed; /* cat[i].dx -= cat[i].speed; */	//@10-5 주석 처리
				}		//@1 물고기의 위치도 이동하고, 데미지존도 이동하고~

				else if (cat[i].pos == RIGHT && cat[i].life == true)
				{
					cat[i].m_x += cat[i].speed;  /* cat[i].dx += cat[i].speed; */	//@10-5 주석 처리
				}

			}

			MonsterMoveTime = GetTickCount64();
		}


		// 움직이는 방향 전환
		for (int i = 0; i < MonsterCount; i++)	
		{
			if (cat[i].life == true)
			{
				if (cat[i].pos == LEFT 
					&& ((cat[i].m_x < 50)	//@3-5-1 화면의 왼쪽 끝에 닿으면
					|| block.BlockArr[(int)(cat[i].m_y / 42)][(int)(cat[i].m_x / 42) - 1].BlockState == MAP_BLOCK	//가는 방향에 블록이 있다면
					/* || bomb.BombArr[(int)(cat[i].m_y / 42)][(int)(cat[i].m_x / 42) - 1].BombYesNo == BOMB_YES*/	))	//가는 방향에 폭탄이 있다면	
				{
					cat[i].pos = RIGHT;	//@3-5-3 왔다갔다 하도록
				}
				else if (cat[i].pos == RIGHT 
					&& ((cat[i].m_x > 1150)	//@3-5-1  화면의 오른쪽 끝에 닿으면. 화면에선 아예 사라지지 않도록 1280 - 100
					|| block.BlockArr[(int)(cat[i].m_y / 42)][(int)(cat[i].m_x / 42) +1].BlockState == MAP_BLOCK	//가는 방향에 블록이 있다면
					/* || bomb.BombArr[(int)(cat[i].m_y / 42)][(int)(cat[i].m_x / 42) + 1].BombYesNo == BOMB_YES*/	))	//가는 방향에 폭탄이 있다면
				{
					cat[i].pos = LEFT;	//@3-5-3 왔다갔다 하도록
				}
			}
		}

		if (GetTickCount64() - MonsterCountTime > 50)		//@1 Draw에서 사용되는 변수~물고기 애니메이션처럼 보이게	//@1 속도 조절 여기서 가능한 게 아닌 듯
		{
			m_Acount++;

			m_Bulletcount++;

			if (m_Acount > 5)  m_Acount = 0;


			if (m_Bulletcount > 20) m_Bulletcount = 0;
			MonsterCountTime = GetTickCount64();
		}


		Boom();



		//@3-3-3 기절 시간이 풀리면 .life = true 되도록===============================
		for (int i = 0; i < MonsterCount; i++)		//@3-5-1
		{
			if (cat[i].life == false)	//&& Gmanager.m_GameStart == true 생략
			{
				if ((cat[i].m_SleepSecond > 0) && (GetTickCount64() - cat[i].m_SleepLifeTime > 1000))	//@ (실시간) 기절시간 아직 남았다면
				{
					cat[i].m_SleepSecond--;							//@ (실시간) 기절 시간 줄여
					cat[i].m_SleepLifeTime = GetTickCount64();
				}

				if (cat[i].m_SleepSecond <= 0)	//@ (실시간) 기절시간 종료되면
				{
					cat[i].life = true;		//@ 기절했던 거 다시 살아나도록!
				}
			}
		}


		//@10-4 <사각형 충돌 처리>	// 몬스터가 잠들어있지 않다면 타겟과 거리가 가까워지면, 직선운동 하던 거 경로 이탈해서 타겟을 따라가도록
		for (int i = 0; i < MonsterCount; i++)		
		{
			if (cat[i].life == true)
			{

				// 몬스터의 FollowRegion 안에 들어가면
				//사각형 거리 계산	(상하좌우 3칸씩 3 * 42(크기) )
				if ( sqrt((target.t_x - cat[i].m_x) * (target.t_x - cat[i].m_x)) < 126 
					&& sqrt((target.t_y - cat[i].m_y) * (target.t_y - cat[i].m_y)) < 126 )
				{
					Follow(i); //타겟(제리) 따라감
				}
			}
		}


	}
}

/*

	기본 충돌처리

	= 사각형 출동 판정 처리
	플레이어기의 충돌 판정 좌표를 (ML, MT) ~ (MR, MB), 탄의 충돌 판정 좌표를 (BL, BT) ~ (BR, BB)라고 해보자.
	(ML, MT), (BL, BT)는 각각의 사각형의 왼쪽 위 좌표이고 (MR. MB), (BR, BB)는 사각형의 오른쪽 아래 좌표이다.
	이 경우, 플레이어기에 탄의 충돌 조건은 다음과 같다.
	* ML < BR && BL < MR && MT < BB && BT < MB		//@1 만약 이 식이 성립하면~ 충돌 맞다고 판단

	= 원을 이용한 충돌 판정 처리
	원을 이용한 충돌 판정 처리는 다음과 같다.
	플레이어기의 중심좌표를 (MX, MY), 탄의 중심좌표를 (BX, BY)라고 하고, 플레이어기의 충돌 판정 반경을 MR,
	탄의 충돌 판정 반경을 BR이라고 하자. 이때 플레이어기와 탄의 충돌 조건은 아래와 같다.
	* (MX-BX)*(MX-BX) + (MY-BY)*(MY-BY) < (MR+BR)*(MR+BR)		//@1 만약 이 식이 성립하면~ 충돌 맞다고 판단

*/

//@1 계속계속 그리는 함수
void Monster::Draw()
{


	for (int i = 0; i < MonsterCount; i++)		//@3-5-1
	{
		if ((Gmanager.m_GameStart == true) && (cat[i].life == false))				//@1 게임 시작 상태일 때 && 제대로 총 맞았으면
		{
			Sleepimg.Render(cat[i].m_x, cat[i].m_y, 0, 0.3, 0.3);		//@3-3 자는 고양이 그림 	
		}
	}

	//@10-5 Follow Region 그림 그리기	//상하좌우 3칸씩 (3칸 * 42크기)
	for (int i = 0; i < MonsterCount; i++)	
	{
		if ((Gmanager.m_GameStart == true))				
		{
			FollowZone.Render(cat[i].m_x-80, cat[i].m_y - 80, 0, 0.4, 0.4);			//@마지막 - 팔로우 존 조금 더 작게 만들기. 중심도 이동 //이전 : -126에 0.5 크기였음	
		}
	}

	if (Gmanager.m_GameStart == true)
	{
		for (int i = 0; i < MonsterCount; i++)			//@2-2 고양이 추가 (i<2)였던 부분을 (i<3)으로 변경.	//@3-5-1 (i<4)로 변경
		{
			if (cat[i].life == true)		//@1 물고기 살아있을 때
			{
				if (cat[i].pos == LEFT)	//@1 물고기(몬스터)가 왼쪽으로 가는 애라면, 여기에 그림을 그려준다
				{
					//@1 m_Account(계속 변하는)에 따라 그림을 계속 그려 - 애니메이션처럼
					catimg1[m_Acount].Render(cat[i].m_x, cat[i].m_y, 0, cat[i].scale, cat[i].scale);						
				}
				if (cat[i].pos == RIGHT)	//@1 물고기(몬스터)가 오른쪽으로 가는 애라면, 여기에 그림을 그려준다.
				{
					 catimg1[m_Acount].Render(cat[i].m_x + cat[i].w, cat[i].m_y, 0, -cat[i].scale, cat[i].scale);

				}
			}

		}
	}

}


//@3-5-2 원을 이용한 충돌처리? (피타고라스 공식을 이용 - 대각선 거리를 구한 거니까)
void Monster::Boom()	//@ 총 쏜 거 잘 맞았는지 확인~ 후 변수들 조정(생명 false, 샷 true, 폭발효과 true)
{
	for (int i = 0; i < MonsterCount; i++)		//@3-3-3 i번째 몬스터//@2-2 고양이 추가 (i<2)였던 부분을 (i<3)으로 변경.	//@3-5-1 (i<4)로 변경
	{
		for (int row = 0; row < 18; row++)	//@3-3-3 row번째 폭탄
		{
			for (int col = 0; col < 30; col++)
			{
				//@3-2 연기 맞은 몬스터 -> m_Boom = true 작동
				if (cat[i].life == true && bomb.BombArr[row][col].Bomb_burst == true)	//@3-3 몬스터가 살아있는 상태 && 연기 나오는 상태
				{
					float distance = (float)sqrt((col * 42 - cat[i].m_x) * (col * 42 - cat[i].m_x) +
						(row * 42 - cat[i].m_y) * (row * 42 - cat[i].m_y));

					if (distance < 100)		//@3-2 충돌처리 거리 조정
					{
						cat[i].life = false;	//@3-2 몬스터 기절 - 움직임 멈춤.

						cat[i].m_SleepSecond = 5;	//@3-3-3 5초동안 기절
					}
				}

			}
		}
	}

}


//좌표가 어찌 되든, 몬스터의 위치(X,Y 에서) (타겟의 X - 몬스터의 X) 만큼 이동하면 타겟에 도달한다는 수학적 성질 이용
void Monster::Follow(int num)	//거리 가까워지면 num번째 몬스터가 타겟을 따라감
{
	if (GetTickCount64() - FollowTime > 200)
	{
		cat[num].m_x += (target.t_x - cat[num].m_x) / 10;	//10차례에 나눠서 가까워지도록 나누기 10
		cat[num].m_y += (target.t_y - cat[num].m_y) / 10;

		MonsterSound.EffectPlay(Gmanager.MonsterFollowSound);

		FollowTime = GetTickCount64();
	}

}


void Monster::Reset()
{
	/* m_x | double m_y | double x | double y |  double speed |
	int pos | double w | int catkind | int num		*/
	GoodFunction(800, 150, 3, LEFT, 100.0f, 0);	//@2-1 스케일 3에서 0.8로 변경. 속도도 변경(10->5)	//@3-3 속도 3으로 변경. m_x, x도 변경 //@3-3-3 속도 2로 변경, m_x, x도 변경
	GoodFunction(0, 350, 3, RIGHT, 100.0f, 1);	//@2-1 3에서 0.8로 스케일 변경. 원래 GoodFunction 함수에서 0.8로 하고 있었으니까~
	GoodFunction(300, 400, 3, RIGHT, 100.0f, 2);	//@2-2 왔다갔다 고양이에 대한 객체 만들기	//@3-3 속도 3으로 변경. m_x, x도 변경
	GoodFunction(1000, 600, 3, LEFT, 100.0f, 3);		//@3-5-1 새로운 몬스터 추가해줌	- D_부분이랑, 그 뒤에 num에 해당하는 부분

	MonsterCount = 4;		//@3-5-3 몬스터 수 설정(이걸로 for문 돌릴 거임)
}