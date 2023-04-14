#include "Include.h"

Trap trap;
//std::vector<Trap*> targetTrap;	//@9-1 ���� ����	//std::vector<Trap*> targetTrap;		
//GameManager.cpp�� ��������
//���� ������ ���� : https://senticoding.tistory.com/54 // http://printf.egloos.com/v/1824410


extern std::list<Trap*> targetTrap;	//@9-1-2				//@������ (vector->list�θ� ����)
//std::list<Trap*>::iterator iter;	//@9-1-2 �ݺ��� ����	//@������ (vector->list�θ� ����)	//@������ �ݺ��� �ƿ� ���ְ� ���� ��� for�� �̿��غ���
//@������ ���� ��� for���� �̿��ϸ�, �ݺ��� �ʿ� ����

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


	//@9-1 Ʈ�� ��ġ �־��ֱ�
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			this->TrapArr[row][col] = TRAP_NO;

			if ( (block.BlockArr[row][col].BlockState == MAP_BLOCK) && ((col != 0) && (col % 11==0))	)	//Block.cpp�� Block�迭 ��ġ�� ������� ��. ����� �ִ� �ڸ��� Ʈ���� �־�� �ϴϱ�.	//@ ������ - ��� if������ ����ϰ�
			{
				this->TrapArr[row][col] = TRAP_YES;	//��� �ִ�.
			}
		}
	}


	gyeokja.Create("./resource/Img/Map/gyeokja.png", false, D3DCOLOR_XRGB(0, 0, 0));	//���� �׷��ִ� �ڵ�	//@9-3

}

void Trap::Update()
{
	//@10-2 Ư�� �ð����� & �ӵ����� Ʈ�� �̵�
	if (GetTickCount64() - TrapMoveTime > 1050)		
	{
		//@������ ���� ����
		/*
		for (iter = targetTrap.begin(); iter != targetTrap.end(); iter++)		
		{
			if ((*iter)->pos == UP )
			{
				//Ʈ�� �迭�� TRAP_NO, TRAP_YES�� �ٲ�� 
					//- ���� Ʈ�� �ϳ��ϳ����� ����(�����̳�)�� ���ǵǾ�����. �׳� ������ x,y���� �����̴� �ɷ� ����
				//��, ����� �μ���, TRAP_NO�� �ǵ���
				(*iter)->y -= speed; 
			}

			else if ((*iter)->pos == DOWN)
			{
				(*iter)->y += speed;
			}

		}
		*/
		//���� �ڵ� ��� ���� ��� for�� �̿��غ���
		for (const auto& i : targetTrap)
		{
			if (i->pos == UP)
			{
				//Ʈ�� �迭�� TRAP_NO, TRAP_YES�� �ٲ�� 
					//- ���� Ʈ�� �ϳ��ϳ����� ����(�����̳�)�� ���ǵǾ�����. �׳� ������ x,y���� �����̴� �ɷ� ����
				//��, ����� �μ���, TRAP_NO�� �ǵ���
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

	//@10-2 �����̴� ���� ����
	//@������ ���� ����
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
	//���� �ڵ� ��� ���� ��� for�� �̿��غ���
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



	//@10-2 �����̴� ���� ����
	//�Ÿ� ������ -> Ÿ�� ���� = false -> LOSE	
	/*
	for (iter = targetTrap.begin(); iter != targetTrap.end(); iter++)		// const auto& i : targetTrap	// int i = 0; i < targetTrap.size(); i++	//�ݺ��ڸ� �̿��ؼ��� ǥ�� ����
	{
		float distance = (float)sqrt(	(((*iter)->x) - target.t_x) * (((*iter)->x) - target.t_x) +
			(((*iter)->y) - target.t_y) * (((*iter)->y) - target.t_y)		);

		if (distance < 30)	//Ÿ�ٰ� Ʈ������ �Ÿ�
		{
			target.Target_Life = false;	// Ÿ�� ���� (LOSE)
		}
	}
	*/
	//���� �ڵ� ��� ���� ��� for�� �̿��غ���
	for (const auto& i : targetTrap)		// const auto& i : targetTrap	// int i = 0; i < targetTrap.size(); i++	//�ݺ��ڸ� �̿��ؼ��� ǥ�� ����
	{
		float distance = (float)sqrt(((i->x) - target.t_x) * ((i->x) - target.t_x) +
			((i->y) - target.t_y) * ((i->y) - target.t_y));

		if (distance < 30)	//Ÿ�ٰ� Ʈ������ �Ÿ�
		{
			target.Target_Life = false;	// Ÿ�� ���� (LOSE)
		}
	}
	////////////////////////////////////////////////////////


	if (GetTickCount64() - TrapCountTime > 150)		//@10-2 Ʈ�� �̹��� ���������� ���̰�
	{
		Trap_count++;
		if (Trap_count > 6)  Trap_count = 0;
		TrapCountTime = GetTickCount64();
	}

}

void Trap::Draw()
{	
	
	//9-1-1 �׽�Ʈ�� - ��� ������ŭ(���͸�.size()) for�� ������ Ʈ�� �׸�����
	//���� : Ʈ�� ������� �ް��� ������ - Block.cpp���� MAP_TRAP�� ��� ��ġ�� ���ؼ� ���Ͱ� ��� ��������� �׷�.
	//@������ ���� ����
	
	/*
	for (iter = targetTrap.begin(); iter != targetTrap.end(); iter++)		// const auto& i : targetTrap	// int i = 0; i < targetTrap.size(); i++	//�ݺ��ڸ� �̿��ؼ��� ǥ�� ����
	{
		Trapimg[Trap_count].Render((*iter)->x -15, (*iter)->y +30, 0, 0.3, 0.3);
	}
	*/
	//���� �ڵ� ��� ���� ��� for�� �̿��غ���
	for (const auto& i : targetTrap)		// const auto& i : targetTrap	// int i = 0; i < targetTrap.size(); i++	//�ݺ��ڸ� �̿��ؼ��� ǥ�� ����
	{
		Trapimg[Trap_count].Render(i->x - 15, i->y + 30, 0, 0.3, 0.3);
	}
	///////////////////////////////////////////////////////
}

void Trap::Reset()
{
	targetTrap.clear();			//�� �� ��� �ʱ�ȭ! - key.cpp���� 1�� ���� �� & Over.cpp���� F11 ���� ��
}

void Trap::PushTrap(int pos)	//@14-1 ���� �Լ��� ������	//@9-2 Ʈ�� �迭�� ��ġ�� �����ؼ�. ��ġ ��Ͽ� Ʈ���� ����ִ� ��ó��
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