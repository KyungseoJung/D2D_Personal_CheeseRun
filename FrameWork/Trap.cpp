#include "Include.h"

Trap trap;
//std::vector<Trap*> targetTrap;	//@9-1 벡터 선언	//std::vector<Trap*> targetTrap;		
//GameManager.cpp에 선언하자
//벡터 포인터 참조 : https://senticoding.tistory.com/54 // http://printf.egloos.com/v/1824410


extern std::list<Trap*> targetTrap;	//@9-1-2				//@마지막 (vector->list로만 변경)
//std::list<Trap*>::iterator iter;	//@9-1-2 반복자 선언	//@마지막 (vector->list로만 변경)	//@마지막 반복자 아예 없애고 범위 기반 for문 이용해보기
//@마지막 범위 기반 for문을 이용하면, 반복자 필요 없음

Trap::Trap()
{
	TrapCountTime = GetTickCount64();
	TrapMoveTime = GetTickCount64();
}

Trap::~Trap()
{

}

Trap::Trap(int x, int y)	//@9-1-2
{
	this->x = x;
	this->y = y;
}

void Trap::Init()
{
	char FileName[256];

	for (int i = 0; i < 7; i++)
	{
		sprintf_s(FileName, "./resource/Img/Trap/output_LandTrap_bg/LandTrap_bg-%03d.png", i+1);
		Trapimg[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}


	//@9-1 트랩 위치 넣어주기
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			this->TrapArr[row][col] = TRAP_NO;

			if ( (block.BlockArr[row][col].BlockState == MAP_BLOCK) && ((col != 0) && (col % 11==0))	)	//Block.cpp에 Block배열 위치와 맞춰줘야 함. 블록이 있는 자리에 트랩이 있어야 하니까.	//@ 마지막 - 블록 if문으로 깔끔하게
			{
				this->TrapArr[row][col] = TRAP_YES;	//블록 있다.
			}
		}
	}


	gyeokja.Create("./resource/Img/Map/gyeokja.png", false, D3DCOLOR_XRGB(0, 0, 0));	//격자 그려주는 코드	//@9-3

}

void Trap::Update()
{
	//@10-2 특정 시간별로 & 속도별로 트랩 이동
	if (GetTickCount64() - TrapMoveTime > 1050)		
	{
		//@마지막 오류 점검
		/*
		for (iter = targetTrap.begin(); iter != targetTrap.end(); iter++)		
		{
			if ((*iter)->pos == UP )
			{
				//트랩 배열의 TRAP_NO, TRAP_YES도 바뀌도록 
					//- 지금 트랩 하나하나들은 벡터(컨테이너)로 정의되어있음. 그냥 벡터의 x,y값이 움직이는 걸로 하자
				//단, 블록을 부수면, TRAP_NO가 되도록
				(*iter)->y -= speed; 
			}

			else if ((*iter)->pos == DOWN)
			{
				(*iter)->y += speed;
			}

		}
		*/
		//위에 코드 대신 범위 기반 for문 이용해보기
		for (const auto& i : targetTrap)
		{
			if (i->pos == UP)
			{
				//트랩 배열의 TRAP_NO, TRAP_YES도 바뀌도록 
					//- 지금 트랩 하나하나들은 벡터(컨테이너)로 정의되어있음. 그냥 벡터의 x,y값이 움직이는 걸로 하자
				//단, 블록을 부수면, TRAP_NO가 되도록
				i->y -= speed;
			}

			else if (i->pos == DOWN)
			{
				i->y += speed;
			}
		}
		////////////////////////////////////////////////////////



		TrapMoveTime = GetTickCount64();
	}		

	//@10-2 움직이는 방향 변경
	//@마지막 오류 점검
	/*
	for (iter = targetTrap.begin(); iter != targetTrap.end(); iter++)
	{
		if ((*iter)->y < 50)
		{
			(*iter)->pos = DOWN;
		}

		else if ((*iter)->y > 650)
		{
			(*iter)->pos = UP;
		}

	}
	*/
	//위에 코드 대신 범위 기반 for문 이용해보기
	for (const auto& i : targetTrap)
	{
		if (i->y < 50)
		{
			i->pos = DOWN;
		}

		else if (i->y > 650)
		{
			i->pos = UP;
		}
	}
	////////////////////////////////////////////////////////



	//@10-2 움직이는 방향 변경
	//거리 가까우면 -> 타겟 생명 = false -> LOSE	
	/*
	for (iter = targetTrap.begin(); iter != targetTrap.end(); iter++)		// const auto& i : targetTrap	// int i = 0; i < targetTrap.size(); i++	//반복자를 이용해서도 표현 가능
	{
		float distance = (float)sqrt(	(((*iter)->x) - target.t_x) * (((*iter)->x) - target.t_x) +
			(((*iter)->y) - target.t_y) * (((*iter)->y) - target.t_y)		);

		if (distance < 30)	//타겟과 트랩간의 거리
		{
			target.Target_Life = false;	// 타겟 죽음 (LOSE)
		}
	}
	*/
	//위에 코드 대신 범위 기반 for문 이용해보기
	for (const auto& i : targetTrap)		// const auto& i : targetTrap	// int i = 0; i < targetTrap.size(); i++	//반복자를 이용해서도 표현 가능
	{
		float distance = (float)sqrt(((i->x) - target.t_x) * ((i->x) - target.t_x) +
			((i->y) - target.t_y) * ((i->y) - target.t_y));

		if (distance < 30)	//타겟과 트랩간의 거리
		{
			target.Target_Life = false;	// 타겟 죽음 (LOSE)
		}
	}
	////////////////////////////////////////////////////////


	if (GetTickCount64() - TrapCountTime > 150)		//@10-2 트랩 이미지 연속적으로 보이게
	{
		Trap_count++;
		if (Trap_count > 6)  Trap_count = 0;
		TrapCountTime = GetTickCount64();
	}

}

