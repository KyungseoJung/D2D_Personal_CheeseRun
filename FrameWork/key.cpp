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
	// �ý��ۿ� ����...GetTickCount/GetTickCount64
	if(KeyDown('1'))		//@5-1 �갡 ���� ���� ��ư. ���� ���� ��ư�� �����Ϸ���, ���� �ڵ���� ��� ���� �Ű��ֵ���
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			//@6-1-2 �� �迭(����) ���̵��� =========================
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
			//map.m_Stage = 2;	//@3-4-1 �ּ� ó��

			//@6-1-2 �� �迭(����) ���̵��� =========================
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
			//@6-1-2 �� �迭(����) ���̵��� =========================
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
			//@9-3�� �迭(����) ���̵��� =========================
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
			//@10-1 ������ �迭(����) ���̵��� =========================
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
			//@15-2 if(KeyDown('1'))���� ��ġ �� �̵� (Menu.cpp�� VK_f12�� ���ÿ� �̷�������� key.cpp�� VK_F12�� �ڵ� �ۼ�
			map.m_Stage = 1;
			//@3-4-1 ��ġ �̵� ===================================
			Gmanager.m_Collision = true;		//@���� ��ġ : 3 ������ ��
			monster.Reset();					//@���� ��ġ : 4 ������ ��	//@���� �� ��ġ��.
			//@������ ���� ���� 
			target.Reset();		//@4-1 Ÿ�� �ٽ� ��Ƴ���. �� ��ġ��

			bomb.Reset();		//@4-1 ��ź �� �������
			score.Reset();						//@5-1 ġ�� ���⵵��
			trap.Reset();						//@9-1 Ʈ�� �ʱ�ȭ
			item.Reset();						//@10-1 ������ �ʱ�ȭ
			//@15-2 ===================================

			KeyTime = GetTickCount64();
		}
	
	}

	


	if(KeyDown(VK_SPACE) ) 
	{
		
		if(GetTickCount64() - KeyTime2 > 200)
		{
			if(Gmanager.m_GameStart==true )		//@1 ������ ���۵Ǿ��ٸ�
			{
				bomb.InstallBomb(5);			//@11-1		//�Ű����� : int BombSecond(��ź�� ����ִ� �ð�)
				
			//@13-1 Sound ���� ���� �ּ� ó��	//sound.m_Shot->Play(NULL);		//@12 ~ Bomb���Ͽ� �־ - ��ź�� �������� �� ������ ���� �Ҹ��� �鸮���� �ϱ�
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
	//@12-1 ��ź �б�	//VK_SHIFT�� ���� ����Ű�� ���ÿ� ���� ����
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
		if(GetTickCount64() - KeyTime1 > 10)		//@ �¿� Ű�� KeyTime1 ���
		{
			target.pos = LEFT;						//@10-7	�����̴� ���� ����

			if(target.t_x<=0)						//@ ��ǥ�� ���� ���� �ٴٸ���, ���̻� ��������
			{
				target.t_x = target.t_x;
			}
			//@6-1-2 ����� �ִ� �κ��� Ÿ��(����)�� ���� ���ϵ���============================ ��� �迭[�� = ������][�� = ������] �򰥸��� �ʱ�!
			else if (block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1].BlockState == MAP_BLOCK)
			{
				if (block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 2].BlockState != MAP_BLOCK)	//@8-1 �̴� ���� �ʸӿ� ����� ���ٸ�
				{
					block.PushBlock(LEFT);		//����� �и��� ��ó��
					
					//@9-2 ============================================================================
					if (trap.TrapArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1] == TRAP_YES)	//���� �а� �ִ� ��Ͽ� �㵣�� ����ִٸ�
					{
						//@9-2 Ʈ�� �迭�� ��ġ�� �����ؼ�. ��ġ ��Ͽ� Ʈ���� ����ִ� ��ó��
						trap.PushTrap(LEFT);
					}
					// ================================================================================
					//@10-2 ============================================================================
					if (item.ItemArr1[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1].ItemState == ITEM_YES)	//���� �а� �ִ� ��Ͽ� �������� ����ִٸ�
					{
						//@9-2 ������ �迭�� ��ġ�� �����ؼ�. ��ġ ��Ͽ� Ʈ���� ����ִ� ��ó��
						item.PushItem(LEFT);
					}
					// ================================================================================
				}
				else	// �̴� ���� �ʸӷ� ����� �ִٸ�, Ÿ���� ���ڸ� ����
				{
					target.t_x = target.t_x;
				}
			}
			// ========================================================
			else if((Gmanager.m_GameStart==true))
			{
				target.t_x-=5;				//@1 �ǽð� ��ġ ������ 5��ŭ �ٰ� ���� (=�ӵ��� 5)
			}


			KeyTime1 = GetTickCount64();
		}
	}

	if(KeyDown(VK_RIGHT))
	{

		if(GetTickCount64() - KeyTime1 > 10)
		{
			target.pos = RIGHT;						//@10-7 �����̴� ���� ����

			if(target.t_x>=1265)		//ȭ���� �� : 1280	
			{
				target.t_x = target.t_x;
			}
			//@6-1-2 ����� �ִ� �κ��� Ÿ��(����)�� ���� ���ϵ���============================
			else if (block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) +1].BlockState == MAP_BLOCK)
			{
				if (block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) +2].BlockState != MAP_BLOCK)	//@8-1 �̴� ���� �ʸӿ� ����� ���ٸ�
				{
					block.PushBlock(RIGHT);		//����� �и��� ��ó��

					//@9-2 ============================================================================
					if (trap.TrapArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) +1] == TRAP_YES)	//���� �а� �ִ� ��Ͽ� �㵣�� ����ִٸ�
					{
						//@9-2 Ʈ�� �迭�� ��ġ�� �����ؼ�. ��ġ ��Ͽ� Ʈ���� ����ִ� ��ó��
						trap.PushTrap(RIGHT);
					}
					// ================================================================================
					//@10-2 ============================================================================
					if (item.ItemArr1[(int)(target.t_y / 42)][(int)(target.t_x / 42) +1].ItemState == ITEM_YES)	//���� �а� �ִ� ��Ͽ� �������� ����ִٸ�
					{
						//@9-2 ������ �迭�� ��ġ�� �����ؼ�. ��ġ ��Ͽ� Ʈ���� ����ִ� ��ó��
						item.PushItem(RIGHT);
					}
					// ================================================================================

				}
				else	// �̴� ���� �ʸӷ� ����� �ִٸ�, Ÿ���� ���ڸ� ����
				{
					target.t_x = target.t_x;
				}
			}
			// ========================================================
			else if(Gmanager.m_GameStart==true)
			{
				target.t_x+=5;
			}

			//@16-1 �̴ϸ� ��ġ========================================


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
			//@6-1-2 ����� �ִ� �κ��� Ÿ��(����)�� ���� ���ϵ���============================
			else if (block.BlockArr[(int)(target.t_y  / 42) -1][(int)(target.t_x / 42)].BlockState == MAP_BLOCK)
			{
				if (block.BlockArr[(int)(target.t_y / 42) -2][(int)(target.t_x / 42)].BlockState != MAP_BLOCK)	//@8-1 �̴� ���� �ʸӿ� ����� ���ٸ�
				{
					block.PushBlock(UP);		//����� �и��� ��ó��

					//@9-2 ============================================================================
					if (trap.TrapArr[(int)(target.t_y / 42)-1][(int)(target.t_x / 42)] == TRAP_YES)	//���� �а� �ִ� ��Ͽ� �㵣�� ����ִٸ�
					{
						//@9-2 Ʈ�� �迭�� ��ġ�� �����ؼ�. ��ġ ��Ͽ� Ʈ���� ����ִ� ��ó��
						trap.PushTrap(UP);
					}
					// ================================================================================
					//@10-2 ============================================================================
					if (item.ItemArr1[(int)(target.t_y / 42)-1][(int)(target.t_x / 42) ].ItemState == ITEM_YES)	//���� �а� �ִ� ��Ͽ� �������� ����ִٸ�
					{
						//@9-2 ������ �迭�� ��ġ�� �����ؼ�. ��ġ ��Ͽ� Ʈ���� ����ִ� ��ó��
						item.PushItem(UP);
					}
					// ================================================================================
				}
				else	// �̴� ���� �ʸӷ� ����� �ִٸ�, Ÿ���� ���ڸ� ����
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
			
			if(target.t_y>=750)		//ȭ���� �� : 768
			{
				target.t_y = target.t_y;
			}
			//@6-1-2 ����� �ִ� �κ��� Ÿ��(����)�� ���� ���ϵ���============================
			else if (block.BlockArr[(int)(target.t_y/42) +1][(int)(target.t_x / 42)].BlockState == MAP_BLOCK)
			{
				if (block.BlockArr[(int)(target.t_y / 42) + 2][(int)(target.t_x / 42)].BlockState != MAP_BLOCK)	//@8-1 �̴� ���� �ʸӿ� ����� ���ٸ�
				{
					block.PushBlock(DOWN);		//����� �и��� ��ó��

					//@9-2 ============================================================================
					if (trap.TrapArr[(int)(target.t_y / 42)+1][(int)(target.t_x / 42) ] == TRAP_YES)	//���� �а� �ִ� ��Ͽ� �㵣�� ����ִٸ�
					{
						//@9-2 Ʈ�� �迭�� ��ġ�� �����ؼ�. ��ġ ��Ͽ� Ʈ���� ����ִ� ��ó��
						trap.PushTrap(DOWN);
					}
					// ================================================================================
					//@10-2 ============================================================================
					if (item.ItemArr1[(int)(target.t_y / 42)+1][(int)(target.t_x / 42) ].ItemState == ITEM_YES)	//���� �а� �ִ� ��Ͽ� �������� ����ִٸ�
					{
						//@9-2 ������ �迭�� ��ġ�� �����ؼ�. ��ġ ��Ͽ� Ʈ���� ����ִ� ��ó��
						item.PushItem(DOWN);
					}
					// ================================================================================
				}
				else	// �̴� ���� �ʸӷ� ����� �ִٸ�, Ÿ���� ���ڸ� ����
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