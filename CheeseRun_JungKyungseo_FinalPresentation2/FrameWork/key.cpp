#include "Include.h"

Key key;


Key::Key(void)
{

	
}

Key::~Key(void)
{
}


void Key::Update()
{
	// 시스템에 따라...GetTickCount/GetTickCount64
	if(KeyDown('1'))		//@5-1 얘가 게임 시작 버튼. 게임 시작 버튼을 변경하려면, 밑의 코드들을 모두 같이 옮겨주도록
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			//@6-1-2 맵 배열(격자) 보이도록 =========================
			if (minimap.ShowAll == TRUE) minimap.ShowAll = FALSE;
			else if (minimap.ShowAll == FALSE) minimap.ShowAll = TRUE;
			// ======================================================

			KeyTime = GetTickCount64();
		}
	}

	if(KeyDown('2'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			//map.m_Stage = 2;	//@3-4-1 주석 처리

			//@6-1-2 맵 배열(격자) 보이도록 =========================
			if (minimap.ShowItem == TRUE) minimap.ShowItem = FALSE;
			else if (minimap.ShowItem == FALSE) minimap.ShowItem = TRUE;
			// ======================================================

			KeyTime = GetTickCount64();
		}
		
	}

	if(KeyDown('3'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
		
	}
	
	if(KeyDown('4'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			
			KeyTime = GetTickCount64();
		}
		
	}

	if(KeyDown('5'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			//@6-1-2 맵 배열(격자) 보이도록 =========================
			if (block.ShowBlockArr == TRUE) block.ShowBlockArr = FALSE;
			else if (block.ShowBlockArr == FALSE) block.ShowBlockArr = TRUE;
			// ======================================================

			KeyTime = GetTickCount64();
		}
	
	}
	
	if(KeyDown('6'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			//@9-3맵 배열(격자) 보이도록 =========================
			if (trap.ShowTrapArr== TRUE) trap.ShowTrapArr = FALSE;
			else if (trap.ShowTrapArr == FALSE) trap.ShowTrapArr = TRUE;
			// ======================================================

			KeyTime = GetTickCount64();
		}
	}



	if(KeyDown('7'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			//@10-1 아이템 배열(격자) 보이도록 =========================
			if (item.ShowItemArr == TRUE)item.ShowItemArr = FALSE;
			else if (item.ShowItemArr == FALSE) item.ShowItemArr = TRUE;
			// ======================================================

			
			KeyTime = GetTickCount64();
		}
		
	}



	
	

	if(KeyDown('8'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{

		}
		
	}

	if(KeyDown('9'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
		
	}


	if(KeyDown('0'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
		
	}






	if(KeyDown(VK_F1))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F2))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F3))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F4))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F5))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F6))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F7))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
		
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F8))
	{
		if(GetTickCount64() - KeyTime > 200)
		{		
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F9))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F10))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F11))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F12))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			//@15-2 if(KeyDown('1'))에서 위치 대 이동 (Menu.cpp의 VK_f12와 동시에 이루어지도록 key.cpp의 VK_F12에 코드 작성
			map.m_Stage = 1;
			//@3-4-1 위치 이동 ===================================
			Gmanager.m_Collision = true;		//@원래 위치 : 3 눌렀을 때
			monster.Reset();					//@원래 위치 : 4 눌렀을 때	//@몬스터 원 위치로.
			//@마지막 오류 점검 
			target.Reset();		//@4-1 타겟 다시 살아나라. 원 위치로

			bomb.Reset();		//@4-1 폭탄 다 사라져라
			score.Reset();						//@5-1 치즈 생기도록
			trap.Reset();						//@9-1 트랩 초기화
			item.Reset();						//@10-1 아이템 초기화
			//@15-2 ===================================

			KeyTime = GetTickCount64();
		}
	
	}

	


	if(KeyDown(VK_SPACE) ) 
	{
		
		if(GetTickCount64() - KeyTime2 > 200)
		{
			if(Gmanager.m_GameStart==true )		//@1 게임이 시작되었다면
			{
				bomb.InstallBomb(5);			//@11-1		//매개변수 : int BombSecond(폭탄이 살아있는 시간)
				
			//@13-1 Sound 파일 관련 주석 처리	//sound.m_Shot->Play(NULL);		//@12 ~ Bomb파일에 넣어서 - 폭탄이 놓여지는 거 성공할 때만 소리가 들리도록 하기
			}
				
			KeyTime2 = GetTickCount64();
		}
		
	}


	if (KeyDown(VK_CONTROL) )		
	{
		if (GetTickCount64() - KeyTime > 200)		
		{
			block.CrushBlock();

			KeyTime = GetTickCount64();
		}
	}

	//=====================================================================================
	//@12-1 폭탄 밀기	//VK_SHIFT와 왼쪽 방향키를 동시에 누른 상태
	//=====================================================================================
	if ( KeyDown(VK_SHIFT) && KeyDown(VK_LEFT) )
	{
		if (GetTickCount64() - KeyTime4 > 200)
		{
			bomb.PushBomb(LEFT);

			KeyTime4 = GetTickCount64();
		}
	}
	
	if (KeyDown(VK_SHIFT) && KeyDown(VK_RIGHT))
	{
		if (GetTickCount64() - KeyTime4 > 200)
		{
			bomb.PushBomb(RIGHT);

			KeyTime4 = GetTickCount64();
		}
	}

	if (KeyDown(VK_SHIFT) && KeyDown(VK_UP))
	{
		if (GetTickCount64() - KeyTime4 > 200)
		{
			bomb.PushBomb(UP);

			KeyTime4 = GetTickCount64();
		}
	}
	if (KeyDown(VK_SHIFT) && KeyDown(VK_DOWN))
	{
		if (GetTickCount64() - KeyTime4 > 200)
		{
			bomb.PushBomb(DOWN);

			KeyTime4 = GetTickCount64();
		}
	}
	//=====================================================================================



	if(KeyDown(VK_LEFT))
	{
		if(GetTickCount64() - KeyTime1 > 10)		//@ 좌우 키는 KeyTime1 사용
		{
			target.pos = LEFT;						//@10-7	움직이는 방향 설정

			if(target.t_x<=0)						//@ 좌표가 왼쪽 끝에 다다르면, 더이상 못가도록
			{
				target.t_x = target.t_x;
			}
			//@6-1-2 블록이 있는 부분은 타겟(제리)이 가지 못하도록============================ 블록 배열[행 = 세로축][열 = 가로축] 헷갈리지 않기!
			else if (block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1].BlockState == MAP_BLOCK)
			{
				if (block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 2].BlockState != MAP_BLOCK)	//@8-1 미는 방향 너머에 블록이 없다면
				{
					block.PushBlock(LEFT);		//블록이 밀리는 것처럼
					
					//@9-2 ============================================================================
					if (trap.TrapArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1] == TRAP_YES)	//만약 밀고 있는 블록에 쥐덫이 들어있다면
					{
						//@9-2 트랩 배열의 위치도 변경해서. 마치 블록에 트랩이 들어있는 것처럼
						trap.PushTrap(LEFT);
					}
					// ================================================================================
					//@10-2 ============================================================================
					if (item.ItemArr1[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1].ItemState == ITEM_YES)	//만약 밀고 있는 블록에 아이템이 들어있다면
					{
						//@9-2 아이템 배열의 위치도 변경해서. 마치 블록에 트랩이 들어있는 것처럼
						item.PushItem(LEFT);
					}
					// ================================================================================
				}
				else	// 미는 방향 너머로 블록이 있다면, 타겟은 제자리 걸음
				{
					target.t_x = target.t_x;
				}
			}
			// ========================================================
			else if((Gmanager.m_GameStart==true))
			{
				target.t_x-=5;				//@1 실시간 위치 변수가 5만큼 줄고 있음 (=속도가 5)
			}


			KeyTime1 = GetTickCount64();
		}
	}

	if(KeyDown(VK_RIGHT))
	{

		if(GetTickCount64() - KeyTime1 > 10)
		{
			target.pos = RIGHT;						//@10-7 움직이는 방향 설정

			if(target.t_x>=1265)		//화면의 끝 : 1280	
			{
				target.t_x = target.t_x;
			}
			//@6-1-2 블록이 있는 부분은 타겟(제리)이 가지 못하도록============================
			else if (block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) +1].BlockState == MAP_BLOCK)
			{
				if (block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) +2].BlockState != MAP_BLOCK)	//@8-1 미는 방향 너머에 블록이 없다면
				{
					block.PushBlock(RIGHT);		//블록이 밀리는 것처럼

					//@9-2 ============================================================================
					if (trap.TrapArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) +1] == TRAP_YES)	//만약 밀고 있는 블록에 쥐덫이 들어있다면
					{
						//@9-2 트랩 배열의 위치도 변경해서. 마치 블록에 트랩이 들어있는 것처럼
						trap.PushTrap(RIGHT);
					}
					// ================================================================================
					//@10-2 ============================================================================
					if (item.ItemArr1[(int)(target.t_y / 42)][(int)(target.t_x / 42) +1].ItemState == ITEM_YES)	//만약 밀고 있는 블록에 아이템이 들어있다면
					{
						//@9-2 아이템 배열의 위치도 변경해서. 마치 블록에 트랩이 들어있는 것처럼
						item.PushItem(RIGHT);
					}
					// ================================================================================

				}
				else	// 미는 방향 너머로 블록이 있다면, 타겟은 제자리 걸음
				{
					target.t_x = target.t_x;
				}
			}
			// ========================================================
			else if(Gmanager.m_GameStart==true)
			{
				target.t_x+=5;
			}

			//@16-1 미니맵 위치========================================


			KeyTime1 = GetTickCount64();
		}
		
	}

	
	if(KeyDown(VK_UP))
	{
		if(GetTickCount64() - KeyTime3 > 10)
		{	

			if(target.t_y<=0)
			{
				target.t_y = target.t_y;
			}
			//@6-1-2 블록이 있는 부분은 타겟(제리)이 가지 못하도록============================
			else if (block.BlockArr[(int)(target.t_y  / 42) -1][(int)(target.t_x / 42)].BlockState == MAP_BLOCK)
			{
				if (block.BlockArr[(int)(target.t_y / 42) -2][(int)(target.t_x / 42)].BlockState != MAP_BLOCK)	//@8-1 미는 방향 너머에 블록이 없다면
				{
					block.PushBlock(UP);		//블록이 밀리는 것처럼

					//@9-2 ============================================================================
					if (trap.TrapArr[(int)(target.t_y / 42)-1][(int)(target.t_x / 42)] == TRAP_YES)	//만약 밀고 있는 블록에 쥐덫이 들어있다면
					{
						//@9-2 트랩 배열의 위치도 변경해서. 마치 블록에 트랩이 들어있는 것처럼
						trap.PushTrap(UP);
					}
					// ================================================================================
					//@10-2 ============================================================================
					if (item.ItemArr1[(int)(target.t_y / 42)-1][(int)(target.t_x / 42) ].ItemState == ITEM_YES)	//만약 밀고 있는 블록에 아이템이 들어있다면
					{
						//@9-2 아이템 배열의 위치도 변경해서. 마치 블록에 트랩이 들어있는 것처럼
						item.PushItem(UP);
					}
					// ================================================================================
				}
				else	// 미는 방향 너머로 블록이 있다면, 타겟은 제자리 걸음
				{
					target.t_y = target.t_y;
				}
			}
			// ========================================================
			else if(Gmanager.m_GameStart==true)
			{
				target.t_y-=5;
			}

			KeyTime3 = GetTickCount64();
		}
		
	}

	if(KeyDown(VK_DOWN))
	{

		if(GetTickCount64() - KeyTime3 > 10)
		{
			
			if(target.t_y>=750)		//화면의 끝 : 768
			{
				target.t_y = target.t_y;
			}
			//@6-1-2 블록이 있는 부분은 타겟(제리)이 가지 못하도록============================
			else if (block.BlockArr[(int)(target.t_y/42) +1][(int)(target.t_x / 42)].BlockState == MAP_BLOCK)
			{
				if (block.BlockArr[(int)(target.t_y / 42) + 2][(int)(target.t_x / 42)].BlockState != MAP_BLOCK)	//@8-1 미는 방향 너머에 블록이 없다면
				{
					block.PushBlock(DOWN);		//블록이 밀리는 것처럼

					//@9-2 ============================================================================
					if (trap.TrapArr[(int)(target.t_y / 42)+1][(int)(target.t_x / 42) ] == TRAP_YES)	//만약 밀고 있는 블록에 쥐덫이 들어있다면
					{
						//@9-2 트랩 배열의 위치도 변경해서. 마치 블록에 트랩이 들어있는 것처럼
						trap.PushTrap(DOWN);
					}
					// ================================================================================
					//@10-2 ============================================================================
					if (item.ItemArr1[(int)(target.t_y / 42)+1][(int)(target.t_x / 42) ].ItemState == ITEM_YES)	//만약 밀고 있는 블록에 아이템이 들어있다면
					{
						//@9-2 아이템 배열의 위치도 변경해서. 마치 블록에 트랩이 들어있는 것처럼
						item.PushItem(DOWN);
					}
					// ================================================================================
				}
				else	// 미는 방향 너머로 블록이 있다면, 타겟은 제자리 걸음
				{
					target.t_y = target.t_y;
				}
			}
			// ========================================================
			else if(Gmanager.m_GameStart==true)
			{
				target.t_y+=5;
			}

			KeyTime3 = GetTickCount64();
		}
		
	}


	if(KeyDown('C') )
	{
		if(GetTickCount64() - KeyTime1 > 200)
		{	
			KeyTime1 = GetTickCount64();
		}
	}




	
	if(KeyDown('N'))
	{
		
		if(GetTickCount64() - KeyTime > 200)
		{			
			KeyTime = GetTickCount64();
		}
	}

	
	if(KeyDown('A'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	}




	if(KeyDown('W') )
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			
			KeyTime = GetTickCount64();
		}

	}


	if(KeyDown('E')  )
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
		
	}


	if(KeyDown('R') )
	{
		if(GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
	}


	if(KeyDown('S') )
	{
		if(GetTickCount64() - KeyTime > 200)
		{
	
			KeyTime = GetTickCount64();
		}
	}


	if(KeyDown('D') )
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			
			KeyTime = GetTickCount64();
		}
	}


	if(KeyDown(VK_RETURN) ) 
	{
		
		if(GetTickCount64() - KeyTime1 > 200)
		{

			KeyTime1 = GetTickCount64();
		}
		
	}


}