void Trap::Draw()
{	
	
	//9-1-1 테스트용 - 블록 개수만큼(벡터명.size()) for문 돌려서 트랩 그리도록
	//문제 : 트랩 생길수록 급격히 느려짐 - Block.cpp에서 MAP_TRAP인 블록 위치에 대해서 벡터가 계속 만들어져서 그럼.
	//@마지막 오류 점검
	
	/*
	for (iter = targetTrap.begin(); iter != targetTrap.end(); iter++)		// const auto& i : targetTrap	// int i = 0; i < targetTrap.size(); i++	//반복자를 이용해서도 표현 가능
	{
		Trapimg[Trap_count].Render((*iter)->x -15, (*iter)->y +30, 0, 0.3, 0.3);
	}
	*/
	//위에 코드 대신 범위 기반 for문 이용해보기
	for (const auto& i : targetTrap)		// const auto& i : targetTrap	// int i = 0; i < targetTrap.size(); i++	//반복자를 이용해서도 표현 가능
	{
		Trapimg[Trap_count].Render(i->x - 15, i->y + 30, 0, 0.3, 0.3);
	}
	///////////////////////////////////////////////////////
}

void Trap::Reset()
{
	targetTrap.clear();			//쥐 덫 모두 초기화! - key.cpp에서 1번 누를 때 & Over.cpp에서 F11 누를 때
}

void Trap::PushTrap(int pos)	//@14-1 따로 함수로 정리만	//@9-2 트랩 배열의 위치도 변경해서. 마치 블록에 트랩이 들어있는 것처럼
{
	if (pos == LEFT)
	{
		trap.TrapArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1] = TRAP_NO;
		trap.TrapArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 2] = TRAP_YES;
	}
	if (pos == RIGHT)
	{
		trap.TrapArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 1] = TRAP_NO;
		trap.TrapArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 2] = TRAP_YES;
	}
	if (pos == UP)
	{
		trap.TrapArr[(int)(target.t_y / 42) - 1][(int)(target.t_x / 42)] = TRAP_NO;
		trap.TrapArr[(int)(target.t_y / 42) - 2][(int)(target.t_x / 42)] = TRAP_YES;
	}
	if (pos == DOWN)
	{
		trap.TrapArr[(int)(target.t_y / 42) + 1][(int)(target.t_x / 42)] = TRAP_NO;
		trap.TrapArr[(int)(target.t_y / 42) + 2][(int)(target.t_x / 42)] = TRAP_YES;
	}
}